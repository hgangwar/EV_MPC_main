function [U_f,U_r] = EVFmincon_test_v4(SOC, v_curr,Ts,N,current_timestep,Torque_demand)
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
    CONSTRAINTS = @(u) EVConstraintFCN(u, N,Ts,veh,v_curr,v_ref,info);
    options = optimoptions('fmincon','Algorithm','sqp','Display','iter');
    [uopt,~,exitflag,~]= fmincon(COST,u0,[],[],[],[],LB,UB,CONSTRAINTS,options);
    %disp(uopt)
    disp(exitflag)
    U_f=uopt(1,1)*Torque_demand;
    U_r=Torque_demand-U_f;
end

function J = EVObjectiveFCN(u, N, Ts, v_curr, v_ref, veh, info)
    v_k = v_curr;
    J = 0;
    torque_demand_vec = [];
    % For initial condition
    % Calculating resistance forces
    F_aero = (veh.rho*veh.A*veh.Cd*(v_k^2))/2;
    F_rr = veh.M*9.81*veh.Crr;
        
    % Calculating current torque demand
    F_trac = F_aero + F_rr + veh.M*(v_ref(1) - v_k)/Ts;
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

        % penalise excess power
        if (torque_demand > 0)
            power_gen = ((u(1,i)*torque_demand*u(2,i))/(0.01*eta_f)) + (((1-u(1,i))*torque_demand*u(3,i))/(0.01*eta_r));
            %power_ref = ((u(1,i)*F_trac*v_k)/(0.01*eta_f)) + (((1-u(1,i))*F_trac*v_k)/(0.01*eta_r));
            power_ref = F_trac*v_k;
        else
            power_gen = abs(((u(1,i)*torque_demand*u(2,i))*(0.01*eta_f)) + (((1-u(1,i))*torque_demand*u(3,i))*(0.01*eta_r)));
            %power_ref = abs(((u(1,i)*F_trac*v_k)*(0.01*eta_f)) + (((1-u(1,i))*F_trac*v_k)*(0.01*eta_r)));
            power_ref = abs(F_trac*v_k);
        end
        J1 = (power_ref - power_gen)'*1*(power_ref - power_gen);
        J = J + J1;
        
        % Calculating resistance forces
        F_aero = (veh.rho*veh.A*veh.Cd*(v_k^2))/2;
        F_rr = veh.M*9.81*veh.Crr;

        % state dynamics
        v_k_next = v_k + ((torque_demand/(veh.M*veh.R_whl))*veh.f_ratio - F_aero/veh.M - F_rr/veh.M)*Ts;

        % Calculating the next torque demand
        % Assuming  
        F_trac = F_aero + F_rr + veh.M*(v_ref(i) - v_k_next)/Ts;
        next_torque_demand = F_trac*veh.R_whl;

        % Updating variables
        torque_demand = next_torque_demand/veh.f_ratio;
        torque_demand_vec = [torque_demand_vec torque_demand];
        v_k = v_k_next;
        %SOC = soc_k;
    end
end

%%
function [c,ceq]=EVConstraintFCN(u,N,Ts,veh,v_k,v_ref,info)
    % split :- 1 -> Front motor
    % split :- 0 -> Rear motor
    
    % calculate curr torque and torque vec
    c=[];
    constraints = [];
    torque_demand_vec=[];
    for i=1:N
        F_aero = (veh.rho*veh.A*veh.Cd*(v_k^2))/2;
        F_rr = veh.M*9.81*veh.Crr;
        F_trac = F_aero + F_rr + veh.M*(v_ref(i) - v_k)/Ts;
        torque_demand = F_trac*veh.R_whl;
        torque_demand_vec = [torque_demand_vec torque_demand];

        if (u(1,i) == 1)
            Pw_gen = ((u(3,i)));
        elseif (u(1,i) == 0)
            Pw_gen = ((u(2,i)));
        end

        % Calculating eta_f & eta_r
        if (torque_demand > 0)
            eta_f = interp2(info.torque,info.speed,info.eff,u(1,i)*min(torque_demand,450),u(2,i));
            eta_r = interp2(info.torque,info.speed,info.eff,(1-u(1,i))*min(torque_demand,450),u(3,i));
        else
            eta_f = interp2(info.torque,info.speed,info.eff,u(1,i)*min(abs(torque_demand),450),u(2,i));
            eta_r = interp2(info.torque,info.speed,info.eff,(1-u(1,i))*min(abs(torque_demand),450),u(3,i));
        end

        if (torque_demand > 0 && u(1,i) ~= 1 && u(1,i) ~= 0)
            Pw_gen = (((u(1,i)*torque_demand*u(2,i))/(0.01*eta_f)) + (((1-u(1,i))*torque_demand*u(3,i))/(0.01*eta_r)));
            Pw_dem = (((u(1,i)*F_trac*v_k)/(0.01*eta_f)) + (((1-u(1,i))*F_trac*v_k)/(0.01*eta_r)));
        elseif (torque_demand < 0 && u(1,i) ~= 1 && u(1,i) ~= 0)
            Pw_gen = abs((((u(1,i)*torque_demand*u(2,i))*(0.01*eta_f)) + (((1-u(1,i))*torque_demand*u(3,i))*(0.01*eta_r))));
            Pw_dem = abs((((u(1,i)*F_trac*v_k)*(0.01*eta_f)) + (((1-u(1,i))*F_trac*v_k)*(0.01*eta_r))));
        elseif (torque_demand > 0 && u(1,i) == 0)
            Pw_gen = ((torque_demand*u(3,i))/(0.01*eta_r));
            Pw_dem = ((F_trac*v_k)/(0.01*eta_r));
        elseif (torque_demand < 0 && u(1,i) == 0)
            Pw_gen = abs((torque_demand*u(3,i))*(0.01*eta_r));
            Pw_dem = abs((F_trac*v_k)*(0.01*eta_r));
        elseif (torque_demand > 0 && u(1,i) == 1)
            Pw_gen = ((torque_demand*u(2,i))/(0.01*eta_f));
            Pw_dem = ((F_trac*v_k)/(0.01*eta_f));
        elseif (torque_demand < 0 && u(1,i) == 1)
            Pw_gen = abs((torque_demand*u(2,i))*(0.01*eta_f));
            Pw_dem = abs((F_trac*v_k)*(0.01*eta_f));
        end

        %for motor 1
        torque_max = interp1(info.torque_limit(:,1),info.torque_limit(:,2),u(2,i));
        torque_min = -torque_max;
        c=[c; torque_min-(u(1,i)*torque_demand)];
        c=[c; (u(1,i)*torque_demand)-torque_max];
        %for motor 2
        c=[c; torque_min-((1-u(1,i))*torque_demand)];
        c=[c; ((1-u(1,i))*torque_demand)-torque_max];
        if(isnan(Pw_gen) || isnan(Pw_dem))
            %pause;
        end
        constraints=[constraints Pw_gen];
        v_k = v_k + ((F_trac - F_aero - F_rr)/veh.M)*Ts;
    end
    ceq=[];  
end