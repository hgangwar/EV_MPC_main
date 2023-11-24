function [U_f,U_r] = EVFmincon_test_v2(SOC, v_curr, v_ref, Ts,N,veh,info,Torque_demand)
%% Extrinsic function used by Nonlinear MPC Block
    % Using motor speed as decision variable
    u0 = repmat([0.5;500;500],1,N);
    LB = repmat([0;0;0],1,N);
    UB = repmat([1;1675;1675],1,N);
    
    COST = @(u) EVObjectiveFCN(SOC, u, N, Ts, v_curr, v_ref, veh, info);
    %CONSTRAINTS=[];
    CONSTRAINTS = @(u) EVConstraintFCN(SOC,u, N,Ts,veh,v_curr,v_ref,info);
    options = optimoptions('fmincon','Algorithm','sqp','Display','iter');
    [uopt,~,exitflag,~]= fmincon(COST,u0,[],[],[],[],LB,UB,CONSTRAINTS,options);
    %disp(uopt)
    %disp(exitflag)
    U_f=uopt(1,1)*Torque_demand;
    U_r=Torque_demand-U_f;
end

function J = EVObjectiveFCN(SOC, u, N, Ts, v_curr, v_ref, veh, info)
    v_k = v_curr;
    J = 0;
    torque_demand_vec = [];
    J2_vec = []; 

    for i=1:N
        % For initial condition
        % Calculating resistance forces
        F_aero = (veh.rho*veh.A*veh.Cd*(v_k^2))/2;
        F_rr = veh.M*9.81*veh.Crr;
            
        % Calculating current torque demand
        F_trac = F_aero + F_rr + veh.M*(v_ref(i) - v_k)/Ts;
        torque_demand = F_trac*veh.R_whl;
        torque_demand_vec = [torque_demand_vec torque_demand];

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
        J = J + 1.5*J2;
        J2_vec = [J2_vec J2];
        
        % Calculating resistance forces
        F_aero = (veh.rho*veh.A*veh.Cd*(v_k^2))/2;
        F_rr = veh.M*9.81*veh.Crr;

        % state dynamics
        % Ignore rotary inertia
        % See if forces can be given by matlab directly
        %soc_k = SOC - ((V_oc - sqrt((V_oc^2)-4*R_bat*J2))/(2*R_bat*C_bat))*Ts; 
        v_k = v_k + ((F_trac - F_aero - F_rr)/veh.M)*Ts;
    end
end

%%
function [c,ceq]=EVConstraintFCN(SOC,u,N,Ts,veh,v_k,v_ref,info)
    % split :- 1 -> Rear motor
    % split :- 0 -> Front motor
    torque_max = 450;
    torque_min = -450;
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

        % Calculating eta_f & eta_r
        if (torque_demand > 0)
            eta_f = interp2(info.torque,info.speed,info.eff,u(1,i)*min(torque_demand,450),u(2,i));
            eta_r = interp2(info.torque,info.speed,info.eff,(1-u(1,i))*min(torque_demand,450),u(3,i));
        else
            eta_f = interp2(info.torque,info.speed,info.eff,u(1,i)*min(abs(torque_demand),450),u(2,i));
            eta_r = interp2(info.torque,info.speed,info.eff,(1-u(1,i))*min(abs(torque_demand),450),u(3,i));
        end
        if (torque_demand > 0)
            Pw_dem = (((u(1,i)*torque_demand*u(2,i))/(0.01*eta_f)) + (((1-u(1,i))*torque_demand*u(3,i))/(0.01*eta_r)));
            Pw_gen = (((u(1,i)*F_trac*v_k)/(0.01*eta_f)) + (((1-u(1,i))*F_trac*v_k)/(0.01*eta_r)));
        elseif (torque_demand < 0)
            Pw_dem = abs((((u(1,i)*torque_demand*u(2,i))*(0.01*eta_f)) + (((1-u(1,i))*torque_demand*u(3,i))*(0.01*eta_r))));
            Pw_gen = abs((((u(1,i)*F_trac*v_k)*(0.01*eta_f)) + (((1-u(1,i))*F_trac*v_k)*(0.01*eta_r))));
        end
        constraints=[constraints Pw_gen-Pw_dem];
        v_k = v_k + ((F_trac - F_aero - F_rr)/veh.M)*Ts;
    end

    ceq=constraints;  
end