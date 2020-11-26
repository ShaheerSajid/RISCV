module timer_module
(
		clock,
		resetn,
		address,
		writedata,
		write,
		readdata,
		read,
		waitrequest,
		chipselect
);

input clock;
input resetn;
input write;
input read;
input chipselect;
input [31:0]writedata;
input [1:0]address;
output[31:0]readdata;
output waitrequest;


reg [31:0] module_reg[0:2];
reg [10:0]div;


always@(posedge clock)
begin
	if(resetn)
		begin
			module_reg[0] <= 32'd0;
			module_reg[1] <= 32'd0;
			module_reg[2] <= 32'd0;
			div <= 0;
		end
	else if(write & chipselect)
		module_reg[address] <= writedata;
	else
		begin
			case(module_reg[0][2:0])
				0: begin div <= 1'b0; module_reg[1] <= 32'b0; end
				1: begin div <= 1'b0; module_reg[1] <= module_reg[1] + 1'b1; end
				2: begin div <= div+ 1'b1; module_reg[1] <= module_reg[1] + div[3]; end
				3: begin div <= div+ 1'b1; module_reg[1] <= module_reg[1] + div[5]; end
				4: begin div <= div+ 1'b1; module_reg[1] <= module_reg[1] + div[6]; end
				5: begin div <= div+ 1'b1; module_reg[1] <= module_reg[1] + div[7]; end
				6: begin div <= div+ 1'b1; module_reg[1] <= module_reg[1] + div[8]; end
				7: begin div <= div+ 1'b1; module_reg[1] <= module_reg[1] + div[10]; end
			endcase
		end
end

assign readdata = (read & chipselect)?module_reg[address]: 32'b0;
assign waitrequest = 1'b0;

endmodule
