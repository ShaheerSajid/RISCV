module register
#(parameter width=32)
(
	input [width-1:0] in,
	output reg [width-1:0] out,
	input clk, reset
);


always@(posedge clk)
begin
	if(reset)
		out <= 0;
	else
		out <= in;
end
endmodule
