 library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity uart_rx is
	generic(
		g_baudrate		: integer := 115200;
		g_clkrate		: integer := 50_000_000
		);
	port(
		i_clk			: in std_logic;
		i_rst			: in std_logic;
		i_rxd			: in std_logic;
		o_rx_dv			: out std_logic;
		o_rx_data		: out std_logic_vector(7 downto 0)
		);
end entity uart_rx;

architecture rtl of uart_rx is

	type t_state is (s_idle, s_get_start, s_get_data, s_done);
	signal f_state		: t_state;

	signal f_rxd		: std_logic;
	signal ff_rxd		: std_logic;
	signal fff_rxd		: std_logic;

	signal f_clk_cnt	: std_logic_vector(9 downto 0);
	signal f_bit_cnt	: std_logic_vector(2 downto 0);

	signal f_data		: std_logic_vector(7 downto 0);
	signal f_dv			: std_logic;

	constant k_clk_cnt_max	: integer := (g_clkrate / g_baudrate) - 1; -- Ticks per bit
	constant k_clk_cnt_mid	: integer := k_clk_cnt_max / 2; -- Mid point through bit

begin
	
	-- assign outputs
	o_rx_dv <= f_dv;
	o_rx_data <= f_data;

	-- sync the rx uart data bit
	process(i_clk)
	begin
		if(i_clk'event and i_clk = '1') then
			f_rxd 	<= i_rxd;
			ff_rxd 	<= f_rxd;
			fff_rxd <= ff_rxd;
		end if;
	end process;

	-- state machine
	process(i_clk, i_rst)
	begin
		if(i_rst = '1') then
			f_state <= s_idle;
		elsif(i_clk'event and i_clk = '1') then
			case f_state is
				when s_idle =>
				if(ff_rxd = '0' and fff_rxd = '1') then
					f_state <= s_get_start;
				end if;

				when s_get_start =>
				if(f_clk_cnt = k_clk_cnt_max) then
					f_state <= s_get_data;
				end if;

				when s_get_data =>
				if(f_clk_cnt = k_clk_cnt_max and f_bit_cnt = "111") then
					f_state <= s_done;
				end if;

				when s_done =>
					f_state <= s_idle;

				when others =>
				null;
			end case;
		end if;
	end process;

	-- clk counter
	process(i_clk, i_rst)
	begin
		if(i_rst = '1') then
			f_clk_cnt <= (others => '0');
		elsif(i_clk'event and i_clk = '1') then
			if(f_state = s_idle) then
				if(ff_rxd = '0' and fff_rxd = '1') then
					f_clk_cnt <= f_clk_cnt + '1';
				end if;
			else
				f_clk_cnt <= f_clk_cnt + '1';
			end if;
			if(f_clk_cnt =  k_clk_cnt_max) then
				f_clk_cnt <= (others => '0');
			end if;
		end if;
	end process;

	-- bit counter
	process(i_clk, i_rst)
	begin
		if(i_rst = '1') then
			f_bit_cnt <= (others => '0');
		elsif(i_clk'event and i_clk = '1') then
			if(f_state = s_idle) then
				f_bit_cnt <= (others => '0');
			elsif(f_state = s_get_data) then
				if(f_clk_cnt = k_clk_cnt_max) then
					f_bit_cnt <= f_bit_cnt + '1';
				end if;
			end if;
		end if;
	end process;

	-- get the data byte
	process(i_clk, i_rst)
	begin
		if(i_rst = '1') then
			f_data <= (others => '1');
		elsif(i_clk'event and i_clk = '1') then
			if(f_state = s_get_data) then
				if(f_clk_cnt = k_clk_cnt_mid) then
					f_data(conv_integer(f_bit_cnt)) <= fff_rxd;
				end if;
			end if;
		end if;
	end process;

	-- set the output read or write enable
	process(i_clk, i_rst)
	begin
		if(i_rst = '1') then
			f_dv <= '0';
		elsif(i_clk'event and i_clk = '1') then
			f_dv <= '0';
			if(f_state = s_done) then
				f_dv <=  '1';
			end if;
		end if;
	end process;

end architecture rtl;