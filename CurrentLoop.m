clear;
close all;
%%
Ts_Control=62.5e-6;
Fnom_Grid=50;
Unom_Grid=690;
Unom_Phase=Unom_Grid/sqrt(3); 
Fsw=1/Ts_Control;
Pnom=220e3;
Inom=Pnom/sqrt(3)/Unom_Grid;
Udc_ref=1500;
Cdc=180e-6;
          
L1=200e-6;
L2=200e-6;
Cf=54e-6;
Gain_i=1/Inom/sqrt(2);
Gain_v=1/Unom_Phase/sqrt(2);

Kp=L2*2*pi*2000;
Ki=Kp*2*pi*10;
Kf=0.8;

%%
s = tf('s');
H_Gain_1=Gain_v/Gain_i;
H_PI=-(Kp+Ki/s);
H_Gain_2=1/Gain_v;
H_Gain_3=Gain_i;
H_LCL=-1/(L1*L2*Cf*s^3+(L1+L2)*s+Kf*L1*Cf*s^2);

H_Delay=exp(-2*Ts_Control*s);

H_OpenLoop=H_Gain_1*H_PI*H_Gain_2*H_Gain_3*H_LCL*H_Delay;
H_ClosedLoop=H_Gain_1*H_PI*H_Gain_2*H_Gain_3*H_LCL/(1+H_OpenLoop);
%%
f1=figure;
f1.Name='Bode Plot of Open Loop';
plotoptions = bodeoptions;
% plotoptions.Title.String='Bode Plot of Open Loop';
plotoptions.FreqUnits='Hz';
plotoptions.Grid ='on';
plotoptions.xLim=[1 20e3];
margin(H_OpenLoop,plotoptions);
close;
%% 
% Lead compensation network
phi=10/360*2*pi;
alpha=2/(1-sin(phi))-1;
gain_correction=10*log10(alpha);

[mag,~,wout] = bode(H_OpenLoop,{1 20e3});
mag=20*log10(squeeze(mag));
wout=squeeze(wout);
wm=interp1(mag,wout,-gain_correction);
zero=wm/sqrt(alpha);
pole=wm*sqrt(alpha);

H_Correction_Lead=(1+s/zero)/(1+s/pole);

%% 
% Lag compensation network
[mag,phase,wout] = bode(H_OpenLoop,{1 20e3});
mag=20*log10(squeeze(mag));
phase=squeeze(phase);
wout=squeeze(wout);
wc=2*pi*500;
Attenuation=interp1(wout,mag,wc);
alpha=10^(Attenuation/20);
zero1=wc/10;
pole1=zero1/alpha;
H_Correction_Lag=(1+s/zero1)/(1+s/pole1);

%%
H_Correction=H_Correction_Lag;
Wz_compensation=zero1;
Wp_compensation=pole1;
%%
H_OpenLoop_Correction=H_Gain_1*H_PI*H_Gain_2*H_Gain_3*H_LCL*H_Delay*H_Correction;
H_ClosedLoop_Correction=H_Gain_1*H_PI*H_Gain_2*H_Gain_3*H_LCL*H_Correction/(1+H_OpenLoop_Correction);
%%
f2=figure;
f2.Name='Bode Plot of Closed Loop';


plotoptions = bodeoptions;
% plotoptions.Title.String='Bode Plot of Closed Loop';
plotoptions.FreqUnits='Hz';
plotoptions.Grid ='on';
plotoptions.xLim=[1 20e3];

subplot(1,4,1);
bodeplot(H_OpenLoop,plotoptions);
hold on;
bodeplot(H_OpenLoop_Correction,plotoptions);
subplot(1,4,2);
bodeplot(H_ClosedLoop,plotoptions);
hold on;
bodeplot(H_ClosedLoop_Correction,plotoptions);
subplot(1,4,3);
margin(H_OpenLoop,plotoptions);
subplot(1,4,4);
margin(H_OpenLoop_Correction,plotoptions);




