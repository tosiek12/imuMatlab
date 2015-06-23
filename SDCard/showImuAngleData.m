%% Close previous elements, import file from SD Card.
clc;
clear all;
close all
IMU = copyAndImportFileFromSDCard('imuUpAndDownInOZ2');
%% (optional) Just load only file to workspace:
% load('imuRotationOfPitchAngle.mat');
load('imuGps_walkParallelToField_allWithStop.mat');
% load('imuGPS_WalkParallelToField_allWithStop_pressureTemp_v2.mat');

IMU = imuDataset;
clear imuDataset;
%% (optional) Skip some first few data records
numberRecordToSkip = 50;
if numberRecordToSkip < length(IMU) 
    if ~exist('IMU_org') 
        IMU_org = IMU; 
    end
    IMU = IMU_org((numberRecordToSkip:length(IMU_org)),:);
    disp 'Obcieto'
end
%% Plot all angles
% Compute time vector for ploting
numberOfProbes = length(IMU);
undersamplingFactor = 40;
samplingFrequency = 400;    %Hz
loggingFrequency = samplingFrequency/undersamplingFactor;   
t = (1:numberOfProbes)./loggingFrequency;

% Get some values for figure plotting
scrSize = get(0,'ScreenSize');

% Plot roll:
data = [IMU.x,IMU.x_c];
numberOfPlot = 1;
IMU_raw = rad2deg(data(:,1)/1000);
m_raw = mean(IMU_raw);
s_raw = std(IMU_raw);

IMU_cooked = rad2deg(data(:,2)/1000);
m_cooked = mean(IMU_cooked);
s_cooked = std(IMU_cooked);

figureHandler = figure('Position',[50, scrSize(4)/2-100,scrSize(3)/2,scrSize(4)/3]);
plot(t, IMU_raw,'-b',t, IMU_cooked,'-r');
legend('Raw','Cooked');
ylim([-180,180]);
title(sprintf(['%s\nRaw:(mean: %.2f, stdDev: %.2f)\n' ...
    'Cooked:(mean: %.2f, stdDev: %.2f)'],'K¹t Roll' ,m_raw,s_raw,m_cooked,s_cooked));
xlabel('Czas, s');
ylabel('K¹t, stopnie');
saveas(figureHandler,'1roll.bmp');

% Plot pitch:
data = [IMU.y,IMU.y_c];
IMU_raw = rad2deg(data(:,1)/1000);
m_raw = mean(IMU_raw);
s_raw = std(IMU_raw);

IMU_cooked = rad2deg(data(:,2)/1000);
m_cooked = mean(IMU_cooked);
s_cooked = std(IMU_cooked);

figureHandler = figure('Position',[50, scrSize(4)/2-100,scrSize(3)/2,scrSize(4)/3]);
plot(t, IMU_raw,'-b',t, IMU_cooked,'-r');
legend('Raw','Cooked');
ylim([-180,180]);
title(sprintf(['%s\nRaw:(mean: %.2f, stdDev: %.2f)\n' ...
    'Cooked:(mean: %.2f, stdDev: %.2f)'],'K¹t Pitch' ,m_raw,s_raw,m_cooked,s_cooked));
xlabel('Czas, s');
ylabel('K¹t, stopnie');
saveas(figureHandler,'1pitch.bmp');

% Plot yaw:
data = [IMU.z,IMU.z_c];
IMU_raw = rad2deg(data(:,1)/1000);
m_raw = mean(IMU_raw);
s_raw = std(IMU_raw);

IMU_cooked = rad2deg(data(:,2)/1000);
m_cooked = mean(IMU_cooked);
s_cooked = std(IMU_cooked);

figureHandler = figure('Position',[50, scrSize(4)/2-100,scrSize(3)/2,scrSize(4)/3]);
plot(t, IMU_raw,'-b',t, IMU_cooked,'-r');
legend('Raw','Cooked');
% ylim([-180,180]);
xlim('auto');
title(sprintf(['%s\nRaw:(mean: %.2f, stdDev: %.2f)\n' ...
    'Cooked:(mean: %.2f, stdDev: %.2f)'],'K¹t Yaw' ,m_raw,s_raw,m_cooked,s_cooked));
xlabel('Czas, s');
ylabel('K¹t, stopnie');
saveas(figureHandler,'1yaw.bmp');
disp 'Koniec';