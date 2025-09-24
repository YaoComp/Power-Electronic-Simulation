
%% Simulation Step
% clear;
Ts_Power=10e-7;
Ts_Control=62.5e-6;
%% Grid parameters
Fnom_Grid=50;
Unom_Grid=690;
Unom_Phase=Unom_Grid/sqrt(3); 
L_grid=200e-6;
C_grid=45e-6;
%% Converter parameters
Fsw=1/Ts_Control;
Pnom=220e3;
Inom=Pnom/sqrt(3)/Unom_Grid;
Udc_ref=1500;
Cdc=180e-6;
%% Controller parameters
Kp_Edq=0.3;
Ki_Edq=Kp_Edq*2*pi*10;

Kp_Vdc=1;
Ki_Vdc=Kp_Vdc*2*pi*10;
Kp_Phase=Kp_Edq*0.1;
Ki_Phase=Ki_Edq*0.1;


% Kp_Idq=1*50;
% Ki_Idq=25*50;

Kp_Idq=L_grid/3/Ts_Control*3;
Ki_Idq=Kp_Idq*2*pi*2;

%% Droop control parameters
m=-2*pi*Fnom_Grid*0.01/0.1;
n=-0.05/0.1;
