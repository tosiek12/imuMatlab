%% Resutls of experiments 2G
ADXL345_2G_FACTOR = 3.9/100;
factor = ADXL345_2G_FACTOR;
x = [29999,-72,-423;
    -31422,-2140,-528].*factor;
y = [-1709,29684,-36;
    291,-31678,-665].*factor;
z = [-433,-1368,30182;
    -901,-1741,-31105].*factor;
%% Resutls of experiments 4G
ADXL345_4G_FACTOR = 7.8/100;
factor = ADXL345_4G_FACTOR;
x = [14959,-4,-199;
    -15731,-895,-2].*factor;
y = [-825,14832,-147;
    2,-15774,-344].*factor;
z = [-217,-645,15097;
    -871,-544,-15472].*factor;

%% Results dom 2g
factor = 1;
x = [246,0,0;
    -257,0,0];
y = [0,240,0;
    0,-260,0];
z = [0,0,250;
    0,0,-251];

%% compute gains, and offsets:
clc
data = {x,y,z};
PlusMinusAllAxis = {[x(1,1), x(2,1)], [y(1,2), y(2,2)], [z(1,3), z(2,3)]};
it = 1;
format bank ; format compact;
for element = PlusMinusAllAxis 
    [gain, offset] = computeGainAndOffset(element{1});
    fprintf('%% %% %% %% %% %% %% %% \n');
    fprintf('Axis %d: Gain: %.2f, Offset: %.2f\n', it, gain,offset);
    fprintf('Before:\n'); data{it}
    fprintf('After:\n'); data{it}*gain + offset
    fprintf('%% %% %% %% %% %% %% %% \n');
    it = it +1;
end
fprintf('wynik = gain*(measurement + offset)\n');
format short



