% Programmed By Sravanth Chowdary Potluri und5uv

function [robot] = RectangularRobot(x, y, theta)
    half_width = 5;
    half_height = 2.5;
    shape = [ ...
        -half_width, -half_height;  
         half_width, -half_height;  
         half_width,  half_height;  
        -half_width,  half_height;
        -half_width, -half_height]; 

    T = [cos(theta), -sin(theta), x; ...
         sin(theta),  cos(theta), y; ...
               0    ,       0   , 1];

    num_points = size(shape, 1);
    shape_homogeneous = [shape, ones(num_points, 1)]';

    robot_homogeneous = T * shape_homogeneous;

    robot = robot_homogeneous(1:2, :)';

end