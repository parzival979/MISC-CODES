% Programmed By Sravanth Chowdary Potluri und5uv

clear; clc; close all;

workspace_size = 100;
dt = 0.1;
t_max = 50;
time = 0:dt:t_max;
N = length(time);

x_initial = 50;
y_initial = 50;
theta_initial = rand() * 2 * pi;
goal_distance = 50;

goal_x = x_initial + goal_distance * cos(theta_initial);
goal_y = y_initial + goal_distance * sin(theta_initial);

goal_x = max(0, min(goal_x, workspace_size));
goal_y = max(0, min(goal_y, workspace_size));

v_const = 5;

x_true = zeros(1, N);
y_true = zeros(1, N);
vx_true = zeros(1, N);
vy_true = zeros(1, N);

x_true(1) = x_initial;
y_true(1) = y_initial;

direction = atan2(goal_y - y_initial, goal_x - x_initial);
vx_true(1) = v_const * cos(direction);
vy_true(1) = v_const * sin(direction);

R1 = diag([6, 6]);
R2 = diag([4, 4]);

z1 = zeros(2, N);
z2 = zeros(2, N);

x_est = zeros(4, N);
P_est = zeros(4, 4, N);

x_est(:,1) = [x_initial; y_initial; 0; 0];
P_est(:,:,1) = eye(4) * 10;

A = [1, 0, dt,  0;
     0, 1,  0, dt;
     0, 0,  1,  0;
     0, 0,  0,  1];

B = [0,  0;
     0,  0;
     dt, 0;
     0, dt];

Q = diag([0.01, 0.01, 0.01, 0.01]);

H = [1, 0, 0, 0;
     0, 1, 0, 0];

u = zeros(2, N);

for k = 2:N
    distance_to_goal = sqrt((goal_x - x_true(k-1))^2 + (goal_y - y_true(k-1))^2);
    
    if distance_to_goal < 0.1
        vx_true(k-1) = 0;
        vy_true(k-1) = 0;
        x_true(k:end) = x_true(k-1);
        y_true(k:end) = y_true(k-1);
        x_est(:,k:end) = repmat(x_est(:,k-1), 1, N - k + 1);
        break;
    end
    
    theta_desired = atan2(goal_y - y_true(k-1), goal_x - x_true(k-1));
    vx_true(k) = v_const * cos(theta_desired);
    vy_true(k) = v_const * sin(theta_desired);
    x_true(k) = x_true(k-1) + vx_true(k) * dt;
    y_true(k) = y_true(k-1) + vy_true(k) * dt;
    
    u(:,k) = ([vx_true(k); vy_true(k)] - [vx_true(k-1); vy_true(k-1)]) / dt;

    u_noisy = u(:,k) + randn(2,1);
    
    z1(:,k) = H * [x_true(k); y_true(k); vx_true(k); vy_true(k)] + sqrt(R1) * randn(2,1);
    z2(:,k) = H * [x_true(k); y_true(k); vx_true(k); vy_true(k)] + sqrt(R2) * randn(2,1);
    
    x_pred = A * x_est(:,k-1) + B * u_noisy;
    P_pred = A * P_est(:,:,k-1) * A' + Q;
    
    z = [z1(:,k); z2(:,k)];
    H_combined = [H; H];
    R_combined = blkdiag(R1, R2);
    
    S = H_combined * P_pred * H_combined' + R_combined;
    K = P_pred * H_combined' / S;
    
    y_meas = z - H_combined * x_pred;
    x_est(:,k) = x_pred + K * y_meas;
    P_est(:,:,k) = (eye(4) - K * H_combined) * P_pred;
end

time = time(1:k);
x_true = x_true(1:k);
y_true = y_true(1:k);
vx_true = vx_true(1:k);
vy_true = vy_true(1:k);
x_est = x_est(:,1:k);
z1 = z1(:,1:k);
z2 = z2(:,1:k);

distance_to_goal = sqrt((x_est(1,:) - goal_x).^2 + (x_est(2,:) - goal_y).^2);
linear_velocity = sqrt(x_est(3,:).^2 + x_est(4,:).^2);

figure;
plot(x_true, y_true, 'g-', 'LineWidth', 1.5); hold on;
plot(z1(1,:), z1(2,:), 'rx');
plot(z2(1,:), z2(2,:), 'bx');
plot(x_est(1,:), x_est(2,:), 'k-', 'LineWidth', 1.5);
plot(goal_x, goal_y, 'go', 'MarkerSize', 10, 'MarkerFaceColor', 'g');
legend('True Path', 'Sensor 1 Measurements', 'Sensor 2 Measurements', 'Kalman Filter Estimate', 'Goal');
xlabel('X Position (m)');
ylabel('Y Position (m)');
title('Robot Position Estimation');
grid on;
axis equal;

figure;
plot(time, linear_velocity, 'b-', 'LineWidth', 1.5); hold on;
plot(time, v_const*ones(size(time)), 'r--', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('Linear Velocity (m/s)');
title('Estimated Linear Velocity Over Time');
legend('Estimated Velocity', 'Reference Velocity');
grid on;

figure;
plot(time, distance_to_goal, 'r-', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('Distance to Goal (m)');
title('Distance to Goal Over Time');
grid on;

figure;
subplot(2,1,1);
plot(time, z1(1,:), 'r.', time, z2(1,:), 'b.', time, x_est(1,:), 'k-', 'LineWidth', 1.5);
legend('Sensor 1 X', 'Sensor 2 X', 'Estimated X');
xlabel('Time (s)');
ylabel('X Position (m)');
title('X Position Measurements and Estimates');
grid on;

subplot(2,1,2);
plot(time, z1(2,:), 'r.', time, z2(2,:), 'b.', time, x_est(2,:), 'k-', 'LineWidth', 1.5);
legend('Sensor 1 Y', 'Sensor 2 Y', 'Estimated Y');
xlabel('Time (s)');
ylabel('Y Position (m)');
title('Y Position Measurements and Estimates');
grid on;

figure;
subplot(2,1,1);
plot(time, vx_true, 'g-', time, x_est(3,:), 'k-', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('Velocity in X (m/s)');
title('True and Estimated Velocity in X');
legend('True Vx', 'Estimated Vx');
grid on;

subplot(2,1,2);
plot(time, vy_true, 'g-', time, x_est(4,:), 'k-', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('Velocity in Y (m/s)');
title('True and Estimated Velocity in Y');
legend('True Vy', 'Estimated Vy');
grid on;

figure;
axis([0 workspace_size 0 workspace_size]);
hold on; grid on; axis equal;
xlabel('X Position (m)');
ylabel('Y Position (m)');
title('Robot Moving from Start to Goal');

plot(goal_x, goal_y, 'go', 'MarkerSize', 10, 'MarkerFaceColor', 'g');

for kk = 1:5:length(time)
    cla;
    plot(goal_x, goal_y, 'go', 'MarkerSize', 10, 'MarkerFaceColor', 'g');
    plot(x_true(1:kk), y_true(1:kk), 'g-', 'LineWidth', 1.5);
    plot(z1(1,kk), z1(2,kk), 'rx', 'MarkerSize', 8);
    plot(z2(1,kk), z2(2,kk), 'bx', 'MarkerSize', 8);
    plot(x_est(1,kk), x_est(2,kk), 'ko', 'MarkerSize', 8, 'MarkerFaceColor', 'k');
    legend('Goal', 'True Path', 'Sensor 1', 'Sensor 2', 'Kalman Estimate');
    pause(0.05);
end