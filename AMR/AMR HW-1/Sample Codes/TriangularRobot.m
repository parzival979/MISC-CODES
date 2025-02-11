%% Homogeneous Transformation

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
% Code by: Nicola Bezzo (UVA)
% AMR 2024 
% Date: 09/11/2024
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [robot] = TriangularRobot(x,y,theta)

center = [x y];

% Robot triangle shape

a = [0 -3];
b = [12 0];
c = [0 3];

% Rotation Matrix

rotmat = [cos(theta) -sin(theta); sin(theta) cos(theta)];

rota = (rotmat * (a'));
rotb = (rotmat * (b'));
rotc = (rotmat * (c'));

% Final Robot Configuration after transformation

robot1 = [rota(1) + center(1), rota(2) + center(2)];
robot2 = [rotb(1) + center(1), rotb(2) + center(2)];
robot3 = [rotc(1) + center(1), rotc(2) + center(2)];

robot = [robot1;robot2;robot3;robot1];
 
end
