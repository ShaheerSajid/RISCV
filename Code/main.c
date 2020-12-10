#include "libs/util/delay.h"
#include "libs/sys/serial/serial.h"
#include "libs/sys/gpio/gpio.h"
#include "libs/sys/timer/timer.h"
#include "libs/util/print.h"
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>


  //void _start();
  extern __attribute__((section (".reset"), naked))
  void _reset(){
    // setup the stack
    // must needed for both stdlib and newlib versions
    // since newlib assumes that stack has already been setup
    __asm(".option push\n"
          ".option norelax\n"
          "la gp, __global_pointer$\n"
          ".option pop");
    __asm("la sp, __stack_top");
    __asm("add s0, sp, zero");

   // _start();
  }

 

#define SCALE 10000  
#define ARRINIT 2000  



int main(void)
{

	gpio_mode(10,0);
	timer_set_prescaler(PRE_1);

  int digits = 100*14/4;
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
  int val;
  char snum[20];
  int cnt = timer_read_cnt();
  printf("\n100 PI digits\n");
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
