/************
 * TPC2 - Ex 2 - 2016/17 MIEI
 * DI/FCT/UNL
 ***********/
 
#include <stdio.h>
#include <stdlib.h>

#define MAX 20  // vamos aceitar vetores ate' esta dimensao

extern int prodInt( int v1[], int v2[], int len );


int main(int argc, char *argv[]) {
    int i, len;

    printf("Comprimento: ");
    fflush( stdout );
    if ( scanf("%d", &len)!= 1 || len>MAX || len<=0) {
        fprintf(stderr, "Dimensao errada!\n");
        return 1;
    }
    int v1[len], v2[len];

    for ( i=0; i<len; i++ )
        if ( scanf("%d", &v1[i])!= 1 ) {
            fprintf(stderr, "Valor errado!\n");
            return 2;
        }
    for ( i=0; i<len; i++ )
        if ( scanf("%d", &v2[i])!= 1 ) {
            fprintf(stderr, "Valor errado!\n");
            return 2;
        }
    int res = prodInt(v1, v2, len);
    printf("Produto interno = %d\n", res);
    return 0;    
}


