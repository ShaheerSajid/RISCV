#ifndef DELAY_H_
#define DELAY_H_

#define F_CPU 16000000
void delay_ms(int);
void delay_us(int);

void delay_us(int d)

{

	volatile int n = d*F_CPU/10000000;

	for(int i = 0; i < n; i++)

	{



	}

}

void delay_ms(int d)

{

	volatile int n = d*F_CPU/10000;

	for(int i = 0; i < n; i++)

	{



	}

}

#endif
