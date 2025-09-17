#include <stdio.h>
#include <string.h>
int main() {
    long long a, i, num[ 35 ];
    while ( scanf( "%lld", &a ) != EOF ) {
        i = 0;
        memset( num, 0, sizeof( num ) );
        while ( a > 0 ) {
            num[ i++ ] = a % 2;
            a /= 2;
        }
        for ( i = 31; i >= 0; i-- )
            printf( "%d", num[ i ] );
        printf( "\n" );
    }
}
