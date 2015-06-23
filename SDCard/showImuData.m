%% Close previous elements, import file from SD Card.
clc;
clear all;
close all
IMU = copyAndImportFileFromSDCard('imuGPS_WalkParallelToField_allWithStop_pressureTemp_v2');
%% (optional) Just load only file to workspace:
% load('imuRotationOfPitchAngle.mat');
% load('imuUpAndDownInOZ.mat');

load('imuGps_walkParallelToField_allWithStop.mat'); %dziwny spadek wysokoœci - wzrost
% ciœnienia...??

% load('imuGPS_WalkParallelToField_allWithStop_pressureTemp_v2.mat');
IMU = imuDataset;
clear imuDataset;
%% Show deltas
%Compute time vector:
numberOfProbes = length(IMU);
undersamplingFactor = 40;
samplingFrequency = 400;    %Hz
loggingFrequency = samplingFrequency/undersamplingFactor;   
t = (1:numberOfProbes)./loggingFrequency;
mask = or(IMU.x>0,IMU.x<=0);
% get some values for figure plotting
scrSize = get(0,'ScreenSize');
%% Remove incorrect data:
latCracow = 5.0045743e+07;  %accurate
lonCracow = 1.9552048e+07;  %accurate
latCracowMean = 5.340621965851671e+07;  %average
lonCracowMean = 1.821655450366748e+07;  %average
distThreshold =  4.0e+6;
distMean = sqrt((IMU.latG-latCracowMean).^2+(IMU.lonG-lonCracowMean).^2);
dist = sqrt((IMU.latG-latCracow).^2+(IMU.lonG-lonCracow).^2);
mask = dist<distThreshold;
latShow = IMU.latG(mask);
lonShow = IMU.lonG(mask);
%% Show deltas and speed
clc
tShow = t(mask);

figureHandler = figure('Position',[scrSize(3)/2, scrSize(4)/2-100, scrSize(3)/2-50, scrSize(4)/2]);
data = [IMU.dx(mask)/1000, IMU.dy(mask)/1000, IMU.dz(mask)/1000];
m_data = mean(data);
s_data = std(data);
plot(tShow, data');
xlabel('Czas, s');
ylabel('Przyrosty, m');
legend('dx','dy','dz');
axis on;
disp (['mean:',mat2str(m_data,2)]);
disp (['std:',mat2str(s_data,2)]);
title(sprintf(['Przyrosty po³o¿enia w kolejnych osiach\n' ...
    'Œrednia: %s\n' ...
    'Odchylenie standardowe: %s'],mat2str(m_data,2),mat2str(s_data,2)));
saveas(figureHandler,'3przyrosty.bmp');