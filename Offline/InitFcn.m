%% data offline
% filename = '400_S_Oz';
% filename = '400_S,przes-x';
% filename = 'oscylacje 0x,g0y';
filename = '400hz--ox+ox';

filename = ['DanePomiarowe\' , filename , '.log'];
measurement = importfile(filename);

index = 1;
% *************************************************
% Constants
% *************************************************
%% For calibartion
gyroGain = ones(3,1); gyroBias = zeros(3,1);
gyroBias(1) = 461;
gyroBias(2) = -243;
gyroBias(3) = 58;
gyroGain(1) = 180/20720;
gyroGain(2) = 180/20720;
gyroGain(3) = 180/20720;
% ((float32_t)0.067565)     // 14.375 LSB/(grad/s)

%Accelerometer
accGain = ones(3,1); accBias = zeros(3,1);
accGain(1) = 3.90;
accGain(2) = 3.92;
accGain(3) = 3.92;
%dodatkowa kalibracja(d³ugoœæ wektora g w spoczynku):
accGain = accGain.*(9.81/9.761);
accBias(1) = 5.5;
accBias(2) = 10;
accBias(3) = 0.5;

%Magnetometer
% magGainM = [1.028, 0.01, 0.004;
%             -0.01, 1.044, 0.088;
%             0.02, 0.014, 1.162];
% magBias(1) = 2.06;
% magBias(2) = -25.661;
% magBias(3) = 46.211;

% %% proba - 3644 probek.
% Bfield =  589.8300;
% offset =[
%    -4.7953
%     9.4034
%   -48.4420];
% W_inverted = [
%     0.9552   -0.0094    0.0184
%    -0.0094    0.9582   -0.0005
%     0.0184   -0.0005    1.0930];

% proba - 6396 probek - 
Bfield = 586.2043;
offset = [-3.8266; 9.2826; -49.7737];
W_inverted = [
    0.9670   -0.0091    0.0265
   -0.0091    0.9517    0.0071
    0.0265    0.0071    1.0875 ];
magBias = [(743-502);(743-507);(579-516)]/2;    %Z usrednienia kilkunastu sek.
magGainM = W_inverted;

%%
usrednien = 5;
filterDelay = round((6.90-6.55)*100);

zakresWykresu = 1000;
%%
% last = max(size(measurement));
% out = measurement(last-100:last, 1:3);
% out = 
% g_1 = diag(sqrt(out*out'));
% g_1_avr = mean(g_1)
%%
order = 1;
filtCutOff = 0.1;
[b, a] = butter(order, (2*filtCutOff)/(1/0.01), 'high');
% linVelHP = filtfilt(b, a, linVel);