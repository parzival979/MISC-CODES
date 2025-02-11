%% Move Robot Sample Code

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
% Code by: Nicola Bezzo (UVA)
% AMR 2024 
% Date: 09/11/2024
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear
close all
clc

%% Parameters

% Workspace Size
xlim([0 100])
ylim([0 100])

%Velocity (constant for this demo example) 
vel = 5;

%Steering angle
steering = pi/6; 

%Initialize a vector of positions for the robot
x=[]; 
y=[];

%% Robot Initial Pose

x(1) = 50;
y(1) = 50;

% Initial Orientation 
theta(1) = pi/3;

% Build Robot Model
robot = TriangularRobot(x,y,theta(1));

plot(robot(:,1),robot(:,2),'-');
xlim([0 100])
ylim([0 100])
    
%% Move Robot

%number of steps of the simualtion
nstep = 50;

%time step
dt = 0.1;

 
for i = 1:nstep
    
    %robot non-holonomic dynamics (as seen in class)
    x(i+1) = x(i) + vel * cos(theta(i)) * dt;
    y(i+1) = y(i) + vel * sin(theta(i)) * dt;
    theta(i+1) = theta(i) + steering * dt;
    
    robot = TriangularRobot(x(i),y(i),theta(i));
    plot(robot(:,1),robot(:,2),'-',x,y,'-');
    xlim([0 100])
    ylim([0 100])
    pause(0.01)
    
end
