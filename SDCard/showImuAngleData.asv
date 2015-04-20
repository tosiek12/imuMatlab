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
%% Plot roll:
data = [IMU.x,IMU.x_c];
numberOfPlot = 1;
IMU_raw = rad2deg(data(:,1)/1000);
m_raw = mean(IMU_raw);
s_raw = std(IMU_raw);

IMU_cooked = rad2deg(data(:,2)/1000);
m_cooked = mean(IMU_cooked);
s_cooked = std(IMU_cooked);

figure(1);
subplot(3,1,numberOfPlot);
plot(t, IMU_raw,'-b',t, IMU_cooked,'-r');
legend('Raw','Cooked');
ylim([-180,180]);
title(sprintf(['%s\nRaw:(mean: %.2f, stdDev: %.2f)\n' ...
    'Cooked:(mean: %.2f, stdDev: %.2f)'],'K¹t Roll' ,m_raw,s_raw,m_cooked,s_cooked));
xlabel('Czas, s');
ylabel('K¹t, stopnie');
%% Plot Yaw:
data = [IMU.y,IMU.y_c];
numberOfPlot = 2;
IMU_raw = rad2deg(data(:,1)/1000);
m_raw = mean(IMU_raw);
s_raw = std(IMU_raw);

IMU_cooked = rad2deg(data(:,2)/1000);
m_cooked = mean(IMU_cooked);
s_cooked = std(IMU_cooked);

figure(1);
subplot(3,1,numberOfPlot);
plot(t, IMU_raw,'-b',t, IMU_cooked,'-r');
legend('Raw','Cooked');
ylim([-180,180]);
title(sprintf(['%s\nRaw:(mean: %.2f, stdDev: %.2f)\n' ...
    'Cooked:(mean: %.2f, stdDev: %.2f)'],'K¹t Pitch' ,m_raw,s_raw,m_cooked,s_cooked));
xlabel('Czas, s');
ylabel('K¹t, stopnie');
%% Plot yaw:
data = [IMU.z,IMU.z_c];
numberOfPlot = 3;
IMU_raw = rad2deg(data(:,1)/1000);
m_raw = mean(IMU_raw);
s_raw = std(IMU_raw);

IMU_cooked = rad2deg(data(:,2)/1000);
m_cooked = mean(IMU_cooked);
s_cooked = std(IMU_cooked);

figure(1);
subplot(3,1,numberOfPlot);
plot(t, IMU_raw,'-b',t, IMU_cooked,'-r');
legend('Raw','Cooked');
ylim([-180,180]);
title(sprintf(['%s\nRaw:(mean: %.2f, stdDev: %.2f)\n' ...
    'Cooked:(mean: %.2f, stdDev: %.2f)'],'K¹t Yaw' ,m_raw,s_raw,m_cooked,s_cooked));
xlabel('Czas, s');
ylabel('K¹t, stopnie');