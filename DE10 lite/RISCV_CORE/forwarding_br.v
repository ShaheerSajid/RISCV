module forwarding_br(float_read, fw_ie, fw_imem, fw_wb, rs1id,rs2id, rdex, rdmem, rdwb, wbex,wbmem, wbwb,memr, fa, fb);


input [1:0] float_read;
input fw_ie,fw_imem,fw_wb;

input [4:0] rs1id,rs2id, rdex,rdmem,rdwb;
input wbex, wbmem, wbwb,memr;
output reg [2:0] fa,fb;


always@(*)
begin

	fa = 3'b000;
	fb = 3'b000;
	
	if(wbex && rdex != 0 && rdex == rs1id && (float_read[1]==fw_ie))
		fa = 3'b001;
		
	if(wbex && rdex != 0 && rdex == rs2id && (float_read[0]==fw_ie))
		fb = 3'b001;
		
			
	if(!memr && wbmem && rdmem != 0 && rdmem == rs1id && (float_read[1]==fw_imem) &&  !(wbex && rdex != 0  && rdex == rs1id && (float_read[1]==fw_ie)))
		fa  =3'b010;
		
	if(!memr && wbmem && rdmem != 0 && rdmem == rs2id && (float_read[0]==fw_imem) &&  !(wbex && rdex != 0  && rdex == rs2id && (float_read[0]==fw_ie)))
		fb  =3'b010;	
		
	
	if(memr && wbmem && rdmem != 0 && rdmem == rs1id  && (float_read[1]==fw_imem) &&  !(wbex && rdex != 0  && rdex == rs1id && (float_read[1]==fw_ie)))
		fa  =3'b011;
		
	if(memr && wbmem && rdmem != 0 && rdmem == rs2id  && (float_read[0]==fw_imem) &&  !(wbex && rdex != 0  && rdex == rs2id && (float_read[0]==fw_ie)))
		fb  =3'b011;
	
	
	if(wbwb && rdwb != 0 && rdwb == rs1id  && (float_read[1]==fw_wb) &&  !(wbmem && rdmem != 0  && rdmem == rs1id && (float_read[1]==fw_imem)) &&  !(wbex && rdex != 0  && rdex == rs1id && (float_read[1]==fw_ie)))
		fa  =3'b100;
		
	if(wbwb && rdwb != 0 && rdwb == rs2id  && (float_read[0]==fw_wb) &&  !(wbmem && rdmem != 0  && rdmem == rs2id && (float_read[0]==fw_imem)) &&  !(wbex && rdex != 0  && rdex == rs2id && (float_read[0]==fw_ie)))
		fb  =3'b100;
	
	
end

endmodule