module vidor_riscv
(
  // system signals
  input         iCLK,
  input         iRESETn,

  input         iSAM_INT,
  output        oSAM_INT,

  // SDRAM
  output        oSDRAM_CLK,
  output [11:0] oSDRAM_ADDR,
  output [1:0]  oSDRAM_BA,
  output        oSDRAM_CASn,
  output        oSDRAM_CKE,
  output        oSDRAM_CSn,
  inout  [15:0] bSDRAM_DQ,
  output [1:0]  oSDRAM_DQM,
  output        oSDRAM_RASn,
  output        oSDRAM_WEn,

  // SAM D21 PINS
  inout         bMKR_AREF,
  inout  [6:0]  bMKR_A,
  inout  [14:0] bMKR_D,

  // Mini PCIe
  inout         bPEX_RST,
  inout         bPEX_PIN6,
  inout         bPEX_PIN8,
  inout        bPEX_PIN10,
  input         iPEX_PIN11,
  inout         bPEX_PIN12,
  input         iPEX_PIN13,
  inout         bPEX_PIN14,
  inout         bPEX_PIN16,
  inout         bPEX_PIN20,
  input         iPEX_PIN23,
  input         iPEX_PIN25,
  inout         bPEX_PIN28,
  inout         bPEX_PIN30,
  input         iPEX_PIN31,
  inout         bPEX_PIN32,
  input         iPEX_PIN33,
  inout         bPEX_PIN42,
  inout         bPEX_PIN44,
  inout         bPEX_PIN45,
  inout         bPEX_PIN46,
  inout         bPEX_PIN47,
  inout         bPEX_PIN48,
  inout         bPEX_PIN49,
  inout         bPEX_PIN51,

  // NINA interface
  inout         bWM_PIO1,
  inout         bWM_PIO2,
  inout         bWM_PIO3,
  inout         bWM_PIO4,
  inout         bWM_PIO5,
  inout         bWM_PIO7,
  inout         bWM_PIO8,
  inout         bWM_PIO18,
  inout         bWM_PIO20,
  inout         bWM_PIO21,
  inout         bWM_PIO27,
  inout         bWM_PIO28,
  inout         bWM_PIO29,
  inout         bWM_PIO31,
  input         iWM_PIO32,
  inout         bWM_PIO34,
  inout         bWM_PIO35,
  inout         bWM_PIO36,
  input         iWM_TX,
  inout         oWM_RX,
  inout         oWM_RESET,

  // HDMI output
  output [2:0]  oHDMI_TX,
  output        oHDMI_CLK,

  inout         bHDMI_SDA,
  inout         bHDMI_SCL,

  input         iHDMI_HPD,

  // MIPI input
  input  [1:0]  iMIPI_D,
  input         iMIPI_CLK,
  inout         bMIPI_SDA,
  inout         bMIPI_SCL,
  inout  [1:0]  bMIPI_GP,

  // S-SPI Flash interface
//  output        oFLASH_MOSI,
//  input         iFLASH_MISO,
//  output        oFLASH_SCK,
//  output        oFLASH_CS,
//  output        oFLASH_WP,
//  output        oFLASH_HOLD

  // Q-SPI Flash interface
  output        oFLASH_SCK,
  output        oFLASH_CS,
  inout         oFLASH_MOSI,
  inout         iFLASH_MISO,
  inout         oFLASH_HOLD,
  inout         oFLASH_WP

);

wire [31:0] inst_data;
wire [31:0] inst_addr;
wire inst_stall;
wire u_clk, c_clk;
wire [13:0]num;
//#################################################
// internal oscillator
wire        wOSC_CLK;
cyclone10lp_oscillator   osc
( 
  .clkout(wOSC_CLK),
  .oscena(1'b1)
);
uart_pll	uart_pll_inst (
	.inclk0 ( iCLK ),
	.c0 ( u_clk ),
	.c1 ( c_clk )
	);
	
system system_inst (
		.uart_clk_clk  (u_clk),  // uart_clk.clk
      .clk_clk       (c_clk),       //   clk.clk
      .reset_reset_n (iRESETn), // reset.reset_n
      .gpio_port     ({	  num,
								  bPEX_RST,
								  bPEX_PIN6,
								  bPEX_PIN8,
								  bPEX_PIN10,
								  bPEX_PIN12,
								  bPEX_PIN14,
								  bPEX_PIN16,
								  bPEX_PIN20,  
								  bPEX_PIN28,
								  bPEX_PIN30,
								  bPEX_PIN32,
								  bPEX_PIN44,
								  bPEX_PIN45,
								  bPEX_PIN46,
								  bPEX_PIN47,
								  bPEX_PIN48,
								  bPEX_PIN49,
								  bPEX_PIN51
							}),     //  gpio.port
		.uart_rx       (iPEX_PIN11),       //  uart.rx
      .uart_tx       (bPEX_PIN42),        //      .tx
		
		  .flash_address    (inst_addr),    //    flash.address
        .flash_chipselect (1'b1), //         .chipselect
        .flash_clken      (~inst_stall),      //         .clken
        .flash_write      (1'b0),      //         .write
        .flash_readdata   (inst_data),   //         .readdata
        .flash_writedata  (),  //         .writedata
        .flash_byteenable (4'b0000), //         .byteenable
		  
        .flash_1_addr     (inst_addr),     //  flash_1.addr
        .flash_1_data     (inst_data),     //         .data
        .flash_1_stall    (inst_stall)    //         .stall
  
);

//##################################################
endmodule
