% Programmed By Sravanth Chowdary Potluri und5uv

x_range = 0:1:100;
y_range = 0:1:100;
[X, Y] = meshgrid(x_range, y_range);

q_goal = [80, 20];
K_att = 1;

U_att = 0.5 * K_att * ((X - q_goal(1)).^2 + (Y - q_goal(2)).^2);

obs_x = [30, 50, 50, 30, 30];
obs_y = [50, 50, 70, 70, 50];

obs_center = [(30 + 50) / 2, (50 + 70) / 2];

K_rep = 1000000;
D0 = 20;

U_rep = zeros(size(X));

threshold = 0.5;

for i = 1:size(X, 1)
    for j = 1:size(X, 2)
        x = X(i, j);
        y = Y(i, j);
        
        dist_to_obstacle = sqrt((x - obs_center(1))^2 + (y - obs_center(2))^2);
        dist_to_obstacle = max(dist_to_obstacle, threshold);
        
        if dist_to_obstacle <= D0
            U_rep(i, j) = 0.5 * K_rep * (1 / dist_to_obstacle - 1 / D0)^2;
        else
            U_rep(i, j) = 0;
        end

        % set a threshold for the repulsive potential field
        if U_rep(i, j) > 1000
            U_rep(i, j) = 1000;
        end

    end
end

U_total = U_att + U_rep;

q_start = [10, 80];
q_goal = [80, 20];
x_robot = q_start(1);
y_robot = q_start(2);

Vmax = 3;

dt = 0.1;
max_iters = 1000;
tol = 1;

v_x = 0;
v_y = 0;

dx = x_range(2) - x_range(1);
dy = y_range(2) - y_range(1);
[dU_dx, dU_dy] = gradient(U_total, dx, dy);

F_x = -dU_dx;
F_y = -dU_dy;

trajectory_x = x_robot;
trajectory_y = y_robot;
trajectory_potential = U_total(round(x_robot), round(y_robot));

figure;
surf(X, Y, U_total);
hold on;
plot3(obs_x, obs_y, max(U_total(:))*ones(size(obs_x)), 'k-', 'LineWidth', 2);
plot3(q_start(1), q_start(2), 0, 'go', 'MarkerFaceColor', 'g', 'MarkerSize', 8);
plot3(q_goal(1), q_goal(2), 0, 'yo', 'MarkerFaceColor', 'y', 'MarkerSize', 8);
title('3D Robot Navigation using Potential Fields');
xlabel('X (meters)');
ylabel('Y (meters)');
zlabel('Potential');
axis tight;
shading interp;
colormap jet;
colorbar;

for iter = 1:max_iters
    F_x_robot = interp2(X, Y, F_x, x_robot, y_robot);
    F_y_robot = interp2(X, Y, F_y, x_robot, y_robot);
    
    a_x = F_x_robot;
    a_y = F_y_robot;
    
    v_x = v_x + a_x * dt;
    v_y = v_y + a_y * dt;
    
    v_mag = sqrt(v_x^2 + v_y^2);
    if v_mag > Vmax
        v_x = (v_x / v_mag) * Vmax;
        v_y = (v_y / v_mag) * Vmax;
    end
    
    x_robot = x_robot + v_x * dt;
    y_robot = y_robot + v_y * dt;
    
    trajectory_x(end+1) = x_robot;
    trajectory_y(end+1) = y_robot;
    trajectory_potential(end+1) = interp2(X, Y, U_total, x_robot, y_robot);
    
    plot3(x_robot, y_robot, interp2(X, Y, U_total, x_robot, y_robot), 'ro', 'MarkerFaceColor', 'r');
    drawnow;
    pause(0.01);
    
    dist_to_goal = sqrt((x_robot - q_goal(1))^2 + (y_robot - q_goal(2))^2);
    if dist_to_goal <= tol
        disp('Goal reached!');
        break;
    end
end

plot3(trajectory_x, trajectory_y, trajectory_potential, 'r-', 'LineWidth', 2);
legend('Potential Field', 'Obstacle', 'Start', 'Goal', 'Robot Path');