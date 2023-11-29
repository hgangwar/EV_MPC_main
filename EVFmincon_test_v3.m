function [U_f,U_r] = EVFmincon_test_v3(SOC, v_curr, Ts,N,current_timestep)
%% Extrinsic function used by Nonlinear MPC Block
    % Initializing U vector
    % Using motor speed as decision variable
    u0 = repmat([0.5;500;500],1,N);
    LB = repmat([0;0;0],1,N);
    UB = repmat([1;1675;1675],1,N);

    %% Vehicle constants
   
    veh.M = 1623;           %Vehicle Mass 
    veh.R_whl = 0.327;      %Wheel effective radius
    veh.Crr = 0.012;        %Coefficient of friction
    veh.Cd = 0.389;         %Air drag coeficient
    veh.rho = 1.202;        %Air density
    veh.A = 2.27;           %Surface area car
    veh.f_ratio = 3.32;     %final gear ratio

    %% Velocity Reference Vector
    Data=load("ftp75_5ms.mat");
    v_ref=Data.ftp75_5ms(current_timestep:current_timestep+N,1);

    %% Loading effeciency map
    data = load("eff_map.mat");
    info.eff = data.eff;
    info.torque = data.torque;
    info.speed = data.speed;
    
    %% Torque limit data
    data = load("Max_Torque_vs_EMSpeed.mat");
    info.torque_limit=data.TorqueVsSpeed;

    COST = @(u) EVObjectiveFCN(u, N, Ts, v_curr, v_ref, veh, info);
    CONSTRAINTS = @(u) EVConstraintFCN(u, N, SOC, flag1);
    options = optimoptions('fmincon','Algorithm','sqp','Display','iter');
    [uopt,~,exitflag,~]= fmincon(COST,u0,[],[],[],[],LB,UB,CONSTRAINTS,options);
    disp(exitflag)
    U_f=uopt(1,1)*Torque_demand;
    U_r=Torque_demand-U_f;
end

function J = EVObjectiveFCN(u, N, Ts, v_curr, v_ref, veh, info)
    v_k = v_curr;
    J = 0;
    torque_demand_vec = [];
    J2_vec = [];

    % For initial condition
    % Calculating resistance forces
    F_aero = (veh.rho*veh.A*veh.Cd*(v_k^2))/2;
    F_rr = veh.M*9.81*veh.Crr;
        
    % Calculating current torque demand
    F_trac = F_aero + F_rr + veh.M*(v_ref - v_k)/Ts;
    torque_demand = F_trac*veh.R_whl;
    torque_demand_vec = [torque_demand_vec torque_demand];
    

    for i=1:N

        % Calculating eta_f & eta_r
        if (torque_demand > 0)
            eta_f = interp2(info.torque,info.speed,info.eff,u(1,i)*min(torque_demand,450),u(2,i));
            eta_r = interp2(info.torque,info.speed,info.eff,(1-u(1,i))*min(torque_demand,450),u(3,i));
        else
            eta_f = interp2(info.torque,info.speed,info.eff,u(1,i)*min(abs(torque_demand),450),u(2,i));
            eta_r = interp2(info.torque,info.speed,info.eff,(1-u(1,i))*min(abs(torque_demand),450),u(3,i));
        end

        %Calculating J

        J1 = 20000*exp(10-(eta_f/10))...
            + 20000*exp(10-(eta_r/10));
        if (torque_demand > 0 && torque_demand < 900)
            J2 = (((u(1,i)*torque_demand*u(2,i))/(0.01*eta_f)) + (((1-u(1,i))*torque_demand*u(3,i))/(0.01*eta_r)));
        elseif (torque_demand < 0 && torque_demand > -900)
            J2 = abs((((u(1,i)*torque_demand*u(2,i))*(0.01*eta_f)) + (((1-u(1,i))*torque_demand*u(3,i))*(0.01*eta_r))));
        end

        if (torque_demand > 900)
            J2 = (((u(1,i)*450*u(2,i))/(0.01*eta_f)) + (((1-u(1,i))*450*u(3,i))/(0.01*eta_r)));
        elseif (torque_demand < -900)
            J2 = abs((((u(1,i)*(-450)*u(2,i))*(0.01*eta_f)) + (((1-u(1,i))*-450*u(3,i))*(0.01*eta_r))));
        end

        J = J + 1.5*J2 + J1;
        J2_vec = [J2_vec J2];
        
        % Calculating resistance forces
        F_aero = (veh.rho*veh.A*veh.Cd*(v_k^2))/2;
        F_rr = veh.M*9.81*veh.Crr;

        % state dynamics
        % Ignore rotary inertia
        % See if forces can be given by matlab directly
        %soc_k = SOC - ((V_oc - sqrt((V_oc^2)-4*R_bat*J2))/(2*R_bat*C_bat))*Ts; 
        v_k_next = v_k + ((torque_demand/(veh.M*veh.R_whl))*veh.f_ratio - F_aero/veh.M - F_rr/veh.M)*Ts;

        % Calculating the next torque demand
        % Assuming  
        F_trac = F_aero + F_rr + veh.M*(v_ref - v_k_next)/Ts;
        next_torque_demand = F_trac*veh.R_whl;

        % Calculating motor speed
        %omega_whl = v_k_next/veh.R_whl;
        %omega_f = min(veh.f_ratio*omega_whl*(60/2*pi),1675);
        %omega_r = min(veh.f_ratio*omega_whl*(60/2*pi),1675);

        % Updating variables
        torque_demand = next_torque_demand/veh.f_ratio;
        torque_demand_vec = [torque_demand_vec torque_demand];
        v_k = v_k_next;
        %SOC = soc_k;
    end
end

%%
function [c,ceq]=EVConstraintFCN(u, N, torque_demand_vec, J2_vec, SOC, flag1)
    % split :- 1 -> Rear motor
    % split :- 0 -> Front motor
    torque_max = 900;
    % calculate curr torque and torque vec

    constraints = [];
    for i=1:N
        %power_generated = u(1,i)*torque_demand_vec(i)
        %if (torque_demand_vec(i) <= torque_max)
        %    constraints = [constraints power_generated == J2(i)]
        %end
    end

    c=[];
    ceq=[constraints];  
end