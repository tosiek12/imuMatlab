%% Close previous elements, import file from SD Card.
clc;
clear all;
close all
IMU = copyAndImportFileFromSDCard('imuGps_walkParallelToField_allWithStop');
%% (optional) Just load only file to workspace:
% load('imuRotationOfPitchAngle.mat');
% load('imuUpAndDownInOZ.mat');
% load('imuGpsWalkInTheGarden.mat');

% load('imuGps_walkParallelToField_half.mat'); %dziwne wahania cisnienia. czasami wchodzilo nawet na zerow¹ wartoœc.
% Jest chyba problem z kompensacj¹ przyspieszenia grawitacyjnego. Na OZ
% bardzo szybko spada po³o¿enie i zmienia siê prêdkoœæ.

load('imuGps_walkParallelToField_allWithStop.mat'); %dziwny spadek wysokoœci - wzrost
% ciœnienia...??


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

% Load initial values for displaing:
latShow = IMU.latG;
lonShow = IMU.lonG;
tShow = t;
latCracow = 5.0045743e+07;  %accurate
lonCracow = 1.9552048e+07;  %accurate
% Remove incorrect data(away from cracov):
distThreshold =  4.0e+6;
dist = sqrt((IMU.latG-latCracow).^2+(IMU.lonG-lonCracow).^2);
mask = dist<distThreshold;
latShow = IMU.latG(mask);
lonShow = IMU.lonG(mask);
tShow = t(mask);

%% Show GSP coordinates on map;
% [park, R] = geotiffread('ParkTiff/Untitled');

figure(1);
% mapshow(park, R);
axis image off;
lat_y = latShow;
long_x = lonShow;
[latInDeg_y,longInDeg_x] = change2Deg(lat_y,long_x); 
mapshow(longInDeg_x, latInDeg_y);
%% Show gps coordinates: 
figureHandler = figure('Position',[50, scrSize(4)/2-100, scrSize(3)/2-50, scrSize(4)/2]);
p = plot(lonShow, latShow, 'xr','MarkerSize',10 );
hold on
plot(lonCracow, latCracow, 'og', 'MarkerSize',10);
xlabel('lonG');
ylabel('latG');
title('koordynaty');
legend('Measured','Cracov');
grid on
axis square

% Show height from gps and from pressure.
figureHandler = figure('Position',[scrSize(3)/2, scrSize(4)/2-100, scrSize(3)/2-50, scrSize(4)/2]);
subplot(3,1,1)
plot(tShow, IMU.altG(mask)/10);
title('Wysokoœæ z GPS');
xlabel('Czas, s');
ylabel('Wysokoœæ, m');
hold on;
plot(tShow,220*ones(1,length(tShow)),'--g');
legend('GPS','rzeczywista');
%
subplot(3,1,2)
plot(tShow,IMU.hdop(mask),'-r');
title('HDOP - horizontal degree of precision');
xlabel('Czas, s');
ylabel('Wartoœæ');
hold on;
plot(tShow,90*ones(1,length(tShow)),'--g');
legend('HDOP','próg');

subplot(3,1,3)
plot(tShow, IMU.altP(mask)/1000,'-r');
title('Wysokoœæ z Ciœnieniomierza');
xlabel('Czas, s');
ylabel('Wysokoœæ, m');
hold on;
plot(tShow, 220*ones(1,length(tShow)),'--g');
legend('Ciœnieniomierz','rzeczywista');

%% gps on maps
mapData = [IMU.lonG, IMU.latG, IMU.altG];
coordinates  = [IMU.lonG, IMU.latG];

% Adding some random gauss noise:
meanVal = 0.00001;
sigmaVal = 0.00002;
noise = meanVal+sigmaVal.*randn(size(coordinates));

% Converting to dd.(rest) format:
coordinates_noise = coordinates.*noise;
coordinates_noise = coordinates_noise.*0.000001;
% Converting to decimal degrees:
% TODO: zmienic na poprawn¹ konwersjê:
coordinates_noise(:,1) = coordinates_noise(:,1)+ 0.36;  %tak na pa³e, by sie zgadzalo ;)
coordinates_noise(:,2) = coordinates_noise(:,2)+ 0.03;

% Creating two vectors for visualisation on map:
lon_x = coordinates_noise(:,1);
lat_y = coordinates_noise(:,2);
%%
figure(1);
plot(lon_x,lat_y, 'x');

figure(2);
mapshow(lon_x, lat_y);