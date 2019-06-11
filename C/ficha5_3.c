#include <stdio.h>
#include <stdlib.h>


extern int 
somaV(int v[], int num);


int 
main(int argc, char *argv[]) {
        int z;
        int x = argc-1;
        int v[x];
    if (argc == 1) {
        fprintf(stderr, "use: %s <int num>\n", argv[0]);
        return 1;
    }
    int i;
        
        for(i = 1;i<argc;i++){
            v[i-1] = atoi(argv[i]);
        }
        z = somaV(v,x);
    printf("z=%d\n", z);
    return 0;
}
