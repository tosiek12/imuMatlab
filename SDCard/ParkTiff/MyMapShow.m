[park, refmat, bbox] = geotiffread('parkTiff');
[park, R] = geotiffread('parkTiff');

figure(1);
mapshow(park,R);
axis image off;
lat_y = IMU.latG;
long_x = IMU.lonG;
% figure(2);
% parkf= double(park);
% geoshow(parkf, refmat,'DisplayType','surface');