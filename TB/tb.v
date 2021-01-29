`timescale 1ns / 100ps

module tb;

     reg clk,reset;
	  parameter LEN = 2048;      // 2 MB
	  reg [7:0] mem [0:65535];
	  reg [31:0] timer[0:1];
	  
		wire [31:0] inst_data;
		wire [31:0] inst_addr;
		wire inst_stall;
		
		wire [31:0] avl_readdata;
		reg avl_waitrequest;
		wire [31:0] avl_address;
		wire [31:0] avl_writedata;
		wire [3:0] avl_byteenable;
		wire avl_read;
		wire avl_write;
		integer i;
		wire[15:0] avl_addr;
		assign avl_addr = (avl_address[15:0]>>2)<<2;

	  initial begin
		for(i = 0; i < 65536; i = i + 1)
		  mem[i] = 0;
		 $readmemh("/home/shaheer/Desktop/Projects/RISC/Demo/DE10/mem_init/sys_onchip_memory2_0.vh", mem);
		 $display("==============");
		 $display("RISCV Terminal");
		 $display("==============");
		 avl_waitrequest = 0;
		 timer[0] = 0;
		 timer[1] = 0;
		 clk = 0;
		 #20 reset = 1'b1;
		 #20 reset = 1'b0;
	  end
	  
	  assign inst_data = {mem[inst_addr+3], mem[inst_addr+2], mem[inst_addr+1], mem[inst_addr]};
	  assign avl_readdata = (avl_address == 32'h00011204)?timer[1]:{mem [avl_addr+3], mem [avl_addr+2], mem [avl_addr+1], mem [avl_addr]};
	  Core Core_inst
		(
			.clk(clk) ,	// input  clk_sig
			.reset(reset) ,	// input  reset_sig
			.inst_addr(inst_addr) ,	// output [31:0] inst_addr_sig
			.inst_data(inst_data) ,	// input [31:0] inst_data_sig
			.inst_stall(inst_stall) ,	// output  inst_stall_sig
			.avl_address(avl_address) ,	// output [31:0] avl_address_sig
			.avl_byteenable(avl_byteenable) ,	// output [3:0] avl_byteenable_sig
			.avl_read(avl_read) ,	// output  avl_read_sig
			.avl_readdata(avl_readdata) ,	// input [31:0] avl_readdata_sig
			.avl_waitrequest(avl_waitrequest) ,	// input  avl_waitrequest_sig
			.avl_write(avl_write) ,	// output  avl_write_sig
			.avl_writedata(avl_writedata) 	// output [31:0] avl_writedata_sig
		);
		defparam Core_inst.M_Extension = 1;
		defparam Core_inst.M_Extension_DIV = 0;
		defparam Core_inst.F_Extension = 0;

	  always begin 
		 #10 clk = !clk;
	  end 
	  
	  always@(posedge clk)
		begin
		if(timer[0][0])
			timer[1] = timer[1] + 1'b1;
		else
			timer[1] = timer[1];
		end

	  always @ (posedge clk) begin
		 if(avl_write && avl_address == 32'h00011200)
			timer[0] = avl_writedata;
		else if(avl_write && avl_address == 32'h00011204)
			timer[1] = avl_writedata;
		 else if (avl_write && avl_address == 32'h00011100)
			$write("%c", avl_writedata);
		 else if (avl_write) begin 
			mem[avl_addr]     = avl_byteenable[0] ? avl_writedata[07:00] : mem[avl_addr];
			mem[avl_addr + 1] = avl_byteenable[1] ? avl_writedata[15:08] : mem[avl_addr + 1];
			mem[avl_addr + 2] = avl_byteenable[2] ? avl_writedata[23:16] : mem[avl_addr + 2];
			mem[avl_addr + 3] = avl_byteenable[3] ? avl_writedata[31:24] : mem[avl_addr + 3];
		 end
	  end
endmodule 