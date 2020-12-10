/*
Read address 0 = 30'b0, tx_done, rx_valid
Read address 1 = 24'b0, rx_data

Write on any address is a write on udr_tx(lower 8 bits)

TX_done bit is always 1 unless uart is busy in sending data
RX_valid indicates if receiver has received any data. This bit automatically clears when MCU reads rx_data.

*/
module uart_ip_avalon_interface(clock, resetn, address, writedata, readdata, write, read,
 chipselect, waitrequest , TX_export, RX_export);

// signals for connecting to the Avalon fabric
input clock, resetn, read, write, chipselect;
input  address;
input [31:0] writedata;
output [31:0] readdata;
output waitrequest;
// signal for exporting register contents outside of the embedded system
output TX_export;
input RX_export;

wire tx_done_indicator, rx_valid_indicator;
reg tx_done, rx_valid;
wire [7:0] rx_data;
reg [7:0] udr_tx;

assign waitrequest = 1'b0;

/*always@(posedge clock)//Read data
if (resetn)
	readdata <= 32'b0;
else
begin
	case({read,address})
		2'b10: readdata <= {29'd0, 1'b1, tx_done, rx_valid};//
		2'b11: readdata <= {24'd0, rx_data};
		default: readdata <= 32'b0;
	endcase
end
*/

assign readdata = (read & ~resetn)?(~address)?{30'b0,tx_done, rx_valid}:{24'b0, rx_data}:32'd0;
always@(posedge clock)begin//Write data
	if (resetn)
		udr_tx <= 8'b0;
	else
	begin
		if(write & chipselect) udr_tx<= writedata[7:0];
		else udr_tx <= udr_tx;
	end
end

always@(posedge clock)begin//tx_done Block
	if (resetn)
		tx_done <= 1'b0;
	else
	begin
		if(chipselect & write)//start sending
			tx_done <= 1'b0;
		else if(tx_done_indicator)//since indicator is ony high for 1 cycle
			tx_done <= 1'b1;
		else
			tx_done <= tx_done;
	end
end

uart_ip_verilog_wrapper inst1(
	.clock(clock),
	.reset(resetn),

	.uart_TXD(TX_export),
	.uart_RXD(RX_export),

	.TX_start(chipselect & write),
	.TX_data(udr_tx),
	.TX_done(tx_done_indicator),

	.RX_data(rx_data),
	.RX_dv(rx_valid_indicator)
);

always@(posedge clock)begin//rx_valid Block
	if (resetn)
		rx_valid <= 1'b0;
	else
	begin
		if(read ==1'b1 && address == 1'b1)//read rx_data
			rx_valid <= 1'b0;
		else if(rx_valid_indicator)//since indicator is ony high for 1 cycle
			rx_valid <= 1'b1;
		else
			rx_valid <= rx_valid;
	end
end

endmodule
