% Programmed By Sravanth Chowdary Potluri und5uv
clear; clc; close all;

workspace_size = 200;    
delta_max = pi / 4;      
v_robot_max = 5;         
L = 2.5;                 
dt = 0.1;                
t_max = 300;             

circle_center = [100, 100];  
circle_radius = 75;          
v_target = 0.05;             

d_d = 10;  

x_initial = 100;
y_initial = 100;
theta_initial = rand() * 2 * pi;  

Kp_v = 0.1;  
Ki_v = 0.1;  
Kp_theta = 1;  

time = 0:dt:t_max;
N = length(time);
x_robot = zeros(1, N);
y_robot = zeros(1, N);
theta_robot = zeros(1, N);
v_robot_history = zeros(1, N);
delta_history = zeros(1, N);
distance_history = zeros(1, N);

x_robot(1) = x_initial;
y_robot(1) = y_initial;
theta_robot(1) = theta_initial;

theta_target = 0;  

e_integral = 0;

for i = 1:N-1
    theta_target = theta_target - v_target * dt;  
    theta_target = mod(theta_target, 2*pi);  
    
    x_target = circle_center(1) + circle_radius * cos(theta_target);
    y_target = circle_center(2) + circle_radius * sin(theta_target);
    
    distance_to_target = sqrt((x_target - x_robot(i))^2 + (y_target - y_robot(i))^2);
    
    e = distance_to_target - d_d;
    e_integral = e_integral + e * dt;  
    distance_history(i) = distance_to_target;  
    
    v_robot = Kp_v * e + Ki_v * e_integral;
    v_robot = min(v_robot, v_robot_max);  
    v_robot_history(i+1) = v_robot;  
    
    theta_d = atan2(y_target - y_robot(i), x_target - x_robot(i));
    
    heading_error = wrapToPi(theta_d - theta_robot(i));
    
    delta = Kp_theta * heading_error;
    delta = max(-delta_max, min(delta, delta_max));  
    delta_history(i+1) = delta;  
    
    x_robot(i+1) = x_robot(i) + v_robot * cos(theta_robot(i)) * dt;
    y_robot(i+1) = y_robot(i) + v_robot * sin(theta_robot(i)) * dt;
    theta_robot(i+1) = theta_robot(i) + (v_robot / L) * tan(delta) * dt;
    
    theta_robot(i+1) = wrapToPi(theta_robot(i+1));
end

v_robot_history = v_robot_history(1:N-1);
delta_history = delta_history(1:N-1);
distance_history = distance_history(1:N-1);

figure;
hold on;
grid on;
axis equal;
axis([0 workspace_size 0 workspace_size]);
xlabel('X Position (m)');
ylabel('Y Position (m)');
title('Robot Following a Moving Point Along a Circle');

theta_circle = linspace(0, 2*pi, 360);
x_circle = circle_center(1) + circle_radius * cos(theta_circle);
y_circle = circle_center(2) + circle_radius * sin(theta_circle);
plot(x_circle, y_circle, 'k--', 'LineWidth', 1.5);

plot(x_robot, y_robot, 'b-', 'LineWidth', 2);

plot(x_initial, y_initial, 'go', 'MarkerFaceColor', 'g');

legend('show');

figure;
subplot(2,1,1);
plot(time, x_robot, 'b-', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('X Position (m)');
title('Robot X Position Over Time');
grid on;

subplot(2,1,2);
plot(time, y_robot, 'r-', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('Y Position (m)');
title('Robot Y Position Over Time');
grid on;

figure;
plot(time(1:N-1), v_robot_history, 'k-', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('Velocity (m/s)');
title('Robot Velocity Over Time');
grid on;

figure;
plot(time(1:N-1), distance_history, 'k-', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('Distance to Target (m)');
title('Distance Between Robot and Moving Target Over Time');
grid on;