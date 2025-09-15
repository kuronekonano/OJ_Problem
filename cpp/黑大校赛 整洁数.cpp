#include <stdio.h>
int main() {
    int       a[ 25 ], t, i, cas = 1;
    long long n;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%lld", &n );
        int num = 0;
        while ( n > 0 ) {
            a[ ++num ] = n % 10;
            n /= 10;
        }
        for ( i = 1; i < num; i++ ) {
            if ( a[ i ] < a[ i + 1 ] ) {
                a[ i + 1 ]--;
                for ( int j = i; j >= 0; j-- ) {
                    a[ j ] = 9;
                }
            }
        }
        printf( "Case #%d: ", cas++ );
        if ( num == 0 ) {
            printf( "0\n" );
            continue;
        }
        for ( i = num; i > 0; i-- ) {
            if ( a[ num-- ] == 0 )
                continue;
            printf( "%d", a[ i ] );
        }
        printf( "\n" );
    }
}
