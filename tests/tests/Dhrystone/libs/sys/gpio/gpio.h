#ifndef GPIO_H_
#define GPIO_H_

volatile int *gpio_ddr_addr = (int*)0x11000;
volatile int *gpio_addr = (int*)0x11004;

void gpio_mode(int, int);
void gpio_write(int, int);
int gpio_read(int);


void gpio_mode(int pin, int mode)
{
	if(mode)
		*gpio_ddr_addr |= (1<<pin);
	else
		*gpio_ddr_addr &= ~(1<<pin);

}
void gpio_write(int pin, int state)
{
	if(state)
		*gpio_addr |= (1<<pin);
	else
		*gpio_addr &= ~(1<<pin);
}

int gpio_read(int pin)
{
	return (*gpio_addr>>pin)&1;
}


#endif

