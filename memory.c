#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned char byte;  //8 bit
typedef unsigned short int word;  // 16 bit
typedef word Adress;  // 16 bit

#define pc reg[7]
#define MEMSIZE (64 * 1024)

word reg[8];
byte mem[MEMSIZE];

void b_write(Adress adr, byte b);
byte b_read(Adress adr);
void w_write(Adress adr, word w);
word w_read(Adress adr);

struct Arg {
	word val;
	word adr;
} ss, dd;

void do_mov() {
	w_write(dd.adr, ss.val);
}
void do_add() {}
void do_halt() {
	exit(0);
}

struct Arg get_mr(word w) {
	struct Arg res;
	int r = w & 7;
	int mode = (w >> 3) & 7;
	switch(mode) {
		case 0:
			res.adr = r;
			res.val = reg[r];
			printf("R%o ", r);
			break;
		case 1:
			res.adr = reg[r];
			res.val = w_read(res.adr);
			printf("(R%o) ", r);
			break;
		case 2:
			res.adr = reg[r];
			res.val = w_read(res.adr);
			reg[r] += 2;
			if (r == 7)
				printf("#%o ", res.val);
			else 
				printf("(R%o)+", r);
			break;
	}
	return res;
}
void load_file() {
	int i;
	word w;
	scanf("%hx %x", &pc, &i);
	while (i > 0) {
		scanf("%hx", &w);
		w_write(pc, w);
		pc += 2;
		i--;
	}
}



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

int main() {
	load_file();
	run();	

	return 0;
}

void b_write(Adress adr, byte b) {
	mem[adr] = b;
}

byte b_read(Adress adr) {
	return mem[adr];
}

word w_read(Adress a) {
	word w = ((word)mem[a+1]) << 8;
	w = w | mem[a];
	return w;
}

void w_write(Adress adr, word w) {
	mem[adr+1] = w >> 8;
	mem[adr] = w << 8;
}

