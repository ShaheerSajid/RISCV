#ifndef SERIAL_H_
#define SERIAL_H_


volatile int *uart_addr = (int*)0x11100;
volatile int *uart_rx_addr = (int*)0x11104;

void serial_putc(char);
void serial_puts(char*);
char serial_getc();
int serial_available();

void serial_putc(char c)
{

	*uart_addr = c;
	while((*uart_addr & (1 << 1)) == 0);

}

int serial_available()
{
	return (*uart_addr & 1);
}

void serial_puts(char *data)
{
	int x = 0;
	while (data[x] != 0)
		{
			serial_putc(data[x]);
			x++;
		}
}

char serial_getc()
{
	return *uart_rx_addr;
}

#endif

