module  mux2to1(din_0,din_1, sel,mux_out);

input [31:0]din_0, din_1;
input sel ;
output [31:0]mux_out;

assign mux_out = (sel) ? din_1 : din_0;

endmodule //End Of Module mux