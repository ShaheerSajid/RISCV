#include "libs/sys/timer/timer.h"
#include "libs/util/delay.h"
#include "libs/sys/gpio/gpio.h"
#include "libs/sys/serial/serial.h"
#include "libs/util/print.h"
#include "libs/lcd/LCD.h"
#include "libs/dht11/dht.h"
#include <stdlib.h>


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

}

/*int main(void)
{
    gpio_mode(6,0);
	lcd(16,15,14,13,12,11,10,9,8,7);//init lcd
    lcd_init();
    lcd_setCursor(0,0);
    lcd_print("RISC  RESEARCH  LAB");

    timer_set_prescaler(PRE_1);
    unsigned int t1 = 0;
    unsigned int t2 = 0;

    
    while(1)
    {
        if(timer_read_cnt()-t1 > 100000000)
        {
            t1 = timer_read_cnt();
            lcd_setCursor(0,1);
            read_dht_data();
        }
        if(timer_read_cnt()-t2 > 20000000)
        {
            t2 = timer_read_cnt();
            lcd_setCursor(0,0);
            lcd_scroll(1);
           
        }
        //delay_ms(2000);
    }
}*/



/*#define  SCALE  10000
#define  ARRINIT  2000
int  main(void){

    timer_set_prescaler(PRE_1);
    while(1){
    *timer_cnt_addr = 0;
    int  digits = 100*14/4;
    int  carry = 0;
    int  arr[digits + 1];
    for (int  i = 0; i <= digits; ++i)
    arr[i] = ARRINIT;
    for (int  i = digits; i > 0; i-= 14) {
    int  sum = 0;
    for (int  j = i; j > 0; --j) {
    sum = sum * j + SCALE * arr[j];
    arr[j] = sum % (j * 2 - 1);
    sum /= j * 2 - 1;
    }
    printf("%04d",carry+sum/SCALE);
    carry = sum % SCALE;
    }
    int  cnt = timer_read_cnt();
    printf("\n100 PI digits\n");
    printf("Cycles: %d\n",cnt);
    delay_ms(1000);
    }
    
}*/

/*float sample[200] = {0,1.121494,1.140112,0.421019,0.182179,-0.488642,-0.420647,0.701751,1.394974,1.54778,-0.375197,-0.273316,0.300843,1.909302,2.067612,1.753117,0.044723,0.242673,0.055658,0.442419,2.166787,1.768076,0.842423,-0.468431,-0.334051,0.411782,0.728821,1.343049,1.01564,-0.529047,-0.847695,-0.715112,1.317595,0.776588,0.56743,0.198452,-1.572102,-0.995518,-0.309997,-0.279675,0.063628,-1.703665,-1.992628,-1.770286,-1.363982,0.302068,-0.121092,-0.80228,-1.594653,-1.822549,-0.851489,0.114765,0.210614,-0.325585,-0.517736,-1.768278,-1.25039,-0.962325,-0.062266,5.2E-05,-1.273429,-1.182356,-0.5551,-0.341479,1.039238,1.041999,0.661873,0.069982,-0.401099,0.849596,1.45526,1.8513,0.801799,0.565871,-0.224797,0.260336,2.209986,1.571444,1.610173,0.239419,-0.383913,0.345365,1.827651,1.788033,1.726464,-0.064441,-0.865414,-0.15641,1.030854,1.245787,1.297072,0.7642,-0.496135,-0.867589,-0.634803,1.28564,0.847298,0.796855,-0.525328,-1.108441,-0.824838,-0.993778,-0.154484,-0.229529,-1.954727,-1.639571,-1.51578,-0.541255,-0.418221,-0.178505,-0.976018,-2.630458,-1.862345,-1.095203,-0.281838,-0.101318,-0.635949,-1.946737,-1.837592,-1.6677,-0.734219,0.246201,0.323196,-0.672016,-1.12794,-1.015407,-0.028724,0.800074,0.986599,-0.434958,0.077524,-0.237187,0.136463,1.974563,1.668,1.547446,0.572501,-0.012939,1.002846,2.119653,2.207722,1.954194,0.334701,0.336629,0.124299,1.884285,1.621931,1.611181,-0.154565,-0.121724,0.108229,0.323857,0.915988,1.037912,-0.543608,-1.072132,-0.737607,-0.239538,0.2635,0.719596,-0.222272,-0.793271,-1.420475,-0.673288,0.212847,0.365936,0.202305,-1.738012,-1.709093,-1.765673,-0.363984,0.227095,-0.310177,-1.715031,-2.300128,-1.719033,-0.846179,0.119689,0.051818,-0.504991,-0.987576,-1.559313,-0.662118,0.384404,0.643346,0.180903,-0.037097,-0.881242,-0.837138,1.249217,0.595389,0.731281,-0.201103,-0.320761,-0.059074,-0.160357,0.910533,1.600672,0.313062,0.569976};
float outs[200] = {0};
float alpha = 0.1;
float var1 = 0;
float var2 = 0;
void lowPassFrequency(float* input, float* output, int points) 
{ 
    output[0] = input[0];
    for(int i = 1; i < points; ++i) 
    {  
        var1 = input[i] - output[i-1];
        var2 = alpha*var1;
        output[i] = output[i-1] + var2;

        int dec = (int)(100.0*(output[i]-(int)output[i]));
        if((int)output[i] < 0 || dec < 0) printf("-");
        printf("%d.", abs((int)output[i]));
        if(abs(dec) < 10) printf("0");
        printf("%d\n", abs(dec));
        
    } 
}     
void main (void){
   
        printf("LPF\n");
       lowPassFrequency(sample, outs, 200);
        while(1){}
}
*/
