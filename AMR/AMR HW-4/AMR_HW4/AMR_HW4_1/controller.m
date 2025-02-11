function [ u ] = pd_controller(~, s, s_des, params)
    %PD_CONTROLLER  PD controller for the height
    %
    %   s: 2x1 vector containing the current state [z; v_z]
    %   s_des: 2x1 vector containing desired state [z; v_z]
    %   params: robot parameters
    
    % Extract current states
    z = s(1);
    z_dot = s(2);
    
    % Extract desired states
    z_des = s_des(1);
    z_dot_des = s_des(2);
    
    % Desired acceleration set to zero since it was not provided in the assignment
    z_ddot_des = 0;
    
    % errors
    e = z_des - z;
    e_dot = z_dot_des - z_dot;
    
    % Control gains 
    Kp = 120;
    Kv = 20;
    
    u = params.mass * (z_ddot_des + Kp * e + Kv * e_dot + params.gravity);
    
    end