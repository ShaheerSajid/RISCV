#include "libs/util/delay.h"
#include "libs/sys/serial/serial.h"
#include "libs/sys/gpio/gpio.h"
#include "libs/sys/timer/timer.h"
#include "libs/util/print.h"


#define SCALE 10000  
#define ARRINIT 2000  

void pi_digits(int digits) {  
  int carry = 0;  
  int arr[digits + 1];  
  for (int i = 0; i <= digits; ++i)  
    arr[i] = ARRINIT; 
  for (int i = digits; i > 0; i-= 14) {  
    int sum = 0;  
    for (int j = i; j > 0; --j) {  
      sum = sum * j + SCALE * arr[j];  
      arr[j] = sum % (j * 2 - 1);  
      sum /= j * 2 - 1;  
    } 
	 //printf("%04d",carry+sum/SCALE);
    carry = sum % SCALE;  
	
  }
  serial_putc('\n');
}

int main(void)
{
	
	gpio_mode(10,0);

	timer_set_prescaler(PRE_1);
	pi_digits(14*100/4);
  int cnt = timer_read_cnt();
  printf("100 PI digits\n");
	printf("Cycles: %d\n",cnt);
     while(1)
	 {
		 if(!gpio_read(10))
		 {
			 while(!gpio_read(10));
			printf("Pressed\n");
		 }
		 	
	 }

	
}
