module mux5to1(sel, i1, i2, i3, i4,i5, o1);

input [2:0] sel;

input [31:0] i1, i2, i3, i4,i5;

output [31:0] o1;
reg [31:0] o1;


always @(*)

  begin

    case (sel)
      3'b000: o1 = i1;
      3'b001: o1 = i2;
      3'b010: o1 = i3;
      3'b011: o1 = i4;
		3'b100: o1 = i5;
		default: o1 = 0;
    endcase

  end

endmodule