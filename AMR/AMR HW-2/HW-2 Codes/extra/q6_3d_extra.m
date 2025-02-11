% Programmed By Sravanth Chowdary Potluri und5uv

x_range = 0:1:100;
y_range = 0:1:100;
[X, Y] = meshgrid(x_range, y_range);

q_goal = [80, 20];
K_att = 1;

U_att = 0.5 * K_att * ((X - q_goal(1)).^2 + (Y - q_goal(2)).^2);

obs_x = [30, 50, 50, 30, 30];
obs_y = [50, 50, 70, 70, 50];

K_rep = 10000;
D0 = 10;
max_potential = 10000;

U_rep = zeros(size(X));

xmin = min(obs_x);
xmax = max(obs_x);
ymin = min(obs_y);
ymax = max(obs_y);

for i = 1:size(X,1)
    for j = 1:size(X,2)
        x = X(i,j);
        y = Y(i,j);

        if (x >= xmin && x <= xmax) && (y >= ymin && y <= ymax)
            U_rep(i,j) = max_potential;
        else
            dx = max([xmin - x, 0, x - xmax]);
            dy = max([ymin - y, 0, y - ymax]);
            dist = sqrt(dx^2 + dy^2);

            if dist <= D0
                U_rep(i,j) = 0.5 * K_rep * (1/dist - 1/D0)^2;
            else
                U_rep(i,j) = 0;
            end
        end
    end
end

U_total = U_att + U_rep;

delta_max = pi / 4;
v_max = 5;
L = 2.5;
dt = 0.1;
t_max = 100;

x_robot = 10;
y_robot = 80;
theta_robot = 0;

v = 0;
delta = 0;

robot_length = 5;
robot_width = 3;

time = 0:dt:t_max;
N = length(time);

x_history = zeros(1, N);
y_history = zeros(1, N);
theta_history = zeros(1, N);
v_history = zeros(1, N);
delta_history = zeros(1, N);

x_history(1) = x_robot;
y_history(1) = y_robot;
theta_history(1) = theta_robot;

dx_grid = x_range(2) - x_range(1);
dy_grid = y_range(2) - y_range(1);
[dU_dx, dU_dy] = gradient(U_total, dx_grid, dy_grid);

F_x = -dU_dx;
F_y = -dU_dy;

figure;
surf(X, Y, U_total);
hold on;
plot3(obs_x, obs_y, max(U_total(:))*ones(size(obs_x)), 'k-', 'LineWidth', 2);
plot3(x_robot, y_robot, 0, 'go', 'MarkerFaceColor', 'g', 'MarkerSize', 8);
plot3(q_goal(1), q_goal(2), 0, 'yo', 'MarkerFaceColor', 'y', 'MarkerSize', 8);
title('3D Non-Holonomic Robot Navigation using Potential Fields');
xlabel('X (meters)');
ylabel('Y (meters)');
zlabel('Potential');
axis tight;
shading interp;
colormap jet;
colorbar;

h_robot = patch('XData', [], 'YData', [], 'ZData', [], 'FaceColor', 'red');

for i = 1:N-1
    F_x_robot = interp2(X, Y, F_x, x_robot, y_robot);
    F_y_robot = interp2(X, Y, F_y, x_robot, y_robot);
    
    desired_theta = atan2(F_y_robot, F_x_robot);
    
    heading_error = wrapToPi(desired_theta - theta_robot);
    
    Kp_delta = 2;
    delta = Kp_delta * heading_error;
    delta = max(-delta_max, min(delta, delta_max));
    delta_history(i) = delta;
    
    distance = sqrt((q_goal(1) - x_robot)^2 + (q_goal(2) - y_robot)^2);
    Kp_v = 1;
    v_desired = Kp_v * distance;
    v = min(v_desired, v_max);
    v_history(i) = v;
    
    x_robot = x_robot + v * cos(theta_robot) * dt;
    y_robot = y_robot + v * sin(theta_robot) * dt;
    theta_robot = theta_robot + (v / L) * tan(delta) * dt;
    
    x_history(i+1) = x_robot;
    y_history(i+1) = y_robot;
    theta_history(i+1) = theta_robot;
    
    R = [cos(theta_robot), -sin(theta_robot); sin(theta_robot), cos(theta_robot)];
    robot_shape = [-robot_length/2, -robot_width/2;
                    robot_length/2, -robot_width/2;
                    robot_length/2,  robot_width/2;
                   -robot_length/2,  robot_width/2]';

    robot_transformed = R * robot_shape;
    robot_transformed(1,:) = robot_transformed(1,:) + x_robot;
    robot_transformed(2,:) = robot_transformed(2,:) + y_robot;
    Z = interp2(X, Y, U_total, robot_transformed(1,:), robot_transformed(2,:));

    set(h_robot, 'XData', robot_transformed(1,:), 'YData', robot_transformed(2,:), 'ZData', Z);
    
    plot3(x_robot, y_robot, interp2(X, Y, U_total, x_robot, y_robot), 'ro', 'MarkerFaceColor', 'r');
    drawnow;
    pause(0.01);
    
    if distance <= 1
        disp('Goal reached!');
        break;
    end
    
    if x_robot < 0 || x_robot > 100 || y_robot < 0 || y_robot > 100
        disp('Robot is out of bounds!');
        break;
    end
end

plot3(x_history(1:i+1), y_history(1:i+1), interp2(X, Y, U_total, x_history(1:i+1), y_history(1:i+1)), 'b-', 'LineWidth', 2);
legend('Potential Field', 'Obstacle', 'Start', 'Goal', 'Robot Path');