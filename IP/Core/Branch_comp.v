module Branch_comp(A,B,BrUn, BrLT, BrEq);



input [31:0]A,B;
input BrUn;
output reg BrLT, BrEq;

always@(*)
begin
	
	BrLT = BrUn?A<B:$signed(A)<$signed(B);
	BrEq = BrUn?A==B:$signed(A)==$signed(B);
	/*if(BrUn)
		begin
			if(A<B)
				begin
					BrLT = 1'b1;
					BrEq = 1'b0;
				end
			else 
				begin
					BrLT = 1'b0;
					if(A==B)
						BrEq = 1'b1;
					else
						BrEq = 1'b0;
				end
		end
	else
		begin
			if($signed(A)<$signed(B))
				begin
					BrLT = 1'b1;
					BrEq = 1'b0;
				end
			else 
				begin
					BrLT = 1'b0;
					if($signed(A)==$signed(B))
						BrEq = 1'b1;
					else
						BrEq = 1'b0;
				end
		end
	*/
end
endmodule

