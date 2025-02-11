% Programmed By Sravanth Chowdary Potluri und5uv
clear; clc; close all;

workspace_size = 200;

x_initial = 100;
y_initial = 100;
theta_initial = rand() * 2 * pi;

robot_initial = RectangularRobot(x_initial, y_initial, theta_initial);

x_translate = 20;
y_translate = 30;
theta_rotate = pi / 6;

x_final = x_initial + x_translate;
y_final = y_initial + y_translate;
theta_final = theta_initial + theta_rotate;

robot_final = RectangularRobot(x_final, y_final, theta_final);

figure;
hold on;
axis equal;
grid on;
axis([0 workspace_size 0 workspace_size]);
xlabel('X Position (m)');
ylabel('Y Position (m)');
title('Homogeneous Transformation of a Rectangular Robot');

plot(robot_initial(:,1), robot_initial(:,2), 'b-', 'LineWidth', 2);
fill(robot_initial(:,1), robot_initial(:,2), 'b', 'FaceAlpha', 0.3);
plot(x_initial, y_initial, 'bo', 'MarkerFaceColor', 'b');
text(x_initial, y_initial, '  Initial Position', 'Color', 'b');

plot(robot_final(:,1), robot_final(:,2), 'r-', 'LineWidth', 2);
fill(robot_final(:,1), robot_final(:,2), 'r', 'FaceAlpha', 0.3);
plot(x_final, y_final, 'ro', 'MarkerFaceColor', 'r');
text(x_final, y_final, '  Final Position', 'Color', 'r');

legend('Initial Configuration', 'Final Configuration');
hold off;