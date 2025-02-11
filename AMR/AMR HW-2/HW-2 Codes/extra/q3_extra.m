% Programmed By Sravanth Chowdary Potluri und5uv

x_range = 0:1:100;
y_range = 0:1:100;
[X, Y] = meshgrid(x_range, y_range);

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

figure;
surf(X, Y, U_rep);
title('3D Repulsive Potential Field around Obstacle');
xlabel('X (meters)');
ylabel('Y (meters)');
zlabel('Potential');
shading interp;
colormap jet;
colorbar;