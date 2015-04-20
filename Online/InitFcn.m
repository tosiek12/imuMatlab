% *************************************************
% Constants
% *************************************************
TOKEN = 238;
BAUDERATE = 115200;
INPUTBUFFER = 512;
START = ['S'];
STOP = ['E']; % 0XFF, 0X09, 0X03
REQUEST = ['R'];


%% Create a serial object
scanPort();
board = serial('COM3', 'BaudRate', BAUDERATE, 'DataBits',8); 
% Set serial port buffer 
set(board,'InputBufferSize', INPUTBUFFER); 
set(board,'Timeout',10);

% board.BytesAvailableFcnCount = FRAMESIZE;
% board.BytesAvailableFcnMode = 'byte';
% board.BytesAvailableFcn = {@byteAvailCallback};

fopen(board);
% Send the Start command to the radio
fwrite(board,START,'uint8');