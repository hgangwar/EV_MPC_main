clear;
clc
% Constants
veh.M = 1623;         %Vehicle Mass 
veh.R_whl = 0.327;   %Wheel effective radius
veh.Crr = 0.012;         %Coefficient of friction
veh.Cd = 0.389;        %Air drag coeficient
veh.rho = 1.202;       %Air density
veh.A = 2.27;           %Surface area car
veh.f_ratio = 3.32;   % final gear ratio

% Loading effeciency map
data = load("eff_map.mat");
info.eff = data.eff;
info.torque = data.torque;
info.speed = data.speed;

%Torque limit
data = load("Max_Torque_vs_EMSpeed.mat");
info.torque_limit=data.TorqueVsSpeed;

% dummy data for testing

current_timestep=19772;
Torque_demand=20;
N=8;
SOC=0.5;
Ts=5e-04;
omega_f=400;
omega_r=400;
flag1=1;
v_curr=3.65;
Data=load("ftp75_sync.mat");
%v_ref=Data.new_ftp(current_timestep:current_timestep+N,1);
v_ref=3.67*(ones(1,N));

% MPC optimization
res = EVFmincon_test(SOC, v_curr, v_ref, Ts, N, veh, info,Torque_demand);

