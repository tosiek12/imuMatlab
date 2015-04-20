function [imuDatatset] = copyAndImportFileFromSDCard(datasetFileName) 
    imuDatatset = importfile('E:\\IMU.CSV', 2, inf);
    copyfile('E:\\IMU.csv',pwd);
    save(datasetFileName,'imuDatatset');
end