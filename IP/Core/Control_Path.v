module Control_Path(instruction,BrEq, BrLt,BrUn,PCSel, Immsel, RegWEn, Asel,Bsel, Asel_br,Bsel_br, ALUSel, MemRW, WBsel, flush_ID,float_read,float_write,fpu_use,br_true);

input BrEq,BrLt;
input [31:0] instruction;

output reg BrUn,PCSel,RegWEn, Asel,Bsel, Asel_br,Bsel_br, flush_ID,float_write,fpu_use,br_true;
output reg [1:0]MemRW,float_read;
output reg [4:0]ALUSel;
output reg [1:0]WBsel;
output reg [2:0]Immsel;

wire [6:0]inst;
assign inst = {instruction[6:0]};

always@(*)
begin
		
	case(inst)
		7'b0000011://I lw
					begin
						br_true = 0;
						flush_ID = 0;
						BrUn = 1'b0;
						PCSel = 1'b0;
						Immsel = 3'b000;
						RegWEn = 1'b1;
						Asel = 1'b0;
						Bsel = 1'b1;
						Asel_br = 1'b0;
						Bsel_br = 1'b0;
						ALUSel = 5'b00010;
						MemRW = 2'b10;
						WBsel = 2'b10;
						float_read = 2'b00;
						float_write = 1'b0;
						fpu_use = 1'b0;
						end
		7'b0010011://I
					begin
						br_true = 0;
						flush_ID = 0;
						BrUn = 1'b0;
						PCSel = 1'b0;
						Immsel = 3'b000;
						RegWEn = 1'b1;
						Asel = 1'b0;
						Bsel = 1'b1;
						Asel_br = 1'b0;
						Bsel_br = 1'b0;
						case(instruction[14:12])
							3'b000: ALUSel = 5'b00010;//addi
							3'b001: ALUSel = 5'b00110;//slli
							3'b010: ALUSel = 5'b01110;//slti
							3'b011: ALUSel = 5'b01101;//sltiu
							3'b100: ALUSel = 5'b01100;//xori
							3'b101: 
									begin
										if(instruction[30])
											ALUSel = 5'b01001;//srai
										else
											ALUSel = 5'b00111;//srli
									end
							3'b110: ALUSel = 5'b01011;//ori
							3'b111: ALUSel = 5'b01010;//andi
							default: ALUSel = 5'b00000;
						endcase
						MemRW = 2'b00;
						WBsel = 2'b00;
						float_read = 2'b00;
						float_write = 1'b0;
						fpu_use = 1'b0;
					end
		7'b1100111://I jalr//
					begin
						br_true = 1;
						flush_ID = 1;
						BrUn = 1'b0;
						PCSel = 1'b1;
						Immsel = 3'b000;
						RegWEn = 1'b1;
						Asel = 1'b0;
						Bsel = 1'b1;
						Asel_br = 1'b1;//PC, RS1
						Bsel_br = 1'b1;//B_Imm,I_Imm
						ALUSel = 5'b00010;
						MemRW = 2'b00;
						WBsel = 2'b01;
						float_read = 2'b00;
						float_write = 1'b0;
						fpu_use = 1'b0;
					end
		7'b0100011://S sw
					begin
						br_true = 0;
						flush_ID = 0;
						BrUn = 1'b0;
						PCSel = 1'b0;
						Immsel = 3'b001;
						RegWEn = 1'b0;
						Asel = 1'b0;
						Bsel = 1'b1;
						Asel_br = 1'b0;
						Bsel_br = 1'b0;
						ALUSel = 5'b00010;
						MemRW = 2'b01;
						WBsel = 2'b00;
						float_read = 2'b00;
						float_write = 1'b0;
						fpu_use = 1'b0;
					end
		7'b0110011://R
					begin
						br_true = 0;
						flush_ID = 0;
						BrUn = 1'b0;
						PCSel = 1'b0;
						Immsel = 3'b000;
						RegWEn = 1'b1;
						Asel = 1'b0;
						Bsel = 1'b0;
						Asel_br = 1'b0;
						Bsel_br = 1'b0;
						if(instruction[31:25] == 1)
						begin
						case(instruction[14:12])
							3'b000: ALUSel = 5'b01000;//mul
							3'b001: ALUSel = 5'b01111;//mulh
							3'b011: ALUSel = 5'b10000;//mulhu
							3'b100: ALUSel = 5'b10001;//div
							3'b101: ALUSel = 5'b10010;//divu
							3'b110: ALUSel = 5'b10011;//rem
							3'b111: ALUSel = 5'b10100;//remu
							default: ALUSel = 5'b00000;
						endcase
						end
						else
						begin
						case(instruction[14:12])
							3'b000:
									begin
										if(instruction[30])
											ALUSel = 5'b00011; //sub
										else
											ALUSel = 5'b00010; //add
									end
							3'b001: ALUSel = 5'b00110;//sll
							3'b010: ALUSel = 5'b01110;//slt
							3'b011: ALUSel = 5'b01101;//sltu
							3'b100: ALUSel = 5'b01100;//xor
							3'b101: 
									begin
										if(instruction[30])
											ALUSel = 5'b01001;//sra
										else
											ALUSel = 5'b00111;//srl
									end
							3'b110: ALUSel = 5'b01011;//or
							3'b111: ALUSel = 5'b01010;//and
							default: ALUSel = 5'b00000;
						endcase
						end
						MemRW = 2'b00;
						WBsel = 2'b00;
						float_read = 2'b00;
						float_write = 1'b0;
						fpu_use = 1'b0;
					end
		7'b1100011://SB//
					begin
						br_true = 1;
						case(instruction[14:12])
							3'b000://beq
									begin
										BrUn = 1'b1;
										PCSel = BrEq;
									end
							3'b001://bne
									begin
										BrUn = 1'b1;
										PCSel = ~BrEq;
									end
							3'b100://blt
									begin
										BrUn = 1'b0;
										PCSel = BrLt;
									end
							3'b101://bge
									begin
										BrUn = 1'b0;
										PCSel = ~BrLt;
									end
							3'b110://bltu
									begin
										BrUn = 1'b1;
										PCSel = BrLt;	
									end
							3'b111://bgeu
									begin
										BrUn = 1'b1;
										PCSel = ~BrLt;
									end
							default:
									begin
										BrUn = 1'b1;
										PCSel = BrEq;
									end
						endcase
						
						flush_ID = PCSel;
						Immsel = 3'b010;
						RegWEn = 1'b0;
						Asel = 1'b0;
						Bsel = 1'b1;
						Asel_br = 1'b0;//PC, RS1
						Bsel_br = 1'b0;//B_Imm,I_Imm
						ALUSel = 5'b00010;
						MemRW = 2'b00;
						WBsel = 2'b00;
						float_read = 2'b00;
						float_write = 1'b0;
						fpu_use = 1'b0;
					end
		7'b1101111://UJ//
					begin	
						br_true = 0;
						flush_ID = 1;
						BrUn = 1'b0;
						PCSel = 1'b1;
						Immsel = 3'b011;
						RegWEn = 1'b1;
						Asel = 1'b0;
						Bsel = 1'b1;
						Asel_br = 1'b0;//PC, RS1
						Bsel_br = 1'b0;//B_Imm,I_Imm
						ALUSel = 5'b00010;
						MemRW = 2'b00;
						WBsel = 2'b01;
						float_read = 2'b00;
						float_write = 1'b0;
						fpu_use = 1'b0;
					end
		7'b0010111://U//auipc
					begin	
						br_true = 0;
						flush_ID = 0;
						BrUn = 1'b0;
						PCSel = 1'b0;
						Immsel = 3'b100;
						RegWEn = 1'b1;
						Asel = 1'b1;
						Bsel = 1'b1;
						Asel_br = 1'b0;
						Bsel_br = 1'b0;
						ALUSel = 5'b00010;
						MemRW = 2'b00;
						WBsel = 2'b00;
						float_read = 2'b00;
						float_write = 1'b0;
						fpu_use = 1'b0;
					end
		7'b0110111://U//lui
					begin	
						br_true = 0;
						flush_ID = 0;
						BrUn = 1'b0;
						PCSel = 1'b0;
						Immsel = 3'b100;
						RegWEn = 1'b1;
						Asel = 1'b0;
						Bsel = 1'b1;
						Asel_br = 1'b0;
						Bsel_br = 1'b0;
						ALUSel = 5'b00001;
						MemRW = 2'b00;
						WBsel = 2'b00;
						float_read = 2'b00;
						float_write = 1'b0;
						fpu_use = 1'b0;
					end
					
		7'b0000111://flw
					begin
						br_true = 0;
						flush_ID = 0;
						BrUn = 1'b0;
						PCSel = 1'b0;
						Immsel = 3'b000;
						RegWEn = 1'b1;
						Asel = 1'b0;
						Bsel = 1'b1;
						Asel_br = 1'b0;
						Bsel_br = 1'b0;
						ALUSel = 5'b00010;
						MemRW = 2'b10;
						WBsel = 2'b10;
						float_read = 2'b00;
						float_write = 1'b1;
						fpu_use = 1'b0;
					end
					
		7'b0100111://fsw
					begin
						br_true = 0;
						flush_ID = 0;
						BrUn = 1'b0;
						PCSel = 1'b0;
						Immsel = 3'b001;
						RegWEn = 1'b0;
						Asel = 1'b0;
						Bsel = 1'b1;
						Asel_br = 1'b0;
						Bsel_br = 1'b0;
						ALUSel = 5'b00010;
						MemRW = 2'b01;
						WBsel = 2'b00;
						float_read = 2'b01;//rs1 = x, rs2 = f
						float_write = 1'b0;
						fpu_use = 1'b0;
					end
					
		7'b1010011:
					begin
						br_true = 0;
						flush_ID = 0;
						BrUn = 1'b0;
						PCSel = 1'b0;
						Immsel = 3'b000;
						RegWEn = 1'b1;
						Asel = 1'b0;
						Bsel = 1'b0;
						Asel_br = 1'b0;
						Bsel_br = 1'b0;
						case(instruction[31:27])
							5'b00000: begin ALUSel = 5'b00100; float_read = 2'b11; float_write = 1'b1;end//add
							5'b00001: begin ALUSel = 5'b00101; float_read = 2'b11; float_write = 1'b1;end//sub
							5'b00010: begin ALUSel = 5'b00110; float_read = 2'b11; float_write = 1'b1;end//mul
							5'b00101: begin ALUSel = (instruction[14:12]==0)? 5'b00111 : 5'b01000; float_read = 2'b11; float_write = 1'b1; end//min/max
							5'b10100: begin
											case(instruction[14:12])
												0: ALUSel = 5'b01011;//le
												1: ALUSel = 5'b01010;//lt
												2: ALUSel = 5'b01001;//eq
												default: ALUSel = 5'b00000;
											endcase
											float_read = 2'b11; float_write = 1'b0;
										end
							5'b11110: begin ALUSel = 5'b01100; float_read = 2'b00; float_write = 1'b1;end//mv-s-x
							5'b11100: begin ALUSel = 5'b01101; float_read = 2'b10; float_write = 1'b0;end//mv-x-s
							5'b11010: begin ALUSel = 5'b01110; float_read = 2'b00; float_write = 1'b1;end//cvt-s-w
							5'b11000: begin ALUSel = 5'b01111; float_read = 2'b10; float_write = 1'b0;end//cvt-w-s
							default: begin ALUSel = 5'b00000; float_read = 2'b00; float_write = 1'b0;end
						endcase
						MemRW = 2'b00;
						WBsel = 2'b00;
						fpu_use = 1'b1;
					end			
		default://ADD X0 X0 X0
					begin
						br_true = 0;
						flush_ID = 0;
						BrUn = 1'b0;
						PCSel = 1'b0;
						Immsel = 1'b0;
						RegWEn = 1'b0;
						Asel = 1'b0;
						Bsel = 1'b0;
						Asel_br = 1'b0;//PC, RS1
						Bsel_br = 1'b0;//B_Imm,I_Imm
						ALUSel = 5'b00000;
						MemRW = 2'b00;
						WBsel = 2'b00;
						float_read = 2'b00;
						float_write = 1'b0;
						fpu_use = 1'b0;
					end
	endcase
end
endmodule
