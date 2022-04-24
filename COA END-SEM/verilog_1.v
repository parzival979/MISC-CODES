module fulladder(a,b,cin,s,cout);
    input a,b,cin;
    output s,cout;
    assign s=((~a)&(~b)&(cin))|((~a)&(b)&(~cin))|((a)&(~b)&(~cin))|((a)&(b)&(cin));
    assign cout=(a&b)|(b&cin)|(a&cin);
endmodule

module main;
    wire t_s,t_cout;
    reg t_a,t_b,t_cin;
    fulladder test(.a(t_a),.b(t_b),.cin(t_cin),.s(t_s),.cout(t_cout));
    initial begin
    $monitor("a:",t_a,"  b:",t_b,"  c:",t_cin,"  sum:",t_s,"  cout:",t_cout);
    t_a=1'b0;
    t_b=1'b0;
    t_cin=1'b0;
    #5000
    t_a=1'b0;
    t_b=1'b0;
    t_cin=1'b1;
    #5000
    t_a=1'b0;
    t_b=1'b1;
    t_cin=1'b0;
    #5000
    t_a=1'b0;
    t_b=1'b1;
    t_cin=1'b1;
    #5000
    t_a=1'b1;
    t_b=1'b0;
    t_cin=1'b0;
    #5000
    t_a=1'b1;
    t_b=1'b0;
    t_cin=1'b1;
    #5000
    t_a=1'b1;
    t_b=1'b1;
    t_cin=1'b0;
    #5000
    t_a=1'b1;
    t_b=1'b1;
    t_cin=1'b1;
    end
endmodule
