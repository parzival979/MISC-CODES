% Programmed By Sravanth Chowdary Potluri und5uv

x_range = 0:1:100;
y_range = 0:1:100;
[X, Y] = meshgrid(x_range, y_range);

q_goal = [80, 20];
K_att = 1;

U_att = 0.5 * K_att * ((X - q_goal(1)).^2 + (Y - q_goal(2)).^2);

figure;
surf(X, Y, U_att);
title('Attractive Potential Field');
xlabel('X (meters)');
ylabel('Y (meters)');
zlabel('Potential');
shading interp;
colormap jet;
colorbar;