module pcALU(A,B,pcalu, Bsel_br);

input[31:0] A,B;
input Bsel_br;
output [31:0] pcalu;
reg [31:0] alu;

always@(*)
begin

if(Bsel_br)
	begin
		alu = $signed(A) + $signed(B);
	end
	else
	begin
		/*if(B[31])
		alu = A - ((~B[31:0] + 1) >> 1);
		else
		alu = A + (B >> 1);
		*/
		alu = $signed(A) + $signed(B<<1);
	end
	
end
assign pcalu = alu;

endmodule
