
%% Simulation Step
% clear;
Ts_Power=10e-7;
Ts_Control=100e-6;
%% Grid parameters
Fnom_Grid=50;
Unom_Grid=690;
Unom_Phase=Unom_Grid/sqrt(3); 
L_grid=200e-6;
C_grid=45e-6;
%% Converter parameters
Fsw=1/Ts_Control;
Pnom=2.5e6;
Inom=Pnom/sqrt(3)/Unom_Grid;
Udc_ref=1500;
Cdc=180e-6;
%% Controller parameters
Kp_Udc=100;
Ki_Udc=Kp_Udc*2*pi*10;

Kp_Idq=L_grid*2*pi*1600;
Ki_Idq=Kp_Idq*2*pi*0.1;


Gain_for_ActiveDamping=1;
