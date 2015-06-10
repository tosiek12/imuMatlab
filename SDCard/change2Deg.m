function [lat_yOutput, long_xOutput] = change2Deg (latInput, longInput)
    sek = mod([latInput, longInput], 10000);
    tempResult = ([latInput, longInput]-sek)/10000;
    latInput = tempResult(:,1);
    longInput = tempResult(:,2);
    
    min = mod([latInput, longInput], 100);
    tempResult = ([latInput, longInput]-min)/100;
    latInput = tempResult(:,1);
    longInput = tempResult(:,2);
    
    deg = mod([latInput, longInput], 100);
    
%     tempResult = deg+(min/0.6)/100+(sek/0.6)/1000000;
    tempResult = deg+(min/0.6)/100+(sek)/1000000;

    lat_yOutput = tempResult(:,1);
    long_xOutput = tempResult(:,2);
    
    %     %50 05 1880
%     lat_yOutput = latInput/1000000;
%     long_xOutput = longInput/1000000;
end
