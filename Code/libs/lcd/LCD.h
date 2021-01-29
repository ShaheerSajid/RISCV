/*
 * LCD.h
 *
 * Created: 3/16/2019 12:56:15 PM
 *  Author: Shahe
 */ 

#ifndef LCD_H_
#define LCD_H_

	int rs;
	int en;
	int D0;
	int D1;
	int D2;
	int D3;
	int D4;
	int D5;
	int D6;
	int D7;
	int out = 0;
	void lcd(int Rs, int En, int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7);
	void lcd_data_write(unsigned char);
	void lcd_cmd_write(unsigned char);
	void lcd_print(char*);
	void lcd_init();
	void lcd_scroll();
	void lcd_setCursor(unsigned char, unsigned char);
	void lcd_clear();

	void lcd_data_write(unsigned char data)
	{
		//out = 0;
		//out |= data;
		//out |= (1<<rs);
		//out |= (1<<en);
		//*gpio_addr = out<<7;
		gpio_write(D0, (data&0x01)==0x01);
		gpio_write(D1, (data&0x02)==0x02);
		gpio_write(D2, (data&0x04)==0x04);
		gpio_write(D3, (data&0x08)==0x08);
		gpio_write(D4, (data&0x10)==0x10);
		gpio_write(D5, (data&0x20)==0x20);
		gpio_write(D6, (data&0x40)==0x40);
		gpio_write(D7, (data&0x80)==0x80);
		gpio_write(rs, 1);
		gpio_write(en, 1);
		delay_us(1);
		//delay_ms(1000);
		//out &= ~(1<<en);
		//*gpio_addr = out<<7;
		gpio_write(en, 0);
		delay_us(100);
		//delay_ms(1000);
	}
	void lcd_cmd_write(unsigned char data)
	{
		//out = 0;
		//out |= data;
		//out |= (1<<en);
		//*gpio_addr = out<<7;
		gpio_write(D0, (data&0x01)==0x01);
		gpio_write(D1, (data&0x02)==0x02);
		gpio_write(D2, (data&0x04)==0x04);
		gpio_write(D3, (data&0x08)==0x08);
		gpio_write(D4, (data&0x10)==0x10);
		gpio_write(D5, (data&0x20)==0x20);
		gpio_write(D6, (data&0x40)==0x40);
		gpio_write(D7, (data&0x80)==0x80);
		gpio_write(rs, 0);
		gpio_write(en, 1);
		delay_us(1);
		//delay_ms(1000);
		//out &= ~(1<<en);
		//*gpio_addr = out<<7;
		gpio_write(en, 0);
		delay_us(100);
		//delay_ms(1000);
	
	
	}

	void lcd(int Rs, int En, int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7)
	{
		rs = Rs;
		en = En;
		D0 = d0;
		D1 = d1;
		D2 = d2;
		D3 = d3;
		D4 = d4;
		D5 = d5;
		D6 = d6;
		D7 = d7;
		gpio_mode(rs,1);
		gpio_mode(en,1);
		gpio_mode(D0,1);
		gpio_mode(D1,1);
		gpio_mode(D2,1);
		gpio_mode(D3,1);
		gpio_mode(D4,1);
		gpio_mode(D5,1);
		gpio_mode(D6,1);
		gpio_mode(D7,1);
	}

	void lcd_print(char *data)
	{
		int x = 0;
		while (data[x] != 0)
			{
				lcd_data_write(data[x]);
				x++;
			}
	}


	void lcd_init()
	{
		//out = 0;
		delay_ms(2);	
		//delay_ms(1000);
		lcd_cmd_write(0x38);
		lcd_cmd_write(0x0C);
		lcd_cmd_write(0x01);
		delay_ms(2);
		//delay_ms(1000);
		lcd_cmd_write(0x06);
	}
	void lcd_setCursor(unsigned char x, unsigned char y)
	{
		unsigned char data = 0;
		if(y)
			data = 0xc0;
		else
			data = 0x80;
		data = data + x;
		
		lcd_cmd_write(data);
		delay_us(100);
		//delay_ms(1000);
	}
	void lcd_scroll(int dir)
{
	if(dir)
	lcd_cmd_write(0x18); //left
	else
	lcd_cmd_write(0x1C); //right
}
	void lcd_clear()
	{
		lcd_cmd_write(0x01); 
		lcd_cmd_write(0x02);
	}
#endif /* LCD_H_ */
