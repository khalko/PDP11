#include <stdlib.h>
#include <stdio.h>

struct Arg {
	word val;
	word adr;
} ss, dd;

void do_mov() {
	w_write(dd.adr, ss.val);
}
void do_add() {}
void do_halt() {}

Arg get_mr(word w) {
	Arg res;
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
				printf("(R%o)+, r");
			break;
	}
	return res;
}