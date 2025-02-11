% Programmed By Sravanth Chowdary Potluri und5uv
clear; clc; close all;

workspace_size = 200;   
delta_max = pi / 4;      
v_max = 5;              
L = 2.5;                 
dt = 0.1;                
t_max = 100;             

x_initial = 100;
y_initial = 100;
theta_initial = rand() * 2 * pi + pi/6;

goal_x = rand() * workspace_size;
goal_y = rand() * workspace_size;

v = 0;        
delta = 0;    

time = 0:dt:t_max;
N = length(time);
x = zeros(1, N);
y = zeros(1, N);
theta = zeros(1, N);
v_history = zeros(1, N);
delta_history = zeros(1, N);

x(1) = x_initial;
y(1) = y_initial;
theta(1) = theta_initial;

for i = 1:N-1
    distance = sqrt((goal_x - x(i))^2 + (goal_y - y(i))^2);
    
    if distance < 0.001
        v = 0;
        x(i+1:end) = x(i);
        y(i+1:end) = y(i);
        theta(i+1:end) = theta(i);
        v_history(i+1:end) = 0;
        delta_history(i+1:end) = 0;
        break;
    end
    
    desired_theta = atan2(goal_y - y(i), goal_x - x(i));
    heading_error = wrapToPi(desired_theta - theta(i));
    
    Kp = 1;
    delta = Kp * heading_error;
    
    delta = max(-delta_max, min(delta, delta_max));
    
    k_v = 1;
    v_desired  = k_v * distance * dt;
    v_desired = min(v_desired, v_max);
    v_error = v_desired - v;
    v = v + v_error * dt;
    
    x(i+1) = x(i) + v * cos(theta(i)) * dt;
    y(i+1) = y(i) + v * sin(theta(i)) * dt;
    theta(i+1) = theta(i) + (v / L) * tan(delta) * dt;
    
    v_history(i+1) = v;
    delta_history(i+1) = delta;

end

time = time(1:i);
x = x(1:i);
y = y(1:i);
theta = theta(1:i);
v_history = v_history(1:i);
delta_history = delta_history(1:i);

figure;
plot(x, y, 'b-', 'LineWidth', 2);
hold on;
plot(goal_x, goal_y, 'ro', 'MarkerFaceColor', 'r');
plot(x_initial, y_initial, 'go', 'MarkerFaceColor', 'g');
xlabel('X Position (m)');
ylabel('Y Position (m)');
title('Robot Trajectory: Go to Goal');
legend('Trajectory', 'Goal', 'Start');
grid on;
axis equal;
axis([0 workspace_size 0 workspace_size]);

figure;
subplot(2,1,1);
plot(time, x, 'b-', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('X Position (m)');
title('X Position Over Time');
grid on;

subplot(2,1,2);
plot(time, y, 'r-', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('Y Position (m)');
title('Y Position Over Time');
grid on;

figure;
subplot(2,1,1);
plot(time, v_history, 'k-', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('Linear Velocity (m/s)');
title('Linear Velocity Over Time');
grid on;

subplot(2,1,2);
plot(time, delta_history, 'm-', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('Steering Angle (rad)');
title('Steering Angle Over Time');
grid on;