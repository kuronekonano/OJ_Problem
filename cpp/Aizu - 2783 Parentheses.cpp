#include <stdio.h>
int main() {
    long long n, i;
    while ( scanf( "%lld", &n ) != EOF ) {
        long long len = 1;
        while ( len * ( len + 1 ) < 2 * n )
            len++;
        long long num = len * ( len + 1 ) / 2 - n;
        for ( i = len; i >= 1; i-- ) {
            if ( i == num )
                printf( "(" );
            printf( ")" );
        }
        for ( i = len; i >= 2; i-- ) {
            printf( "(" );
        }
        if ( num == 0 )
            printf( "(\n" );
        else
            printf( "\n" );
    }
}
