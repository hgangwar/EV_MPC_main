data = load("Max_Torque_vs_EMSpeed.mat");
EMspeed=data.TorqueVsSpeed(:,1);
torque_limit=data.TorqueVsSpeed(:,2);
%Pol=interp1(EMspeed,torque_limit,"linear",'pp');
F = griddedInterpolant(EMspeed,torque_limit,'pchip','nearest');
vq = F(EMspeed);
figure
plot(EMspeed,torque_limit,'o',EMspeed,vq,'-b');
legend ('actual','predicted')
disp(max(EMspeed.*torque_limit))