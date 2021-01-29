module FPU(A,B,sel,out);

input [31:0] A,B;
input	[4:0] sel;
output reg [31:0] out;

wire [31:0] res1, res2;
wire [1:0] res3;
wire [31:0] res4,res5;
reg add_sub;

adder adder_inst
(
	.a(A) ,	// input [31:0] a_sig
	.b(B) ,	// input [31:0] b_sig
	.op(add_sub) ,	// input  op_sig
	.results(res1), 	// output [31:0] results_sig
	.compare(res3)
);
multiply multiply_inst
(
	.iA(A) ,	// input [31:0] iA_sig
	.iB(B) ,	// input [31:0] iB_sig
	.oProd(res2) 	// output [31:0] oProd_sig
);

fp2int fp2int_inst
(
	.A(A) ,	// input [31:0] A_sig
	.B(res5) 	// output [31:0] B_sig
);

int2fp int2fp_inst
(
	.A(A) ,	// input [31:0] A_sig
	.B(res4) 	// output [31:0] B_sig
);

always@(*)
	begin
	case(sel)
		0: begin add_sub =1'b0; out = A; end//A
		1: begin add_sub =1'b0; out = B; end//B
		2: begin add_sub =1'b0; out = {~A[31], A[30:0]}; end//~A
		3: begin add_sub =1'b0; out = {~B[31], B[30:0]}; end//~B
		4: begin add_sub =1'b0; out = res1; end//A+B
		5: begin add_sub =1'b1; out = res1; end//A-B
		6: begin add_sub =1'b0; out = res2; end//A*B
		7: begin add_sub =1'b0; out = (res3==1)?A:B; end//min
		8: begin add_sub =1'b0; out = (res3==0)?A:B; end//max
		9: begin add_sub =1'b0; out = (res3==2)?1:0; end//eq
		10: begin add_sub =1'b0; out = (res3==1)?1:0; end//lt
		11: begin add_sub =1'b0; out = (res3==1 || res3==2)?1:0; end//le
		12: begin add_sub =1'b0; out = A; end//mv s-r
		13: begin add_sub =1'b0; out = A; end//mv r-s
		14: begin add_sub =1'b0; out = res4; end//cvt s-w
		//15: begin add_sub =1'b0; out = A; end//cvt s-wu
		15: begin add_sub =1'b0; out = res5; end//cvt w-s
		//17: begin add_sub =1'b0; out = A; end//cvt wu-s
		default: begin add_sub =1'b0;  out  = 0; end//0
	 endcase
	end


endmodule


module adder(a,b,op,results, compare);

input op;
input [31:0]a,b; //[31]Sign,[30:23] Exponent,[22:0]mantissa,
output reg[31:0]results;

reg [7:0]a_exp, b_exp, r_exp;
reg [31:0]a_m, b_m, r_m,prm;
reg [1:0] mag;
output reg [1:0] compare;
integer i;
reg state;


