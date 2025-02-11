function [ u1, u2 ] = controller(~, state, des_state, params)
    %CONTROLLER  Controller for the planar quadrotor
%
%   state: The current state of the robot with the following fields:
%   state.pos = [y; z], state.vel = [y_dot; z_dot], state.rot = [phi],
%   state.omega = [phi_dot]
%
%   des_state: The desired states are:
%   des_state.pos = [y; z], des_state.vel = [y_dot; z_dot], des_state.acc =
%   [y_ddot; z_ddot]
%
%   params: robot parameters
    
    % current states
    y = state.pos(1);
    z = state.pos(2);
    y_dot = state.vel(1);
    z_dot = state.vel(2);
    phi = state.rot;
    phi_dot = state.omega;
    
    % desired states
    y_des = des_state.pos(1);
    z_des = des_state.pos(2);
    y_dot_des = des_state.vel(1);
    z_dot_des = des_state.vel(2);
    y_ddot_des = des_state.acc(1);
    z_ddot_des = des_state.acc(2);
    
    % Controller gains
    Kp_z = 80;      
    Kv_z = 20;      
    Kp_y = 10;      
    Kv_y = 5;       
    Kp_phi = 2000;  
    Kv_phi = 50;    
    
    
    z_c_ddot = z_ddot_des + Kv_z * (z_dot_des - z_dot) + Kp_z * (z_des - z);
    
    
    y_c_ddot = y_ddot_des + Kv_y * (y_dot_des - y_dot) + Kp_y * (y_des - y);
    
    
    phi_c = -(1 / params.gravity) * y_c_ddot;
    
    
    u1 = params.mass * (params.gravity + z_c_ddot);
    
    
    u2 = params.Ixx * (Kv_phi * (0 - phi_dot) + Kp_phi * (phi_c - phi));
    
    end