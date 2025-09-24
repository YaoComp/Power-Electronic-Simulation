%% Sample rate
Ts_Control=62.5e-6;
%% Grid parameters
Fnom_Grid=50;
Unom_Grid=690;
Unom_Phase=Unom_Grid/sqrt(3); 
L_grid=200e-6;
C_grid=36e-6;
%% Converter parameters
Pnom=220e3;
Inom=Pnom/sqrt(3)/Unom_Grid;
Udc_ref=1500;
Cdc=180e-6;
%% Controller parameters
Kp_Idq=L_grid*2*pi*1600;
Ki_Idq=Kp_Idq*2*pi*0.5;
Gain_for_ActiveDamping=1;