module REG_FILE
  (input clk,
   input reset,
   input write,
   input [4:0] wrAddr,
   input [31:0] wrData,
   input [4:0] rdAddrA,
   output [31:0] rdDataA,
   input [4:0] rdAddrB,
   output [31:0] rdDataB);

   reg [31:0] 	 regfile [0:31] ;
	
	initial
	begin
		$readmemh("/home/shaheer/Desktop/Projects/RISC/Demo/DE10/RISCV_CORE/regfile.txt", regfile,0,31);
	end
	
   assign rdDataA = regfile[rdAddrA];
   assign rdDataB = regfile[rdAddrB];

   always @(posedge clk) begin 
	 if (write && wrAddr != 0) regfile[wrAddr] <= wrData;
      end 
endmodule

