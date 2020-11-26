`timescale 1 ps / 1 ps
module tb();

reg clk, reset;
wire [31:0] inst_data;
wire [31:0] inst_addr;
wire inst_stall; 

system system_inst (
		.uart_clk_clk  (clk),  // uart_clk.clk
      .clk_clk       (clk),       //   clk.clk
      .reset_reset_n (reset), // reset.reset_n
      .gpio_port     (),     //  gpio.port
		.uart_rx       (),       //  uart.rx
      .uart_tx       (),        //      .tx
		
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

initial begin
reset = 1'b0; clk = 1'b0; #50 reset = 1'b1;
end
always
begin
#25 clk = 1'b1;
#25 clk = 1'b0;
end
endmodule