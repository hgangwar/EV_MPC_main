
Data1=load("C:\Users\swang443.ASURITE\MATLAB\EV_MPC_main\ftp75_5ms.mat");

Data2 = load("C:\Users\swang443.ASURITE\MATLAB\EV_MPC_main\eff_map.mat");
Data3 = load("C:\Users\swang443.ASURITE\MATLAB\EV_MPC_main\Max_Torque_vs_EMSpeed.mat");

custom_struct.ftp75_5ms = Data1.ftp75_5ms;
custom_struct.eff = Data2.eff;
custom_struct.torque = Data2.torque;
custom_struct.speed = Data2.speed;
custom_struct.TorqueVsSpeed = Data3.TorqueVsSpeed;

Data_var=Simulink.Bus.createObject(custom_struct);
Data_bus=evalin("base",Data_var.busName);
Data1=load("C:\Users\swang443.ASURITE\MATLAB\EV_MPC_main\ftp75_5ms.mat");
Data_1=evalin("base",'Data1');


