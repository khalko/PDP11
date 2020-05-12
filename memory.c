#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "run.c"

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

int main() {
	
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

