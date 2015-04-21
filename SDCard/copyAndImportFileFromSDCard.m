function [imuDataset] = copyAndImportFileFromSDCard(datasetFileName) 
    out = dir([datasetFileName,'.mat']);
    try
        if out.name 
            disp ('Plik o takiej nazwie istnieje, zmien nazwe.')
            imuDataset = '';
        else
            throw('normalna akcja');
        end
    catch err
        disp err
        copyfile('E:\\IMU.csv', pwd);
        disp ('Skopiowano plik IMU.csv do working directory.')
        
        imuDataset = importfile('IMU.CSV', 2, inf);
        kolStr = int2str(size(imuDataset,2));
        disp (['Zaimportowano ', kolStr , ' kolumn']);
        
        save(datasetFileName,'imuDataset');
        disp(['Stworzono plik', datasetFileName, '.mat']);
    end
end