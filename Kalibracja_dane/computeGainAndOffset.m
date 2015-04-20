function [gain, offset ] = computeGainAndOffset( plusMinus )
%COMPUTEGAINANDOFFSET Summary of this function goes here
%   Detailed explanation goes here
plus = plusMinus(1);
minus = plusMinus(2);
g = 981.05; %Acceleration in Cracow, cm/s
sumOf2G = plus  + (-minus);
avr = sumOf2G/2;
gain = 2*g/sumOf2G;
offset = (avr - plus);
end

