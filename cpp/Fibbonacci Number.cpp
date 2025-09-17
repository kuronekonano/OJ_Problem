#include <stdio.h>
int main() {
    long long i, f[ 55 ], n, f1, f2;  // 前五十项，用long long
    while ( scanf( "%lld", &n ) != EOF ) {
        if ( n == -1 ) {
            return 0;
        }
        if ( n == 0 ) {
            printf( "0\n" );
        }
        if ( n == 1 || n == 2 ) {
            printf( "1\n" );
        }
        else if ( n > 2 ) {
            f1 = 1;
            f2 = 1;
            for ( i = 3; i <= 50; i++ ) {
                f[ i ] = f1 + f2;
                f1     = f2;
                f2     = f[ i ];
            }
            printf( "%lld\n", f[ n ] );
        }
    }
    return 0;
}
