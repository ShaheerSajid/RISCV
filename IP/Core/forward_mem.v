module forward_mem
#(parameter FLOAT = 0)
(float_read, fw_imem, rs1id,rs2id, rdmem, wbmem, fa, fb);

input [4:0] rs1id,rs2id, rdmem;
input wbmem;
input [1:0] float_read;
input fw_imem;
output reg fa,fb;

always@(*)
begin
	if(FLOAT)
	begin
	fa = wbmem && rdmem != 0 && rdmem == rs1id && (float_read[1]==fw_imem);
	fb = wbmem && rdmem != 0 && rdmem == rs2id && (float_read[0]==fw_imem);
	end
	else
	begin
	fa = wbmem && rdmem != 0 && rdmem == rs1id;
	fb = wbmem && rdmem != 0 && rdmem == rs2id;
	end
	

end
endmodule