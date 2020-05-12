#include <stdio.h>
#include <stdlib.h>
#include "memory.c"


void run() {
	pc = 01000;
	while(1) {
		word w = w_read(pc);
		printf("%06o %06o: ", pc, w);
		pc += 2;
	if (w == 0) {
		printf("halt ");
		do_halt();
	}
	else if ((w & 0170000) == 0010000) {
		printf("mov ");
		do_mov();
	}
		else if ((w & 0170000) == 0060000) {
			printf("add ");
			do_add();
		}
			else
				printf("unknow ");
}
}
