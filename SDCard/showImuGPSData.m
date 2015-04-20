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
%% gps
figure(1);
plot3(IMU.lonG, IMU.latG, IMU.altG );
xlabel('lonG');
ylabel('latG');
zlabel('altG');
title('koordynaty i wysokosc');
grid on
axis square

%% gps on maps
load('IMUwPokoju.mat');
IMU = IMwpookoju;
clear IMwpookoju;
mapData = [IMU.lonG, IMU.latG, IMU.altG];
coordinates  = [IMU.lonG, IMU.latG];

noise = 1+0.00002.*randn(size(coordinates));

coordinates_noise = coordinates.*noise;
coordinates_noise = coordinates_noise.*0.000001;

coordinates_noise(:,1) = coordinates_noise(:,1)+ 0.36;  %tak na pa�e, by sie zgadzalo ;)
coordinates_noise(:,2) = coordinates_noise(:,2)+ 0.03;

lon = coordinates_noise(:,1);
lat = coordinates_noise(:,2);

%% wysokosc
figure(2);
subplot(2,1,1)
plot(t,IMU.altG/10);
hold on
plot(t,IMU.altP/1000,'-r');
hold off
legend('GPS','Ci�nieniomierz');
subplot(2,1,2)
plot(t,IMU.dop);
hold on
plot(t,IMU.hdop,'-r');
legend('dop','hdop');