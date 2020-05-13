void load_file() {
	int i;
	word w;
	scanf("%hx %hx", pc, i);
	while (i > 0) {
		scanf("%hx", w);
		w_write(pc, w);
		pc += 2;
		i--;
	}
}
