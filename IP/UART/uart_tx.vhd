-- Description: UART Transmitter Logic

Library ieee;
	use ieee.std_logic_1164.all;

entity uart_tx is
	generic(
		g_baudrate	: integer := 115200; --115200;
		g_clkrate	: integer := 50_000_000 --50000000
		);
	port(
		i_clk		: in std_logic;
		i_rst		: in std_logic;
		i_start		: in std_logic;
		i_data		: in std_logic_vector(7 downto 0);
		o_done		: out std_logic;
		o_uart_tx	: out std_logic
		);
end entity uart_tx;

architecture behave of uart_tx is

	constant k_max_count 	: integer := (g_clkrate/g_baudrate) - 1;
	signal f_clk_count		: integer range 0 to k_max_count;
	signal f_bit_count		: integer range 0 to 7;
	signal f_done			: std_logic;
	signal f_uart_tx		: std_logic;

	type t_state is (s_idle, s_start, s_data, s_stop);
	signal f_state			: t_state;

begin

	-- assign outputs
	o_done <= f_done;
	o_uart_tx <= f_uart_tx;

	-- state machine
	process(i_clk, i_rst)
	begin
		if(i_rst = '1') then
			f_state <= s_idle;
		elsif (rising_edge(i_clk)) then
			case f_state is
				when s_idle =>
					if(i_start = '1') then
						f_state <= s_start;
					end if;

				when s_start =>
					if(f_clk_count = k_max_count) then
						f_state <= s_data;
					end if;

				when s_data =>
					if(f_clk_count = k_max_count) then 
						if(f_bit_count = 7) then
							f_state <= s_stop;
						end if;
					end if;

				when s_stop =>
					if(f_clk_count = k_max_count) then
						f_state <= s_idle;
					end if;

				when others =>
					null;
			end case;
		end if;
	end process;

-- Clock Counter
	process(i_clk, i_rst)
	begin
		if(i_rst = '1') then
			f_clk_count <= 0;
		elsif(rising_edge(i_clk)) then
			if(f_state = s_idle) then
				f_clk_count <= 0;
			else
				if(f_clk_count = k_max_count) then
					f_clk_count <= 0;
				else
					f_clk_count <= f_clk_count + 1;
				end if;
			end if;
		end if;
	end process;

-- Bit Counter
	process(i_clk, i_rst)
	begin
		if(i_rst = '1') then
			f_bit_count <= 0;
		elsif(rising_edge(i_clk)) then
			if(f_state = s_idle) then
				f_bit_count <= 0;
			elsif(f_state = s_data) then
				if(f_clk_count = k_max_count) then
					if(f_bit_count = 7) then
						f_bit_count <= 0;
					else
						f_bit_count <= f_bit_count + 1;
					end if;
				end if;
			end if;
		end if;
	end process;

-- Output tx data
	process(i_clk)
	begin
		if(rising_edge(i_clk)) then
			case f_state is
				when s_idle =>
					f_uart_tx <= '1';
				when s_start =>
					f_uart_tx <= '0';
				when s_data =>
					f_uart_tx <= i_data(f_bit_count);
				when s_stop =>
					f_uart_tx <= '1';

				when others =>
					null;
			end case;
		end if;
	end process;

-- Output done signal
	process(i_clk)
	begin
		if(rising_edge(i_clk)) then
			if(f_state = s_stop and f_clk_count = k_max_count) then
				f_done <= '1';
			else
				f_done <= '0';
			end if;
		end if;
	end process;

end architecture behave;