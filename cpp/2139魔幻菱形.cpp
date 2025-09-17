#include <stdio.h>
int main() {
    int s, x, n, i, j;
    while ( scanf( "%d", &n ) != EOF ) {
        s = 1;
        for ( i = 1; i <= n / 2 + 1; i++ ) {
            for ( j = 1; j <= n / 2 + i - s; j++ ) {
                printf( " " );
            }
            for ( x = s; x > 0; x-- ) {
                printf( "*" );
            }
            for ( j = 1; j <= n / 2 + i - s; j++ ) {
                printf( " " );
            }
            for ( j = 1; j <= n / 2 + i - s; j++ ) {
                printf( " " );
            }
            for ( x = s; x > 0; x-- ) {
                printf( "*" );
            }
            printf( "\n" );
            s = s + 2;
        }
        s = n - 2;
        for ( i = n / 2; i >= 1; i-- ) {
            for ( j = 1; j <= n / 2 + i - s; j++ ) {
                printf( " " );
            }
            for ( x = s; x > 0; x-- ) {
                printf( "*" );
            }
            for ( j = 1; j <= n / 2 + i - s; j++ ) {
                printf( " " );
            }
            for ( j = 1; j <= n / 2 + i - s; j++ ) {
                printf( " " );
            }
            for ( x = s; x > 0; x-- ) {
                printf( "*" );
            }
            printf( "\n" );
            s = s - 2;
        }
    }
    return 0;
}
