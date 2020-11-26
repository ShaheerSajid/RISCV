# 32 bit RISCV Implementation for FPGAs

This is a soft implementation of a processor on the opensource RISC-V ISA. The project was created on Intel Quartus Prime software and tested on DE10 lite.

![enter image description here](https://raw.githubusercontent.com/ShaheerSajid/RISCV/master/images/RISCV.png)

## Specifications

 - 32 bit
 - In-order, single issue, 5-stage pipeline
 - Supported instruction sets: I, M(without div and rem), F(without div)
 - Avalon data bus
 - Single cycle multiply and floating hardware
 - 16KB Instruction Memory and 32KB Data Memory. (Configurable)
 - Logic Utilization (Core only):
	- Logic Cells: 4366
	- Logic Registers: 802
	 - Memory Bits: 4096

## Benchmarks and Tests

 - Fmax: 20Mhz
	- Current CPU frequency is 16Mhz
 - Calculation of 100 PI digits:
	 - 3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067
	 - Cycles: 1728973
 - Dhrystone
  ![enter image description here](https://raw.githubusercontent.com/ShaheerSajid/RISCV/master/images/dhry.png)
	 - DMIPS/Mhz : 1.13

	

## Project

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
Steps to compile project:

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
 7. The folder libs contain libraries of the available peripherals

## Examples




## ToDos


<!--stackedit_data:
eyJoaXN0b3J5IjpbMTY5NzY5NjI5LDEwMjcyMTI5NzEsLTIwMD
Y2MTAwMzIsMzI4NDU4NzUyLC0xNzU0MzY4NTI5LC0xNDE4OTQz
NTEsNDQzMjgzNjA0LDQ1NTE1NTUyMl19
-->