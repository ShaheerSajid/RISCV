module forward_mem(float_read, fw_imem, rs1id,rs2id, rdmem, wbmem,memr,memw_ie, fa, fb);

input [4:0] rs1id,rs2id, rdmem;
input wbmem,memr,memw_ie;

input [1:0] float_read;
input fw_imem;

output reg fa,fb;


always@(*)
begin

	fa = 0;
	fb = 0;
	
	if(memw_ie && memr && wbmem && rdmem != 0 && rdmem == rs1id && (float_read[1]==fw_imem))
		fa = 1;
		
	if(memw_ie && memr && wbmem && rdmem != 0 && rdmem == rs2id && (float_read[0]==fw_imem))
		fb = 1;
	
end

endmodule