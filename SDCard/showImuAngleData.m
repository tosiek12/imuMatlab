%% Close previous elements, import file from SD Card.
clc;
clear all;
close all
IMU = copyAndImportFileFromSDCard('imuRotationOfPitchAngle');
%% Compute time vector
numberOfProbes = length(IMU);
undersamplingFactor = 40;
samplingFrequency = 400;    %Hz
loggingFrequency = samplingFrequency/undersamplingFactor;   
t = (1:numberOfProbes)./loggingFrequency;

%%  Plot some angles ;)
IMU_raw = rad2deg(IMU.z/1000);
m_raw = mean(IMU_raw);
s_raw = std(IMU_raw);

IMU_cooked = rad2deg(IMU.z_c /1000);
m_cooked = mean(IMU_cooked);
s_cooked = std(IMU_cooked);

figure(1);
subplot(3,1,1);
plot(t, IMU_raw,'-b',t, IMU_cooked,'-r');
legend('Raw','Cooked');
ylim([-180,180]);
title(sprintf(['%s\nRaw:(mean: %.2f, stdDev: %.2f)\n' ...
    'Cooked:(mean: %.2f, stdDev: %.2f)'],'K¹t Pitch' ,m_raw,s_raw,m_cooked,s_cooked));
xlabel('Czas, s');
ylabel('K¹t, stopnie');