always @(*)
begin
//Decompose
	a_exp = a[30:23];
	a_m = {9'b000000001, a[22:0]};
	b_exp = b[30:23];
	b_m = {9'b000000001, b[22:0]};
	
//Sort/Align
	
	if(a_exp > b_exp)
	begin
		mag = 0;
		compare = 0;
		b_m = b_m >> (a_exp-b_exp);
		b_exp = b_exp + (a_exp-b_exp);
	end
	else if(a_exp < b_exp)
	begin
		mag = 1;
		compare = 1;
		a_m = a_m >> (b_exp-a_exp);
		a_exp = a_exp + (b_exp-a_exp);
	end
	else
	begin
		mag = 2;
		compare = 2;
		if(a_m > b_m)
			compare = 0;
		else  if(a_m < b_m)
			compare = 1;
		else	
			compare = 2;			
	end

	
//Add
		if((a[31]==b[31] && !op) || (a[31]!=b[31] && op))
			begin
			results[31] = a[31];
			r_m = a_m + b_m;
			end	
		else if((a[31]!=b[31] && !op) || (a[31]==b[31] && op))
			begin
				if(mag==0)
				begin
					r_m = a_m - b_m;
					results[31] = op? 1'b0 : a[31];
				end
				else if (mag==1)
				begin
					r_m = b_m - a_m;
					results[31] = op? (b[31]?1'b0:1'b1) : b[31];
				end
				else if (mag==2)
				begin
					if(a_m >= b_m)
					begin
						r_m = a_m - b_m;
						results[31] = op? 1'b0 : a[31];
					end
					else if (a_m < b_m)
					begin
						r_m = b_m - a_m;
						results[31] = op? (b[31]?1'b0:1'b1) : b[31];
					end
					else begin r_m = b_m - a_m; results[31] = 1'b0; end
				end
				else begin r_m = b_m - a_m; results[31] = 1'b0; end
			end
		else begin r_m = b_m - a_m; results[31] = 1'b0; end
	
//Normalize
	state = 1;
	i = 31;
	 while (state==1) 
	 begin
		if(r_m[i]==1 || i == 0)
			state = 0;
		i = i-1;
    end
	 
	r_exp = a_exp + i-22;
	
	
	if((i-22) > 0)
		prm = r_m >> $unsigned((i-22));
	else if((i-22) < 0)
		prm = r_m << $unsigned((22-i));
	else
		prm = r_m;

//compose
	results[30:23] = r_exp;
	results[22:0] = prm[22:0];
end

endmodule

module multiply(
    input      [31:0] iA,    // First input
    input      [31:0] iB,    // Second input
    output     [31:0] oProd  // Product
);

    // Extract fields of A and B.
    wire        A_s;
    wire [7:0]  A_e;
    wire [22:0] A_f;
    wire        B_s;
    wire [7:0]  B_e;
    wire [22:0] B_f;
    assign A_s = iA[31];
    assign A_e = iA[30:23];
    assign A_f = {1'b1, iA[22:1]};
    assign B_s = iB[31];
    assign B_e = iB[30:23];
    assign B_f = {1'b1, iB[22:1]};

    // XOR sign bits to determine product sign.
    wire        oProd_s;
    assign oProd_s = A_s ^ B_s;

    // Multiply the fractions of A and B
    wire [45:0] pre_prod_frac;
    assign pre_prod_frac = A_f * B_f;

    // Add exponents of A and B
    wire [8:0]  pre_prod_exp;
    assign pre_prod_exp = A_e + B_e;

    // If top bit of product frac is 0, shift left one
    wire [7:0]  oProd_e;
    wire [22:0] oProd_f;
    assign oProd_e = pre_prod_frac[45] ? (pre_prod_exp-9'd126) : (pre_prod_exp - 9'd127);
    assign oProd_f = pre_prod_frac[45] ? pre_prod_frac[44:22] : pre_prod_frac[43:21];

    // Detect underflow
    wire        underflow;
    assign underflow = pre_prod_exp < 9'h80;

    // Detect zero conditions (either product frac doesn't start with 1, or underflow)
    assign oProd = underflow        ? 32'b0 :
                   (B_e == 8'd0)    ? 32'b0 :
                   (A_e == 8'd0)    ? 32'b0 :
                   {oProd_s, oProd_e, oProd_f};

endmodule


module int2fp(A,B);

input [31:0] A;
output reg [31:0] B;

reg [31:0]abs;
reg sign ;
reg [22:0] mout ; // mantissa
reg [7:0] eout ; // exponent
reg [7:0] num_zeros ;

always@(*)
begin
	abs = (A[31])? (~A)+32'd1 : A;
		
	if (abs[30:0] == 0)
		begin // zero value
			eout = 0 ;
			mout = 0 ;
			sign = 0 ;
			num_zeros = 8'd0 ;
		end 
		else // not zero
		begin
			casez (abs[30:0])
				31'b1??????????????????????????????: num_zeros = 8'd0 ;
				31'b01?????????????????????????????: num_zeros = 8'd1 ;
				31'b001????????????????????????????: num_zeros = 8'd2 ;
				31'b0001???????????????????????????: num_zeros = 8'd3 ;
				31'b00001??????????????????????????: num_zeros = 8'd4 ;
				31'b000001?????????????????????????: num_zeros = 8'd5 ;
				31'b0000001????????????????????????: num_zeros = 8'd6 ;
				31'b00000001???????????????????????: num_zeros = 8'd7 ;
				31'b000000001??????????????????????: num_zeros = 8'd8 ;
				31'b0000000001?????????????????????: num_zeros = 8'd9 ;
				31'b00000000001????????????????????: num_zeros = 8'd10;
				31'b000000000001???????????????????: num_zeros = 8'd11;
				31'b0000000000001??????????????????: num_zeros = 8'd12;
				31'b00000000000001?????????????????: num_zeros = 8'd13;
				31'b000000000000001????????????????: num_zeros = 8'd14;
				31'b0000000000000001???????????????: num_zeros = 8'd15;
				31'b00000000000000001??????????????: num_zeros = 8'd16;
				31'b000000000000000001?????????????: num_zeros = 8'd17;
				31'b0000000000000000001????????????: num_zeros = 8'd18;
				31'b00000000000000000001???????????: num_zeros = 8'd19;
				31'b000000000000000000001??????????: num_zeros = 8'd20;
				31'b0000000000000000000001?????????: num_zeros = 8'd21;
				31'b00000000000000000000001????????: num_zeros = 8'd22;
				31'b000000000000000000000001???????: num_zeros = 8'd23;
				31'b0000000000000000000000001??????: num_zeros = 8'd24;
				31'b00000000000000000000000001?????: num_zeros = 8'd25;
				31'b000000000000000000000000001????: num_zeros = 8'd26;
				31'b0000000000000000000000000001???: num_zeros = 8'd27;
				31'b00000000000000000000000000001??: num_zeros = 8'd28;
				31'b000000000000000000000000000001?: num_zeros = 8'd29;
				31'b0000000000000000000000000000001: num_zeros = 8'd30;
				default: num_zeros = 8'd31 ;
			endcase 
			mout = (abs[30:0] << num_zeros) >> 7 ; 
			eout = (157- num_zeros) ; // h80 is offset, h09 normalizes
			sign = A[31] ;
		end // if int_in!=0
		
		B = {sign, eout, mout};
end // always @
endmodule


module fp2int(A,B);

input [31:0] A;
output[31:0] B;

wire [31:0] abs_int ;
wire [23:0] m;
wire [7:0] e;

assign m = {1'd1, A[22:0]};
assign e = A[30:23];

assign abs_int = (A[30:23] >= 127)? ((m<<7) >> (157 - e)) : 32'd0 ;
assign B = (A[31]? (~abs_int)+32'd1 : abs_int);
endmodule
