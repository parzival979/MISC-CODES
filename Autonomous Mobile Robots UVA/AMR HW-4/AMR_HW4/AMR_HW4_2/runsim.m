clear;
close all;

% need to add the path to the utils folders
addpath('/Users/parzival979/Documents/Assignments/AMR/AMR HW-4/AMR_HW4/AMR_HW4_2/utils');
addpath('trajectories');

controlhandle = @controller;

% Choose which trajectory you want to test with by uncommenting that line
trajhandle = @traj_line;
% trajhandle = @traj_sine;
% trajhandle = @traj_step;
% trajhandle = @traj_diamond;

[t, state] = simulation_2d(controlhandle, trajhandle);
