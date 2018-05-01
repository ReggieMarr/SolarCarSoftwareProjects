%% Import the data
[~, ~, raw0_0] = xlsread('Drive_Cycles_jan_2018.xlsx','Sheet1','D2:F44');
[~, ~, raw0_1] = xlsread('Drive_Cycles_jan_2018.xlsx','Sheet1','J2:J44');
raw = [raw0_0,raw0_1];
raw(cellfun(@(x) ~isempty(x) && isnumeric(x) && isnan(x),raw)) = {''};

%% Exclude rows with non-numeric cells
I = ~all(cellfun(@(x) (isnumeric(x) || islogical(x)) && ~isnan(x),raw),2); % Find rows with non-numeric cells
raw(I,:) = [];

%% Create output variable
data = reshape([raw{:}],size(raw));

%% Allocate imported array to column variable names
altitudem = data(:,1);
NetDistancemiles = data(:,2);
Distancemiles = data(:,3);
HorizontalGravityForce = data(:,4);

%% Clear temporary variables
clearvars data raw I;
%% Programmable Constants

MASS=250;%kg
FRICTION_COEFF=0.02;
DRAG_COEFF=0.2;
DENSITY=1.164;
EMOTOR_EFF=0.945;
C_RATING=15.9;%Ah
PACK_VOLTAGE=255.5;%V
MAX_SPEED=100/1.60934;%100kph in mph
WARNING_LIGHT=0.15;%if expected completion time is within x%, warning light will be trigered 

%% Parameters for Model
Distancem=Distancemiles*1609.34;%length of each segment in meters
len=length(Distancemiles);
total_distmiles=NetDistancemiles(len)+Distancemiles(len);%total distance (miles) of day

%To get total energy req the following are combined in model
energySeg_noDrag=zeros(len,1);%energy req for each segment ignoring drag
energyTotal_noDrag=zeros(len,1);%Total energy req for all subsequent segments
mult_velsq_ToDragEnergy=DENSITY*DRAG_COEFF*1000*1.60934^3/(2*3.6^2);%multiply by velocity squared to get drag force 

%To get power req the following are combined in model
mult_velcubed_ToPower=DENSITY*DRAG_COEFF*1.60934^3/(2*3.6^3*EMOTOR_EFF);%multiply by velocity cubed to get power
mult_vel_ToPower=zeros(len,1);


energySeg_noDrag(len)=MASS*9.8*altitudem(len)+MASS*9.8*FRICTION_COEFF*Distancem(len);%gravitational and work due to friction

for i=len-1:-1:1
    energyTotal_noDrag(i)=energyTotal_noDrag(i+1)+energySeg_noDrag(i+1);
    energySeg_noDrag(i)=MASS*9.8*altitudem(i)+MASS*9.8*FRICTION_COEFF*Distancem(i);%gravitational and work due to friction
end

%convert to watt-hour
energyTotal_noDrag=energyTotal_noDrag/(3600*EMOTOR_EFF);
energySeg_noDrag=energySeg_noDrag/(3600*EMOTOR_EFF);


for i=1:len
    mult_vel_ToPower(i)=MASS*9.8*FRICTION_COEFF+HorizontalGravityForce(i);
end

mult_vel_ToPower = mult_vel_ToPower*1.60934/(3.6*EMOTOR_EFF);%convert to Watts and account for motor efficiency



