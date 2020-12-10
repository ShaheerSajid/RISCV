module IMM_gen(instruction,immsel, imm);

input [31:0]instruction;
input [2:0]immsel;
output reg[31:0]imm;
always @(*)

  begin
    case (immsel)
      3'b000: imm = {{20{instruction[31]}},instruction[31:20]};
      3'b001: imm = {{20{instruction[31]}},instruction[31:25],instruction[11:7]};
      3'b010: imm = {{20{instruction[31]}},instruction[31],instruction[7],instruction[30:25],instruction[11:8]};
      3'b011: imm = {{12{instruction[31]}},instruction[31], instruction[19:12],instruction[20],instruction[30:21]};
		3'b100: imm = {{instruction[31:12]},12'b000000000000};
		default: imm = 0;
    endcase
  end
endmodule
