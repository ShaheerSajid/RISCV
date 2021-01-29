module REG_FILE
  (input clk,
   input reset,
   input write,
   input [4:0] wrAddr,
   input [31:0] wrData,
   input [4:0] rdAddrA,
   output[31:0] rdDataA,
   input [4:0] rdAddrB,
   output[31:0] rdDataB);

   reg [31:0] 	 regfile [0:31] ;
	integer i;
   assign rdDataA = regfile[rdAddrA];
   assign rdDataB = regfile[rdAddrB];
	
	initial begin
		for(i = 0; i<32; i = i+1)
			regfile[i] = 0;
	end

   always @(posedge clk) begin 
	 if (write && wrAddr != 0) regfile[wrAddr] <= wrData;
      end 
	
endmodule

