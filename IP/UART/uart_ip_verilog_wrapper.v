module uart_ip_verilog_wrapper (
	input 		clock,
	input 		reset,

	output 		uart_TXD,
	input 		uart_RXD,

	input 		TX_start,
	input [7:0] TX_data,
	output 		TX_done,

	output [7:0]RX_data,
	output RX_dv
);

uart_ip u0(
	.clock(clock),
	.reset(reset),

	.uart_TXD(uart_TXD),
	.uart_RXD(uart_RXD),

	.TX_start(TX_start),
	.TX_data(TX_data),
	.TX_done(TX_done),

	.RX_data(RX_data),
	.RX_dv(RX_dv)
	);

endmodule