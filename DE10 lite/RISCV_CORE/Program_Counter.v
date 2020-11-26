module Program_Counter(stall, pc_in, pc_reset, clk, pc_out);

input stall;
input wire [31:0]pc_in;
input wire pc_reset, clk;
output reg [31:0]pc_out;

always @(posedge clk)
begin
	if (pc_reset)
		begin
			pc_out <= 32'h00000000;
		end
	else if(!stall)
		begin
			pc_out <= pc_in;
		end		
end
endmodule
