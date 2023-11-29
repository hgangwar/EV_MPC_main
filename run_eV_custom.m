
clc
% dummy data for testing

current_timestep=1054154;
Torque_demand=20;
N=8;
SOC=0.5;
Ts=5e-02;
v_curr=23.85;


% MPC optimization
res = EVFmincon_test_v4(SOC, v_curr,Ts,N,current_timestep,Torque_demand);

