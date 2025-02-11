% Programmed By Sravanth Chowdary Potluri und5uv
clear; clc; close all;

workspace_size = 200;    
delta_max = pi / 4;      
v_max = 5;               
v_ref = 3;               
L = 2.5;                 
dt = 0.1;                
t_max = 300;             

x_initial = rand()*200;
y_initial = rand()*200;
theta_initial = rand() * 2 * pi;  

num_waypoints = 3;
waypoints = rand(num_waypoints, 2) * workspace_size;

x = x_initial;
y = y_initial;
theta = theta_initial;
v = 0;          
delta = 0;      

time = 0:dt:t_max;
N = length(time);
x_history = zeros(1, N);
y_history = zeros(1, N);
theta_history = zeros(1, N);
v_history = zeros(1, N);
delta_history = zeros(1, N);

Kp_v = 0.4;    
Ki_v = 0.5;    
Kd_v = 0;      

v_error_integral = 0;
v_error_previous = 0;

Kp_delta = 1;

current_waypoint_index = 1;
goal_threshold = 1.0;  

robot_length = 5;  
robot_width = 3;   

figure;
hold on;
axis equal;
grid on;
axis([0 workspace_size 0 workspace_size]);
xlabel('X Position (m)');
ylabel('Y Position (m)');
title('Robot Trajectory with Cruise Controller');
plot(waypoints(:,1), waypoints(:,2), 'ro', 'MarkerFaceColor', 'r');
plot(x_initial, y_initial, 'go', 'MarkerFaceColor', 'g');

h_robot = patch('XData', [], 'YData', [], 'FaceColor', 'b');
h_trail = plot(x, y, 'b-', 'LineWidth', 2);

for i = 1:N
    t = time(i);
    
    if current_waypoint_index > num_waypoints
        v = 0;
        delta = 0;
        x_history(i:end) = x;
        y_history(i:end) = y;
        theta_history(i:end) = theta;
        v_history(i:end) = v;
        delta_history(i:end) = delta;
        break;
    end
    
    goal_x = waypoints(current_waypoint_index, 1);
    goal_y = waypoints(current_waypoint_index, 2);
    
    distance = sqrt((goal_x - x)^2 + (goal_y - y)^2);
    
    if distance < goal_threshold
        current_waypoint_index = current_waypoint_index + 1;
    end
    
    desired_theta = atan2(goal_y - y, goal_x - x);
    
    heading_error = wrapToPi(desired_theta - theta);
    
    delta = Kp_delta * heading_error;
    
    delta = max(-delta_max, min(delta, delta_max));
    
    v_error = v_ref - v;
    v_error_integral = v_error_integral + v_error * dt;
    v_error_derivative = (v_error - v_error_previous) / dt;
    u = Kp_v * v_error + Ki_v * v_error_integral + Kd_v * v_error_derivative;
    v_error_previous = v_error;
    
    v = v + u - 0.01 * v;
    
    v = max(0, min(v, v_max));
    
    x = x + v * cos(theta) * dt;
    y = y + v * sin(theta) * dt;
    theta = theta + (v / L) * tan(delta) * dt;
    
    x_history(i) = x;
    y_history(i) = y;
    theta_history(i) = theta;
    v_history(i+1) = v;
    delta_history(i) = delta;
    
    R = [cos(theta), -sin(theta); sin(theta), cos(theta)];
    robot_shape = [-robot_length/2, -robot_width/2;
                    robot_length/2, -robot_width/2;
                    robot_length/2,  robot_width/2;
                   -robot_length/2,  robot_width/2]';
    
    robot_transformed = R * robot_shape;
    robot_transformed(1,:) = robot_transformed(1,:) + x;
    robot_transformed(2,:) = robot_transformed(2,:) + y;
    
    set(h_robot, 'XData', robot_transformed(1,:), 'YData', robot_transformed(2,:));
    
    set(h_trail, 'XData', x_history(1:i), 'YData', y_history(1:i));  
    
    pause(0.05);
end

time = time(1:i);
x_history = x_history(1:i);
y_history = y_history(1:i);
theta_history = theta_history(1:i);
v_history = v_history(1:i);
delta_history = delta_history(1:i);

plot(x_history, y_history, 'b-', 'LineWidth', 2);
legend('Waypoints', 'Start', 'Trajectory');

figure;
plot(time, v_history, 'k-', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('Linear Velocity (m/s)');
title('Linear Velocity Over Time');
grid on;