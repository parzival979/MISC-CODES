% Programmed By Sravanth Chowdary Potluri und5uv

x_range = 0:1:100;
y_range = 0:1:100;
[X, Y] = meshgrid(x_range, y_range);

q_goal = [80, 20];
K_att = 1;

U_att = 0.5 * K_att * ((X - q_goal(1)).^2 + (Y - q_goal(2)).^2);

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
        if U_rep(i, j) > 10000
            U_rep(i, j) = 10000;
        end
    end
end

U_total = U_att + U_rep;

figure;
surf(X, Y, U_total);
title('Combined Potential Field');
xlabel('X (meters)');
ylabel('Y (meters)');
zlabel('Potential');
shading interp;
colormap jet;
colorbar;