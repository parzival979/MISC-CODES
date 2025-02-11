% Programmed By Sravanth Chowdary Potluri und5uv

x_range = 0:1:100;
y_range = 0:1:100;
[X, Y] = meshgrid(x_range, y_range);

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
        % This is required so that the field doesn't extend to infinity in the centre
        if U_rep(i, j) > 1000
            U_rep(i, j) = 1000;
        end
    end
end

figure;
surf(X, Y, U_rep);
title('3D Repulsive Potential Field Centered at the Obstacle');
xlabel('X (meters)');
ylabel('Y (meters)');
zlabel('Potential');
shading interp;
colormap jet;
colorbar;