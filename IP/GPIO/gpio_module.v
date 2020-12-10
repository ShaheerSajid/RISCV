module gpio_module
(
		clock,
		resetn,
		address,
		writedata,
		write,
		readdata,
		read,
		waitrequest,
		chipselect,
		
		gpio
);


// signals for connecting to the Avalon fabric
input clock;
input resetn;
input write;
input read;
input chipselect;
input [31:0]writedata;
input address;
output[31:0]readdata;
output waitrequest;

inout [31:0] gpio;



reg [31:0] module_reg[0:1];//DDR,POUT,PIN
reg[31:0] data_out;
wire[31:0] in;


integer i;
genvar gi;
generate
  for (gi=0; gi<32; gi=gi+1) begin : genbit
    assign gpio[gi] = module_reg[0][gi]? module_reg[1][gi]: 1'bz;
  end
endgenerate


assign in = gpio;

always@(posedge clock)
begin
	if(resetn)
		begin
			module_reg[0] = 32'd0;
			module_reg[1] = 32'd0;
		end
	else if(write & chipselect)
		module_reg[address] <= writedata;
	data_out <= in;
end

assign waitrequest = 1'b0;
assign readdata = (address)?data_out:module_reg[0];
endmodule
