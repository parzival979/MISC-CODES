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

figure;
contour(X, Y, U_total, 50);
hold on;
plot(obs_x, obs_y, 'k-', 'LineWidth', 2);
plot(q_start(1), q_start(2), 'go', 'MarkerFaceColor', 'g');
plot(q_goal(1), q_goal(2), 'ro', 'MarkerFaceColor', 'r');
title('Robot Navigation using Potential Fields');
xlabel('X (meters)');
ylabel('Y (meters)');
axis equal;

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
    
    plot(x_robot, y_robot, 'bo', 'MarkerFaceColor', 'b');
    drawnow;
    pause(0.01);
    
    dist_to_goal = sqrt((x_robot - q_goal(1))^2 + (y_robot - q_goal(2))^2);
    if dist_to_goal <= tol
        disp('Goal reached!');
        break;
    end
end

plot(trajectory_x, trajectory_y, 'r-', 'LineWidth', 2);
legend('Potential Field', 'Obstacle', 'Start', 'Goal', 'Robot Path');