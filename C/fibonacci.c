/*
 *  fibonacci.c
 */
#include <stdio.h>
#include <stdlib.h>

extern int fibonacci( int n );

int main( int argc, char *argv[] ) {
    if (argc != 2) {
        fprintf( stderr, "use: %s <int_num>\n", argv[0] );
        return 1;
    }
    int n = atoi( argv[1] );
    int f = fibonacci( n );

    // print the results
    printf( "Fibonacci(%d)=%d\n", n, f );
    return 0;
}
