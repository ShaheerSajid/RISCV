library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.all;


entity uart_ip is
	port(
		signal clock 		: in std_logic;
		signal reset 		: in std_logic; 

		signal uart_TXD		: out std_logic;
		signal uart_RXD		: in std_logic;

		signal TX_start		: in std_logic;
		signal TX_data		: in std_logic_vector(7 downto 0);
		signal TX_done		: out std_logic;

		signal RX_data 		: out std_logic_vector(7 downto 0);
		signal RX_dv		: out std_logic
		);
end uart_ip;

architecture arch of uart_ip is

component uart_tx is
	port(
		i_clk		: in std_logic;
		i_rst		: in std_logic;
		i_start		: in std_logic;
		i_data		: in std_logic_vector(7 downto 0);
		o_done		: out std_logic;
		o_uart_tx	: out std_logic
		);
end component;

component uart_rx
	port(
		i_clk			: in std_logic;
		i_rst			: in std_logic;
		i_rxd			: in std_logic;
		o_rx_dv			: out std_logic;
		o_rx_data		: out std_logic_vector(7 downto 0)
		);
end component;

begin

u0: uart_tx
	port map(
		i_clk		=> clock,
		i_rst		=> reset,
		i_start		=> TX_start,
		i_data		=> TX_data,
		o_done		=> TX_done,
		o_uart_tx	=> uart_TXD
		);

u1: uart_rx
	port map(
		i_clk		=> clock,
		i_rst		=> reset,
		i_rxd		=> uart_RXD,
		o_rx_dv		=> RX_dv,
		o_rx_data	=> RX_data
		);

end architecture arch;