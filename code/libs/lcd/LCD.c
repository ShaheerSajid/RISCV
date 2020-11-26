#include "LCD.h"



void lcd_data_write(unsigned char data)
{
	out = 0;
	out |= data;
	out |= (1<<rs);
	out |= (1<<en);
	*gpio_addr = out;
	delay_us(1);
	//delay_ms(1000);
	out &= ~(1<<en);
	*gpio_addr = out;
	delay_us(100);
	//delay_ms(1000);
}
void lcd_cmd_write(unsigned char data)
{
	out = 0;
	out |= data;
	out |= (1<<en);
	*gpio_addr = out;
	delay_us(1);
	//delay_ms(1000);
	out &= ~(1<<en);
	*gpio_addr = out;
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
}

void print(char *data)
{
	int x = 0;
	while (data[x] != 0)
		{
			lcd_data_write(data[x]);
			x++;
		}
}


void init()
{
	out = 0;
	delay_ms(2);	
	//delay_ms(1000);
	lcd_cmd_write(0x38);
	lcd_cmd_write(0x0C);
	lcd_cmd_write(0x01);
	delay_ms(2);
	//delay_ms(1000);
	lcd_cmd_write(0x06);
}
void setCursor(unsigned char x, unsigned char y)
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
void clear()
{
	lcd_cmd_write(0x01); 
	lcd_cmd_write(0x02);
}
