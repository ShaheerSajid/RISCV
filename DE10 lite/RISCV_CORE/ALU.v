module ALU(fpu_use, A,B,ALUsel,result);

input fpu_use;
input [31:0]A,B;
input[4:0]ALUsel;
output [31:0] result;

wire[31:0]fpuout;
reg[31:0]ALUout;

	
FPU FPU_inst
(
	.A(A) ,	// input [31:0] A_sig
	.B(B) ,	// input [31:0] B_sig
	.sel(ALUsel) ,	// input [3:0] sel_sig
	.out(fpuout) 	// output [31:0] out_sig
);

assign result = fpu_use? fpuout:ALUout;

always@(*)
begin
	case (ALUsel)
		0:ALUout = A;
		1:ALUout = B;
		2:ALUout = A+B;//add
		3:ALUout = A-B;//sub
		4:ALUout = ~A;//not A
		5:ALUout = ~B; //not B
		6:ALUout = A<<B[4:0];//shift left
		7:ALUout = A>>B[4:0];//shift right
		8:ALUout = $signed(A)*$signed(B);//mul
		9:ALUout = {A[31], A[30:0]>>B[4:0]};//shift right arithmatic
		10:ALUout = A&B;//and
		11:ALUout = A|B;//or
		12:ALUout = A^B;//xor
		13:	begin	if (A<B) ALUout = 32'd1; //sltu
						else ALUout = 32'd0;
				end
		14:	begin	if ($signed(A)<$signed(B)) ALUout = 32'd1;//slt
						else ALUout = 32'd0;
				end
		15:ALUout = ($signed({{32{A[31]}},A})*$signed({{32{B[31]}},B}))>>32;//mulh
		16:ALUout = ({32'd0,A}*{32'd0,B})>>32;//mulhu		
		default: ALUout = 0;
	endcase	
end
endmodule
