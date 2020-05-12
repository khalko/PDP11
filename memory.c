#include <stdio.h>

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
	b_write(4, 0x0a);
	b_write(3, 0x0b);
	word wres = w_read(4);
	printf("%04hhx\n", wres);
	

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
	mem[adr++] = w >> 8;
	mem[adr] = w << 8;
}

