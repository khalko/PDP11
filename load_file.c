void load_file(){
    adr address;
    unsigned short int n;
    byte k = 0x00;
    int i;
    int j = 2;
    while(1) {

        j = scanf("%04hx%04hx", &address, &n);
        //printf("%d\n", j);
        if(j != 2){
            break;
        }
        for (i = 0; i < n; i++) {
            scanf("%02hhx", &k);
            b_write(address + i, k);
            //printf("scaned %d, i = %d, n = %d\n", k, i, n);
        }
    }
}
