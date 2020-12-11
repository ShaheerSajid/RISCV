module ALU
#(parameter M_Extension = 0, parameter M_Extension_DIV = 0, parameter F_Extension = 0)
(fpu_use, A,B,ALUsel,result);

input fpu_use;
input [31:0]A,B;
input[4:0]ALUsel;
output [31:0] result;

wire[31:0]fpuout;
wire[31:0]div_out;
wire[31:0]divu_out;
wire[31:0]rem_out;
wire[31:0]remu_out;

reg[31:0]ALUout;

generate
if(F_Extension)
	begin
		FPU FPU_inst
		(
			.A(A) ,	// input [31:0] A_sig
			.B(B) ,	// input [31:0] B_sig
			.sel(ALUsel) ,	// input [3:0] sel_sig
			.out(fpuout) 	// output [31:0] out_sig
		);
		assign result = fpu_use? fpuout:ALUout;
	end
else
	assign result = ALUout;
endgenerate

generate
if(M_Extension_DIV && M_Extension)
	begin
	
		lpm_divide	LPM_DIVIDE_component (
				.denom (B),
				.numer (A),
				.quotient (div_out),
				.remain (rem_out),
				.aclr (1'b0),
				.clken (1'b1),
				.clock (1'b0));
	defparam
		LPM_DIVIDE_component.lpm_drepresentation = "SIGNED",
		LPM_DIVIDE_component.lpm_hint = "LPM_REMAINDERPOSITIVE=TRUE",
		LPM_DIVIDE_component.lpm_nrepresentation = "SIGNED",
		LPM_DIVIDE_component.lpm_type = "LPM_DIVIDE",
		LPM_DIVIDE_component.lpm_widthd = 32,
		LPM_DIVIDE_component.lpm_widthn = 32;
		
		
		lpm_divide	LPM_DIVIDEU_component (
				.denom (B),
				.numer (A),
				.quotient (divu_out),
				.remain (remu_out),
				.aclr (1'b0),
				.clken (1'b1),
				.clock (1'b0));
	defparam
		LPM_DIVIDEU_component.lpm_drepresentation = "UNSIGNED",
		LPM_DIVIDEU_component.lpm_hint = "LPM_REMAINDERPOSITIVE=TRUE",
		LPM_DIVIDEU_component.lpm_nrepresentation = "UNSIGNED",
		LPM_DIVIDEU_component.lpm_type = "LPM_DIVIDE",
		LPM_DIVIDEU_component.lpm_widthd = 32,
		LPM_DIVIDEU_component.lpm_widthn = 32;
		
	end
else
	begin
		assign div_out = 32'd0;
		assign divu_out = 32'd0;
		assign rem_out = 32'd0;
		assign remu_out = 32'd0;
	end
endgenerate




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
		8:ALUout = (M_Extension)?$signed(A)*$signed(B):32'd0;//mul
		9:ALUout = $signed(A)>>>B[4:0];//shift right arithmatic
		10:ALUout = A&B;//and
		11:ALUout = A|B;//or
		12:ALUout = A^B;//xor
		13:	begin	if (A<B) ALUout = 32'd1; //sltu
						else ALUout = 32'd0;
				end
		14:	begin	if ($signed(A)<$signed(B)) ALUout = 32'd1;//slt
						else ALUout = 32'd0;
				end
		15:ALUout = (M_Extension)?($signed({{32{A[31]}},A})*$signed({{32{B[31]}},B}))>>32:32'd0;//mulh
		16:ALUout = (M_Extension)?({32'd0,A}*{32'd0,B})>>32:32'd0;//mulhu
		17:ALUout = div_out;//div
		18:ALUout = divu_out;//divu
		19:ALUout = rem_out;//rem
		20:ALUout = remu_out;//remu
		default: ALUout = 0;
	endcase	
end
endmodule
