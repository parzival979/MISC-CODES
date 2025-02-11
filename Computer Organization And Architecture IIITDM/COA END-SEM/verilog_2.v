module not_gate(a,b);
    input a;
    output b;
    assign b = ~a;
endmodule


module main;
    wire t_b;
    reg t_a;
    not_gate test(.a(t_a),.b(t_b));
    initial begin
    $monitor("a:",t_a,"  b(output):",t_b);
    t_a = 1'b0;
    #5000
    t_a = 1'b1;
    end
endmodule
