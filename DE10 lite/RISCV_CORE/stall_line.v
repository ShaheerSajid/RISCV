module stall_line(float_read, fw_ie, memw_id,memr_ie, rd_ie, rs1_id, rs2_id, c_sel, id_stall, pc_stall);

input memr_ie,memw_id;

input [1:0] float_read;
input fw_ie;

input [4:0] rd_ie, rs1_id, rs2_id;
output reg c_sel, id_stall,pc_stall;

always@(*)
begin

	if(memr_ie && ((rd_ie == rs1_id && float_read[1]==fw_ie) || (rd_ie == rs2_id && float_read[0]==fw_ie)) )
		begin
			if(~memw_id)begin
			c_sel = 1'b1;
			id_stall = 1'b1;
			pc_stall = 1'b1;
			end
			else begin
			c_sel = 1'b0;
			id_stall = 1'b0;
			pc_stall = 1'b0;
			end
		end
	else
		begin
			c_sel = 1'b0;
			id_stall = 1'b0;
			pc_stall = 1'b0;
		end


end
endmodule
