function [U_f,U_r] = EVFmincon_custom(SOC, v_curr, v_ref, Ts, omega_f, omega_r, flag1, Torque_demand,N,current_timestep,veh,info)
%% Extrinsic function used by Nonlinear MPC Block
    % Initializing U vector
    %u0=0.5*[ones(1,N)];
    %LB=[zeros(1,N)];
    %UB=[ones(1,N)];

    % Using motor speed as decision variable
    u0 = repmat([0.5;500;500],1,N);
    LB = repmat([0;0;0],1,N);
    UB = repmat([1;1675;1675],1,N);
    
    COST = @(u) EVObjectiveFCN(SOC, u, N, Ts, v_curr, v_ref, flag1, Torque_demand, veh, info, omega_f, omega_r);
    %CONSTRAINTS=[];
    CONSTRAINTS = @(u) EVConstraintFCN(u, N, SOC, Torque_demand, flag1);
    options = optimoptions('fmincon','Algorithm','sqp','Display','iter');
    [uopt,~,exitflag,~]= fmincon(COST,u0,[],[],[],[],LB,UB,CONSTRAINTS,options);
    U_f=uopt(1)*Torque_demand;
    U_r=Torque_demand-U_f;
    disp(exitflag)
end

function J = EVObjectiveFCN(SOC, u, N, Ts, v_curr, v_ref, flag1, Torque_demand, veh, info, omega_f, omega_r)
    v_k = v_curr;
    J = 0;
    Torque_vec = [];
    for i=1:N
        % Calculating eta_f & eta_r
        if (Torque_demand > 0)
            eta_f = interp2(info.torque,info.speed,info.eff,u(1,i)*min(Torque_demand,450),u(2,i));
            eta_r = interp2(info.torque,info.speed,info.eff,(1-u(1,i))*min(Torque_demand,450),u(3,i));
        else
            eta_f = interp2(info.torque,info.speed,info.eff,u(1,i)*min(abs(Torque_demand),450),u(2,i));
            eta_r = interp2(info.torque,info.speed,info.eff,(1-u(1,i))*min(abs(Torque_demand),450),u(3,i));
        end
        %Calculating J

        J1 = 1000*exp(10-(eta_f/10))...
            + 1000*exp(10-(eta_r/10));
        if (Torque_demand > 0)
            J2 = (((u(1,i)*Torque_demand*u(2,i))/(0.01*eta_f)) + (((1-u(1,i))*Torque_demand*u(3,i))/(0.01*eta_r)));
        else
            J2 = abs((((u(1,i)*Torque_demand*u(2,i))*(0.01*eta_f)) + (((1-u(1,i))*Torque_demand*u(3,i))*(0.01*eta_r))));
        end

        J = J + J1 + J2;
        
        % Calculating resistance forces
        F_aero = (veh.rho*veh.A*veh.Cd*(v_k^2))/2;
        F_rr = veh.M*9.81*veh.Crr;

        % state dynamics
        % Ignore rotary inertia
        % See if forces can be given by matlab directly
        %soc_k = SOC - ((V_oc - sqrt((V_oc^2)-4*R_bat*J2))/(2*R_bat*C_bat))*Ts; 
        v_k_next = v_k + ((Torque_demand/(veh.M*veh.R_whl))*veh.f_ratio - F_aero/veh.M - F_rr/veh.M)*Ts;

        % Calculating the next torque demand
        % Assuming  
        F_trac = F_aero + F_rr + veh.M*(v_ref - v_k_next)/Ts;
        next_torque_demand = F_trac*veh.R_whl;

        % Calculating motor speed
        omega_whl = v_k_next/veh.R_whl;
        omega_f = min(veh.f_ratio*omega_whl*(60/2*pi),1675);
        omega_r = min(veh.f_ratio*omega_whl*(60/2*pi),1675);

        % Updating variables
        Torque_demand = next_torque_demand/veh.f_ratio;
        v_k = v_k_next;
        %SOC = soc_k;
    end
end
%%
function Fz=Normal_reaction(M,v_dot)
    L=2.79;         %longitudinal distance between wheels 
    b=0.3;          %height between wheel centre and CM
    g=9.81;         %gravity
    Fz_f=(M/L)*((g*L/2)-(b*v_dot));
    Fz_r=(M/L)*((g*L/2)+(b*v_dot));
    Fz=Fz_f+Fz_r;
end
%%
function [Fx, Omega_f_next, Omega_r_next]=longitudinal_wheel(Trq_demand,flag1,u,Ts,Omega_f,Omega_r,Reff)
    Rotor_inertia=0.01;
    [Uf_out, Ur_out, Uf_in,Ur_in]=Torque_distribution(Trq_demand,flag1,u);
    Net_torque=Uf_out+Ur_out- Uf_in-Ur_in;
    Delta_Om=(Ts*Net_torque)/Rotor_inertia;
    Omega_f_next=Omega_f+Delta_Om;
    Omega_r_next=Omega_r+Delta_Om;              %new angular velocities
    Fx=Net_torque/Reff;                         % traction force
end

%%
function [x_next]=state(x,Pw,flag1)
    E_batt=1e09;  %%Battery constant
    x_next=x+((-1)^flag1)*(Pw/E_batt);    
end
%% Torque 
function [U_out1, U_out2, U_in1, U_in2]=Torque_distribution(Torque_demand,flag1,u)
    if flag1==1  % Motor Mode
        U_out1=u*Torque_demand;
        U_out2=Torque_demand-U_out1;
        U_in1=0;
        U_in2=0;
    else         % Generator Mode   
        U_in1=u*Torque_demand;
        U_in2=Torque_demand-U_in1;
        U_out1=0;
        U_out2=0;
    end
end
%%
function [etaf_in, etaf_out, etar_in, etar_out]=eff_map(Torque_demand,flag1,u,Omega_f, Omega_r)
    data=load("eff_map.mat");
    eff=data.eff;
    torque=data.torque;
    speed=data.speed;
    Uf=abs(u*Torque_demand);
    Ur=abs((1-u)*Torque_demand);
    Omega_f=abs(Omega_f);
    Omega_r=abs(Omega_r);
    if flag1==1
        etaf_out=interp2(torque,speed,eff,Uf,Omega_f)/100;
        etar_out=interp2(torque,speed,eff,Ur,Omega_r)/100;
        etaf_in=1;  
        etar_in=1;
    else
        etaf_out=0;
        etar_out=0;
        etaf_in=interp2(torque,speed,eff,Uf,Omega_f)/100;  
        etar_in=interp2(torque,speed,eff,Ur,Omega_r)/100;
    end
end

%%
function [c,ceq]=EVConstraintFCN(u, N, SOC, Torque_demand, flag1)

    c=[];
    ceq=[];
  
end