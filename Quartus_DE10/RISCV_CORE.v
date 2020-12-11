module RISCV_CORE(MAX10_CLK1_50, KEY, ARDUINO_IO, HEX0,HEX1,HEX2,HEX3,HEX4,HEX5);

input MAX10_CLK1_50;
inout [1:0]KEY;
output [7:0] HEX0,HEX1,HEX2,HEX3,HEX4,HEX5;
inout [15:0]ARDUINO_IO;

wire [31:0]num;
wire [31:0] inst_data;
wire [31:0] inst_addr;
wire inst_stall;
wire clk1;
hex_out h5(.data(num[23:20]) ,.out(HEX5));
hex_out h4(.data(num[19:16]) ,.out(HEX4));
hex_out h3(.data(num[15:12]) ,.out(HEX3));
hex_out h2(.data(num[11:8])  ,.out(HEX2));
hex_out h1(.data(num[7:4]) ,.out(HEX1));
hex_out h0(.data(num[3:0]) ,.out(HEX0));


//################################################# 
	 
pll_8m	pll_8m_inst (
	.inclk0 ( MAX10_CLK1_50 ),
	.c0 ( clk1 )
);
system system_inst (
		.uart_clk_clk  (MAX10_CLK1_50),  // uart_clk.clk
      .clk_clk       (clk1),       //   clk.clk
      .reset_reset_n (KEY[0]), // reset.reset_n
      .gpio_port     ({num[20:0], KEY[1], ARDUINO_IO[9:0]}),     //  gpio.port
		.uart_rx       (ARDUINO_IO[10]),       //  uart.rx
      .uart_tx       (ARDUINO_IO[11]),        //      .tx
		
		  .flash_address    (inst_addr),    //    flash.address
        .flash_chipselect (1'b1), //         .chipselect
        .flash_clken      (~inst_stall),      //         .clken
        .flash_write      (1'b0),      //         .write
        .flash_readdata   (inst_data),   //         .readdata
        .flash_writedata  (),  //         .writedata
        .flash_byteenable (4'b0000), //         .byteenable
		  
        .flash_1_addr     (inst_addr),     //  flash_1.addr
        .flash_1_data     (inst_data),     //         .data
        .flash_1_stall    (inst_stall)    //         .stall
  
);

//##################################################
endmodule


module hex_out(data, out);
input [3:0] data;
output reg [7:0]out;
always@(*)
begin
	case (data)
		  0: out=8'b11000000;  
		  1: out=8'b11111001;
		  2: out=8'b10100100;  
		  3: out=8'b10110000;
		  4: out=8'b10011001;
		  5: out=8'b10010010;  
		  6: out=8'b10000010; 
		  7: out=8'b11111000;
		  8: out=8'b10000000;
		  9: out=8'b10010000;
		  10:out=8'b10001000;
		  11:out=8'b10000011;
		  12:out=8'b11000110;
		  13:out=8'b10100001;
		  14:out=8'b10000110;
		  15:out=8'b10001110;
	endcase
end
endmodule