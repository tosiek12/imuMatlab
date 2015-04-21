%% Close previous elements, import file from SD Card.
clc;
clear all;
close all
IMU = copyAndImportFileFromSDCard('imuUpAndDownInOZ');
%% (optional) Just load only file to workspace:
% load('imuRotationOfPitchAngle.mat');
load('imuUpAndDownInOZ.mat');
IMU = imuDataset;
clear imuDataset;
%% Show Coordinates and height
%Compute time vector:
numberOfProbes = length(IMU);
undersamplingFactor = 40;
samplingFrequency = 400;    %Hz
loggingFrequency = samplingFrequency/undersamplingFactor;   
t = (1:numberOfProbes)./loggingFrequency;

% get some values for figure plotting
scrSize = get(0,'ScreenSize');

% Show gps coordinates: 
figureHandler = figure('Position',[50, scrSize(4)/2-100, scrSize(3)/2-50, scrSize(4)/2]);
p = plot(IMU.lonG, IMU.latG, 'xr' );
set(p,'Color','red','MarkerSize',8);
xlabel('lonG');
ylabel('latG');
title('koordynaty');
grid on
axis square

% Show height from gps and from pressure.
figureHandler = figure('Position',[scrSize(3)/2, scrSize(4)/2-100, scrSize(3)/2-50, scrSize(4)/2]);
subplot(3,1,1)
plot(t,IMU.altG/10);
title('Wysoko�� z GPS');
xlabel('Czas, s');
ylabel('Wysoko��, m');
hold on;
plot(t,220*ones(1,length(t)),'--g');
legend('GPS','rzeczywista');

subplot(3,1,2)
plot(t,IMU.hdop,'-r');
title('HDOP - horizontal degree of precision');
xlabel('Czas, s');
ylabel('Warto��');
hold on;
plot(t,4*ones(1,length(t)),'--g');
legend('HDOP','pr�g');

subplot(3,1,3)
plot(t,IMU.altP/1000,'-r');
title('Wysoko�� z Ci�nieniomierza');
xlabel('Czas, s');
ylabel('Wysoko��, m');
hold on;
plot(t,220*ones(1,length(t)),'--g');
legend('Ci�nieniomierz','rzeczywista');

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
