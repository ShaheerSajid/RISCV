module stall_line
#(parameter FLOAT = 0)
(inst,float_read, fw_ie, wb_ie, rd_ie, rs1_id, rs2_id, br_stall);

input wb_ie;
input inst;
input [1:0] float_read;
input fw_ie;
input [4:0] rd_ie, rs1_id, rs2_id;
output reg br_stall;

always@(*)
begin
	if(FLOAT)
	br_stall = inst && wb_ie && rd_ie != 0 && ((rd_ie == rs1_id && float_read[1]==fw_ie) || (rd_ie == rs2_id && float_read[0]==fw_ie));
	else
	br_stall = inst && wb_ie && rd_ie != 0 && ((rd_ie == rs1_id) || (rd_ie == rs2_id));
	
end
endmodule
