% Programmed By Sravanth Chowdary Potluri und5uv
clear; clc; close all;

workspace_size = 200;    
delta_max = pi / 4;      
v = 3;                   
L = 2.5;                 
dt = 0.1;                
t_max = 100;             

m = rand() * 1;       
b = rand() * 100;     

x_initial = 100;
y_initial = 100;
theta_initial = rand() * 2 * pi;  

d_desired = 10;  

time = 0:dt:t_max;
N = length(time);
x = zeros(1, N);
y = zeros(1, N);
theta = zeros(1, N);
delta_history = zeros(1, N);
distance_history = zeros(1, N);

x(1) = x_initial;
y(1) = y_initial;
theta(1) = theta_initial;

Kt = 0.01;  
Kh = 1; 

A = -m;
B = 1;
C = -b;

robot_length = 5;  
robot_width = 3;   

figure;
hold on;
grid on;
axis equal;
axis([0 workspace_size 0 workspace_size]);
xlabel('X Position (m)');
ylabel('Y Position (m)');
title('Robot Following a Line at a Constant Distance');

x_line = 0:1:workspace_size;
y_line = m * x_line + b;
plot(x_line, y_line, 'k-', 'LineWidth', 2);

h_robot = patch('XData', [], 'YData', [], 'FaceColor', 'b');
h_trail = plot(x(1), y(1), 'b-', 'LineWidth', 2);

plot(x_initial, y_initial, 'go', 'MarkerFaceColor', 'g');

for i = 1:N-1
    distance = A * x(i) + B * y(i) + C / sqrt(A^2 + B^2);
    distance_error = distance - d_desired;
    distance_history(i) = distance;

    theta_d = atan(-A/B);
    
    delta = -Kt * distance_error + Kh * (theta_d - theta(i));

    delta = max(-delta_max, min(delta, delta_max));
    delta_history(i) = delta;
    
    x(i+1) = x(i) + v * cos(theta(i)) * dt;
    y(i+1) = y(i) + v * sin(theta(i)) * dt;
    theta(i+1) = theta(i) + (v / L) * tan(delta) * dt;
    
    theta(i+1) = wrapToPi(theta(i+1));
    
    R = [cos(theta(i)), -sin(theta(i)); sin(theta(i)), cos(theta(i))];  
    robot_shape = [-robot_length/2, -robot_width/2;
                    robot_length/2, -robot_width/2;
                    robot_length/2,  robot_width/2;
                   -robot_length/2,  robot_width/2]';  
    
    robot_transformed = R * robot_shape;
    robot_transformed(1,:) = robot_transformed(1,:) + x(i);  
    robot_transformed(2,:) = robot_transformed(2,:) + y(i);  
    
    set(h_robot, 'XData', robot_transformed(1,:), 'YData', robot_transformed(2,:));
    
    set(h_trail, 'XData', x(1:i), 'YData', y(1:i));  
    
    pause(0.05);

end

distance_history = distance_history(1:N-1);
delta_history = delta_history(1:N-1);

plot(x, y, 'b-', 'LineWidth', 2);
legend('Line', 'Start', 'Trajectory');

figure;
plot(time(1:N-1), distance_history, 'r-', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('Distance to Line (m)');
title('Relative Distance Between Robot and Line Over Time');
grid on;