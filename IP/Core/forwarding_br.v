module forwarding_br
#(parameter FLOAT=0)
(float_read, fw_wb, rs1id,rs2id, rdwb, wbwb, fa, fb);


input [1:0] float_read;
input fw_wb;
input [4:0] rs1id,rs2id,rdwb;
input wbwb;
output reg fa,fb;

always@(*)
begin
	if(FLOAT)
	begin
	fa = wbwb && rdwb != 0 && rdwb == rs1id  && (float_read[1]==fw_wb);
	fb = wbwb && rdwb != 0 && rdwb == rs2id  && (float_read[0]==fw_wb);
	end
	else
	begin
	fa = wbwb && rdwb != 0 && rdwb == rs1id;
	fb = wbwb && rdwb != 0 && rdwb == rs2id;
	end

end

endmodule