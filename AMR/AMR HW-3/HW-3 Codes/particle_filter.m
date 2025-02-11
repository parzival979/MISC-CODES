% Programmed By Sravanth Chowdary Potluri und5uv

clear; clc; close all;

workspace_size = 100;
num_landmarks = 6;
landmarks = [25, 25;
             25, 70;
             70, 25;
             70, 70;
             10, 40;
             80, 60];

num_particles = 1000;
num_steps = 10;
forward_motion = 1;
rotation_motion = 0.2;
motion_noise = 0.5;
measurement_noise_std = sqrt(8);

robot_true_pose = [workspace_size/2 + randn(), workspace_size/2 + randn(), 2*pi*rand()];
robot_true_poses = zeros(num_steps, 3);
robot_true_poses(1, :) = robot_true_pose;

robot_estimated_pose = [rand()*workspace_size, rand()*workspace_size, 2*pi*rand()];
robot_estimated_poses = zeros(num_steps, 3);
robot_estimated_poses(1, :) = robot_estimated_pose;

particles = zeros(num_particles, 3);
particles(:, 1) = rand(num_particles, 1) * workspace_size;
particles(:, 2) = rand(num_particles, 1) * workspace_size;
particles(:, 3) = rand(num_particles, 1) * 2 * pi;

particles_history = zeros(num_particles, 3, num_steps);
particles_history(:, :, 1) = particles;

weights = ones(num_particles, 1) / num_particles;

for t = 2:num_steps
    robot_true_pose(3) = robot_true_pose(3) + rotation_motion + randn() * motion_noise;
    robot_true_pose(3) = wrapToPi(robot_true_pose(3));
    robot_true_pose(1) = robot_true_pose(1) + (forward_motion + randn() * motion_noise) * cos(robot_true_pose(3));
    robot_true_pose(2) = robot_true_pose(2) + (forward_motion + randn() * motion_noise) * sin(robot_true_pose(3));
    robot_true_pose(1) = min(max(robot_true_pose(1), 0), workspace_size);
    robot_true_pose(2) = min(max(robot_true_pose(2), 0), workspace_size);
    robot_true_poses(t, :) = robot_true_pose;
    
    distances_true = sqrt((landmarks(:,1) - robot_true_pose(1)).^2 + (landmarks(:,2) - robot_true_pose(2)).^2);
    measurements = distances_true + randn(num_landmarks, 1) * measurement_noise_std;
    
    for i = 1:num_particles
        particles(i,3) = particles(i,3) + rotation_motion + randn() * motion_noise;
        particles(i,3) = wrapToPi(particles(i,3));
        particles(i,1) = particles(i,1) + (forward_motion + randn() * motion_noise) * cos(particles(i,3));
        particles(i,2) = particles(i,2) + (forward_motion + randn() * motion_noise) * sin(particles(i,3));
        particles(i,1) = min(max(particles(i,1), 0), workspace_size);
        particles(i,2) = min(max(particles(i,2), 0), workspace_size);
        
        distances_particle = sqrt((landmarks(:,1) - particles(i,1)).^2 + (landmarks(:,2) - particles(i,2)).^2);
        
        prob = normpdf(measurements, distances_particle, measurement_noise_std);
        weights(i) = prod(prob);
    end
    
    weights = weights / sum(weights);
    
    sin_sum = sum(sin(particles(:,3)) .* weights);
    cos_sum = sum(cos(particles(:,3)) .* weights);
    estimated_theta = atan2(sin_sum, cos_sum);
    robot_estimated_pose = [sum(particles(:,1) .* weights), sum(particles(:,2) .* weights), estimated_theta];
    robot_estimated_poses(t, :) = robot_estimated_pose;
    
    indices = resampleWheel(weights);
    particles = particles(indices, :);
    weights = ones(num_particles, 1) / num_particles;
    
    particles_history(:, :, t) = particles;
    
    disp(['Step ', num2str(t), ':']);
    disp(['Estimated Pose: x=', num2str(robot_estimated_pose(1)), ...
          ', y=', num2str(robot_estimated_pose(2)), ...
          ', theta=', num2str(robot_estimated_pose(3))]);
    position_error = norm(robot_true_pose(1:2) - robot_estimated_pose(1:2));
    orientation_error = abs(angdiff(robot_true_pose(3), robot_estimated_pose(3)));
    disp(['Position Error: ', num2str(position_error), ' meters']);
    disp(['Orientation Error: ', num2str(orientation_error), ' radians']);
    disp('----------------------------------------');
end

figure;
for t = 1:num_steps
    clf;
    hold on; grid on; axis equal;
    axis([0 workspace_size 0 workspace_size]);
    xlabel('X Position (m)');
    ylabel('Y Position (m)');
    title(['Particle Filter Localization - Step ', num2str(t)]);
    
    plot(landmarks(:,1), landmarks(:,2), 'kp', 'MarkerSize', 12, 'MarkerFaceColor', 'y');
    legend_entries = {'Landmarks'};
    
    scatter(particles_history(:,1,t), particles_history(:,2,t), 10, 'b', 'filled');
    legend_entries{end+1} = 'Particles';
    
    plot(robot_true_poses(t,1), robot_true_poses(t,2), 'go', 'MarkerSize', 10, 'MarkerFaceColor', 'g');
    legend_entries{end+1} = 'True Robot Position';
    
    plot(robot_estimated_poses(t,1), robot_estimated_poses(t,2), 'ro', 'MarkerSize', 8, 'MarkerFaceColor', 'r');
    legend_entries{end+1} = 'Estimated Position';
    
    legend(legend_entries);
    
    pause(0.5);
end

position_errors = sqrt((robot_true_poses(:,1) - robot_estimated_poses(:,1)).^2 + ...
                       (robot_true_poses(:,2) - robot_estimated_poses(:,2)).^2);
orientation_errors = abs(angdiff(robot_true_poses(:,3), robot_estimated_poses(:,3)));

figure;
subplot(2,1,1);
plot(1:num_steps, position_errors, 'r-o', 'LineWidth', 1.5);
xlabel('Time Step');
ylabel('Position Error (m)');
title('Position Estimation Error Over Time');
grid on;

subplot(2,1,2);
plot(1:num_steps, orientation_errors, 'b-o', 'LineWidth', 1.5);
xlabel('Time Step');
ylabel('Orientation Error (rad)');
title('Orientation Estimation Error Over Time');
grid on;

function indices = resampleWheel(weights)
    N = length(weights);
    indices = zeros(N, 1);
    max_weight = max(weights);
    index = randi(N);
    beta = 0;

    for i = 1:N
        beta = beta + rand() * 2 * max_weight;
        
        while weights(index) < beta
            beta = beta - weights(index);
            index = mod(index, N) + 1;
        end
        
        indices(i) = index;
    end
end

function delta = angdiff(theta1, theta2)
    delta = atan2(sin(theta1 - theta2), cos(theta1 - theta2));
end