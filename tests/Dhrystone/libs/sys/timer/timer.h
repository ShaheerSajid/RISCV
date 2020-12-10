#ifndef TIMER_H_
#define TIMER_H_


#define NO_CLOCK 0
#define PRE_1 1
#define PRE_8 2
#define PRE_32 3
#define PRE_64 4
#define PRE_128 5
#define PRE_256 6
#define PRE_1024 7



volatile int *timer_conf_addr = (int*)0x11200;
volatile int *timer_cnt_addr = (int*)0x11204;
volatile int *timer_comp_addr = (int*)0x11208;


void timer_set_prescaler(int);
void timer_set_compare(int);
int timer_read_conf();
int timer_read_cnt();


void timer_set_prescaler(int pre)
{
	*timer_conf_addr = pre;
}
void timer_set_compare(int pre)
{
	*timer_comp_addr = pre;
}
int timer_read_conf()
{
	return *timer_conf_addr;
}
int timer_read_cnt()
{
	return *timer_cnt_addr;
}
#endif

