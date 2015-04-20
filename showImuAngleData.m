%% Close, import, compute stats, plot
clc;
clear all;
close all
IMU = importfile('IMU.TXT', 4*400, inf);
% Plot some angles ;)
clc;
numberOfProbes = length(IMU);
samplingFrequency = 400;   %Hz
t = (1:numberOfProbes)./samplingFrequency;

IMU_raw = IMU.y;
IMU_raw = IMU_raw./1000;
IMU_raw = rad2deg(IMU_raw);
m_raw = mean(IMU_raw);
s_raw = std(IMU_raw);

IMU_cooked = IMU.y_c;
IMU_cooked  = IMU_cooked ./1000;
IMU_cooked = rad2deg(IMU_cooked );
m_cooked = mean(IMU_cooked);
s_cooked = std(IMU_cooked);

figure(1);
subplot(3,1,1);
plot(t, IMU_raw);
hold on;
plot(t, IMU_cooked,'-r');

title(sprintf(['%s\nRaw:(mean: %.2f, stdDev: %.2f)\n' ...
    'Cooked:(mean: %.2f, stdDev: %.2f)'],'K¹t Pitch' ,m_raw,s_raw,m_cooked,s_cooked));
xlabel('Czas, s');
ylabel('K¹t, stopnie');