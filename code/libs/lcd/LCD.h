/*
 * LCD.h
 *
 * Created: 3/16/2019 12:56:15 PM
 *  Author: Shahe
 */ 

#include <stdio.h>
#include <stdlib.h>
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
	char buf[16];
	int out = 0;
	void lcd(int Rs, int En, int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7);
	void writePin(int ,int);
	void clrPin(int);
	void lcd_data_write(unsigned char);
	void lcd_cmd_write(unsigned char);
	void port_clr();
	void print2(char*);	
	void print(char*);
	void init();
	void createChar(unsigned char , unsigned char*);
	void setCursor(unsigned char, unsigned char);
	void scroll(int);
	void clear();
	void autoScroll(int);
	void delay_ms(int);
	void delay_us(int);
#endif /* LCD_H_ */
