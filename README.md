# 32 bit RISCV Implementation for FPGAs

This is a soft implementation of a processor on the opensource RISC-V ISA. The project was created on Intel Quartus Prime software and tested on DE10 lite. The processor features a single issue, in-order 4-stage pipeline. It currently supports integer, multiply and single precision IEEE compliant floating point(without float-div) instruction sets.

Initially a proof of concept was developed on logisim. It was at first a single cycle implementation which was later pipelined. Later on it was moved to verilog.

![enter image description here](https://raw.githubusercontent.com/ShaheerSajid/RISCV/master/images/RISCV.png)


Instructions are fetched at a latency of 1 clock cycle. There is a separate ALU for branch and jump address calculation located in the decode stage. Since the branch addresses are calculated in the decode stage, only a single cycle bubble is inserted when the branch is taken. 

To prevent data hazards, port forwarding is done in the decode and the execution stages. The forwarding unit for the decode stage forwards data from memory/write-back stage. Combining the memory and write-back stage removes the stall needed by instructions that immediately follow load instruction as the load data can be forwarded from write-back stage, however since branch is calculated in the decode stage, only then the pipeline is stalled for a single cycle so that the data from previous instruction is available for forwarding if the branch instruction asks for it.

The memory stage features an Avalon master that connects the processor to data memory and other peripherals via the Avalon bus. Currently the processor is equipped with GPIO, UART and TIMER peripherals. Read and write latency is 1 cycle. The Avalon wait-request signal is used to stall the core until the data is available from load. This can increase from more than 1 cycle depending on the type of memory/peripherals used.

The instruction and data memory are combined into a single dual port memory for the sake of using ISP in the future and to avoid separating the hex file generated by the compiler into instruction and data sections.

Interrupts are not supported at the moment. 

### Logic Utilization (Core only)

![enter image description here](https://raw.githubusercontent.com/ShaheerSajid/RISCV/master/images/logic.png)

## Benchmarks and Tests

### CoreMark
```
2K performance run parameters for coremark.
CoreMark Size    : 666u
Total ticks      : 1550779828u
Total time (secs): 31
Iterations/Sec   : 129
Iterations       : 4000u
Compiler version : GCC8.3.0
Compiler flags   : -O2,-DITERATIONS=4000, -mabi=ilp32, -march=rv32im (See Makefile)
Memory location  : STACK
seedcrc          : 0xe9f5
[0]crclist       : 0xe714
[0]crcmatrix     : 0x1fd7
[0]crcstate      : 0x8e3a
[0]crcfinal      : 0x65c5
Correct operation validated. See README.md for run and reporting rules.
```
**Coremark/mhz = 2.58**

![enter image description here](https://raw.githubusercontent.com/ShaheerSajid/RISCV/master/images/coremark.png)
*rv32im is without hard division


### Calculation of 100 PI digits:
```
#define  SCALE  10000
#define  ARRINIT  2000
int  main(void){
timer_set_prescaler(PRE_1);
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
}

Serial Window:

3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067
Cycles: 2282586
```

### Dhrystone
![enter image description here](https://raw.githubusercontent.com/ShaheerSajid/RISCV/master/images/dhry_out.png)
```
	 DMIPS/Mhz = ( (1/execution time) x runs) / (1757 x Frequency in Mhz) 
```

![enter image description here](https://raw.githubusercontent.com/ShaheerSajid/RISCV/master/images/dhry.png)



## Project

### Folder Structure
```
.
+-- _images
+-- _DE10 Lite
|	+--RISCV_CORE (Quartus Prime lite 18.1 project)
+-- _Code (vscode workspace)
+-- _tests 
|	+--Dhrystone (vscode workspace)
+-- _IPs (Platform Designer)
|	+--Core
|	+--gpio
|	+--timer
|	+--serial
```

### Steps to compile project:

 1. Download and install Quartus Prime Lite 18.1
 2. Open RISCV_CORE.qpf in DE10 Lite/RISCV_CORE
 3. Change device and pin assignments according to whatever device you are using
 4. Open tools/platform designer and edit system-on-chip ram IP. Give path of hex file generated by the compiler (See Programming section)
 6. Save and generate
 7. Compile Quartus project
 8. You only need to compile once after which just update memory initialization file and program device again.



## Programming

 1. Download riscv32 from the repository and extract in 'opt' folder. The directory should be as follows: opt/riscv32/bin.
 2. Download visual studio code and open the DE10 workspace in Code folder.
 3. Open link.riscv.ld and give absolute path of the file link.common.ld in the include section.
 4. Add your code to main.c.
 5. Click terminal/run build task.
 6. The file main.hex will be generated inside the flash folder.
 
 ### Libraries
	**GPIO:**
	void  gpio_mode(int, int); //pin(0-31), mode(input,output)
	void  gpio_write(int, int);//pin(0-31),HIGH,LOW
	int  gpio_read(int);//pin(0-31)
	**SERIAL:**
	int  serial_putc(int);//print char
	void  serial_puts(char*);//print string
	char  serial_getc();//get char
	int  serial_available();//if recv
	**TIMER:**
	void  timer_set_prescaler(int);//configure timer clock
	void  timer_set_compare(int);//enter compare value
	int  timer_read_conf();//read configuration register (OVF,CMPF,PRESCALER)
	int  timer_read_cnt();//read timer counter
	**UTIL:**
	printf ported to UART (Does not support floating yet)
	delay function
	**LCD:**
	1602 LCD  interfaced with GPIOs

## Examples

 - LCD
 - UART
 - TIMER


## ToDos

 - [ ] ISP
 - [ ] Interrupts
 - [ ] CSR 
 - [ ] Improve FMAX
	 - [ ] Optimize combinational cloud 
	 - [ ] Pipelined Div and Rem
	 - [ ] Pipelined FPU
 - [ ] Support for external flash
 - [ ] Support for SDRAM
 - [ ] Branch Prediction

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTIwNjAxMDMzMywxNDA3NjgwNjExLC04MD
IzOTgzNzEsMTIyNDc4OTM2MSwtMjA1MjU4MjY5OSwyOTg4MTQ5
OTgsLTExODAwOTkwNTIsMjA3NjY0MzI5MSwtODc2MTQ0ODEwLD
c2MTQxMjMwMiwtOTIyNjgyMTAsLTE3MTMyMjM2NTgsLTEyNzk5
MzIwNjAsMTY5Nzk4NTEyMCw4OTA3ODM3ODMsMTQzMjY1ODk0MC
wxMDE2MDY3OTMxLDMzODUyNjIwNywtMTkzMDgyMTcwNywxMjYz
MzI0NzA5XX0=
-->