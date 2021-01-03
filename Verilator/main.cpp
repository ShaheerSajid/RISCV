#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>  // for strtol

#define MEMBLK 1024
#include "VCore.h"
#include "verilated.h"



int main(int argc, char **argv) {
		
	 if (argc != 2) {
		printf("Usage: Please provide path to binfile\n");
		return -1;	
	}
	// Initialize Verilators variables
	Verilated::commandArgs(argc, argv);
	// Create an instance of our module under test
	VCore *tb = new VCore;
	// Tick the clock until we are done

	unsigned char *mem  = new unsigned char[65536];
	unsigned char block[4];
	int fd_i;
	struct stat fileinfo;
	//fd_i = open("../mem_init/sys_onchip_memory2_0.bin", O_RDONLY);
	//fstat(fd_i, &fileinfo);
	if ((fd_i = open(argv[1], O_RDONLY)) == -1 || fstat(fd_i, &fileinfo) == -1) {
		printf("Couldn't open file\n");
		return -1;
	}
	printf("size: %ld bytes\n", fileinfo.st_size);
	for (int i=0; i<fileinfo.st_size; i+=4) {
		read(fd_i, (void*)block, 4);
		printf("%.2x: %.2X%.2X%.2X%.2X\n",i,block[3],block[2],block[1],block[0]);
		mem[i] = block[0];
		mem[i+1] = block[1];
		mem[i+2] = block[2];
		mem[i+3] = block[3];
	}
	close(fd_i);
	unsigned int *timer = new unsigned int[2];
	unsigned int inst_data;
	unsigned int inst_addr;
	bool inst_stall;
	
	unsigned int avl_readdata;
	bool avl_waitrequest;
	unsigned int avl_address;
	unsigned int avl_writedata;
	unsigned int avl_byteenable;
	bool avl_read;
	bool avl_write;
	uint16_t avl_addr;
	
	
	printf("==============\n");
	printf("NUCORE RV32IMF Terminal\n");
	printf("==============\n");
	avl_waitrequest = 0;
	timer[0] = 0;
	timer[1] = 0;
	tb->reset = 0;
	tb->clk = 0;
	tb->eval();
	tb->reset = 0;
	tb->clk = 1;
	tb->eval();
	tb->reset = 0;
	tb->eval();
	
	while(true) {
		
		if(timer[0]) timer[1] = timer[1] + 1;
		
		
		
		
		tb->clk = 0;
		
		
		tb->eval();
		
		inst_addr = tb->inst_addr;
		avl_address = tb->avl_address;
	  	avl_addr = (avl_address>>(unsigned int)2)<<(unsigned int)2;
	  	avl_byteenable = tb->avl_byteenable;
	  	avl_read = tb->avl_read;
	  	avl_write = tb->avl_write;
	  	avl_readdata = (avl_address == 0x00011204)?timer[1]:(mem[avl_addr+3]<<24) | (mem[avl_addr+2]<<16) | (mem[avl_addr+1]<<8) | (mem[avl_addr]);
	  	avl_writedata = tb->avl_writedata;
		inst_data = (mem[inst_addr+3]<<24) | (mem[inst_addr+2]<<16) | (mem[inst_addr+1]<<8) | (mem[inst_addr]);
	  	
	  	tb->inst_data = inst_data;
	  	tb->avl_waitrequest = 0;
	  	tb->avl_readdata = avl_readdata;
	  	
	  	
	  	if(avl_write && avl_address == 0xFFFFFFFF)
	  		break;
		else if(avl_write && avl_address == 0x00011200)
			timer[0] = avl_writedata;
		else if(avl_write && avl_address == 0x00011204)
			timer[1] = avl_writedata;
		else if (avl_write && avl_address == 0x00011100)
			printf("%c", avl_writedata);
		else if (avl_write){
		
		if((avl_byteenable & 0x01)==0x01) mem[avl_addr]     = (unsigned char)avl_writedata;
		if((avl_byteenable & 0x02)==0x02) mem[avl_addr + 1] = (unsigned char)(avl_writedata>>8);
		if((avl_byteenable & 0x04)==0x04) mem[avl_addr + 2] = (unsigned char)(avl_writedata>>16);
		if((avl_byteenable & 0x08)==0x08) mem[avl_addr + 3] = (unsigned char)(avl_writedata>>24);
		}
		
		
		
		tb->clk = 1;
		
		
	  	tb->eval();
	  	
	  	inst_addr = tb->inst_addr;
		avl_address = tb->avl_address;
	  	avl_addr = (avl_address>>2)<<2;
	  	avl_byteenable = tb->avl_byteenable;
	  	avl_read = tb->avl_read;
	  	avl_write = tb->avl_write;
	  	avl_readdata = (avl_address == 0x00011204)?timer[1]:(mem[avl_addr+3]<<24) | (mem[avl_addr+2]<<16) | (mem[avl_addr+1]<<8) | (mem[avl_addr]);
	  	avl_writedata = tb->avl_writedata;
	  	
	  	tb->avl_waitrequest = 0;
	  	tb->avl_readdata = avl_readdata;
	  	
		
		
	} exit(EXIT_SUCCESS);
} 
