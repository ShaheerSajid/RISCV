#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>  // for strtol

#define MEMBLK 1024

int main(int argc, char **argv)
{
	unsigned char block[4];
	int fd_i;
	int cnt = 0;
	FILE *fd_o;
	FILE *fd_o_0;
	FILE *fd_o_1;
	FILE *fd_o_2;
	FILE *fd_o_3;
	struct stat fileinfo;
	
	unsigned int i;
	
	if (argc != 8) {
		printf("usage: %s binfile hexfiles flash_size\n", argv[0]);
		return -1;	
	}
	
	if ((fd_i = open(argv[1], O_RDONLY)) == -1 || fstat(fd_i, &fileinfo) == -1) {
		printf("Couldn't open file\n");
		return -1;
	}

    	printf("size: %u bytes\n", fileinfo.st_size);
	
	if ((fd_o = fopen(argv[2], "w")) == NULL) {
		printf("invalid outfile\n");
		return -1;
	}
	if ((fd_o_0 = fopen(argv[3], "w")) == NULL) {
		printf("invalid outfile\n");
		return -1;
	}
	if ((fd_o_1 = fopen(argv[4], "w")) == NULL) {
		printf("invalid outfile\n");
		return -1;
	}
	if ((fd_o_2 = fopen(argv[5], "w")) == NULL) {
		printf("invalid outfile\n");
		return -1;
	}
	if ((fd_o_3 = fopen(argv[6], "w")) == NULL) {
		printf("invalid outfile\n");
		return -1;
	}
	
	int num;
	num = strtol(argv[7], NULL, 10);
	
	for (i=0; i<fileinfo.st_size; i+=4) {
		read(fd_i, (void*)block, 4);
        if(i < num)
		fprintf(fd_o, "%.2X%.2X%.2X%.2X\n",block[3],block[2],block[1],block[0]);
	else{
		fprintf(fd_o_0, "%.2X\n",block[0]);
		fprintf(fd_o_1, "%.2X\n",block[1]);
		fprintf(fd_o_2, "%.2X\n",block[2]);
		fprintf(fd_o_3, "%.2X\n",block[3]);
	}
	
	}
	
	fclose(fd_o);
	fclose(fd_o_0);
	fclose(fd_o_1);
	fclose(fd_o_2);
	fclose(fd_o_3);
	close(fd_i);
	
	return 0;
}
