module core2avl
#(parameter DATA_WIDTH=32, parameter ADDR_WIDTH=32)
(
		input clk,
		input reset,
		input [2:0] mode,
		input [ADDR_WIDTH-1:0] addr,
		input [DATA_WIDTH-1:0] data2write,
		output [DATA_WIDTH-1:0] data2read,
		input [1:0] rw,
		output stall,
		
		//avl signals
		input [DATA_WIDTH-1:0] readdata, 
		input waitrequest, 
		output [ADDR_WIDTH-1:0] address, 
		output reg[DATA_WIDTH-1:0] writedata, 
		output [3:0] byteenable, 
		output read, 
		output write
);

	wire [1:0] byt;
	wire [(ADDR_WIDTH-1):0] base;
	reg [3:0] be;
	reg [DATA_WIDTH-1:0] q;
	reg [DATA_WIDTH-1:0] q1;
	
	//
	reg read_assert;
	reg [1:0] current,next;
	parameter IDLE = 2'b00;
	parameter S1 = 2'b01;
	parameter S2 = 2'b10;
	always@(posedge clk)
	begin
		if(reset)
			current <= IDLE;
		else
			current <= next;
	end
	always@(*)
	begin
		case(current)
			IDLE: begin next =(stall)?S1:IDLE; read_assert = 1'b1; end
			S1: begin next = (stall)?S1:S2; read_assert = 1'b1; end
			S2: begin next = IDLE; read_assert = 1'b0; end
		endcase
	end
	//
	
	assign base = addr >> 2;
	assign byt = (base==0)?addr:addr - (2<<base);

	assign read = rw[1] /*& read_assert*/;
	assign write = rw[0];
	assign stall = waitrequest & ~reset;
	assign address = addr;
	
	always@(*)
	begin
		case(byt)
			0:writedata = data2write;
			1:writedata = data2write<<8;
			2:writedata = data2write<<16;
			3:writedata = data2write<<24;
		endcase
	end
	
	
	assign data2read = q;
	assign byteenable = be;

	always@(*)
	begin
		if(mode == 3'b000 || mode == 3'b100)
			be = 1<<byt;
		else if(mode == 3'b001 || mode == 3'b101)
			be = 2'b11 << byt;
		else if(mode == 3'b010)
			be = 4'b1111;
		else
			be = 0;
			
	end
	
	always@(*)
	begin
		case(be)
			4'b0001: q1 = {{24{1'b0}},readdata[7:0]};
			4'b0010: q1 = {{24{1'b0}},readdata[15:8]};
			4'b0100: q1 = {{24{1'b0}},readdata[23:16]};
			4'b1000: q1 = {{24{1'b0}},readdata[31:24]};
			4'b0011: q1 = {{16{1'b0}},readdata[15:0]};
			4'b0110: q1 = {{16{1'b0}},readdata[23:8]};
			4'b1100: q1 = {{16{1'b0}},readdata[31:16]};
			4'b1111: q1 = readdata;
			default: q1 = 32'h00000000;
		endcase
	end
	
	always@(*)
	begin
				case(mode)
				3'b000: q = {{24{q1[7]}},q1[7:0]};//lb	
				3'b001: q = {{16{q1[15]}},q1[15:0]};// lh
				3'b010: q = q1;//lw
				3'b100: q = {{24{1'b0}},q1[7:0]};//lbu						
				3'b101: q = {{16{1'b0}},q1[15:0]};// lhu
				default: q = 0;
				endcase
	end

endmodule
