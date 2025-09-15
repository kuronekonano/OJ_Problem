#include <stdio.h>
int main() {
    int t, i, j, a[ 15 ][ 15 ], b[ 15 ];
    scanf( "%d", &t );
    while ( t-- ) {
        for ( i = 0; i < 9; i++ ) {
            scanf( "%d", &b[ i ] );
        }
        int k = 0;
        for ( j = 0; j < 3; j++ ) {
            for ( i = 0; i < 3; i++ ) {
                a[ i ][ j ] = b[ k++ ];
            }
        }
        for ( i = 0; i < 3; i++ ) {
            for ( j = 0; j < 3; j++ ) {
                printf( "%d%c", a[ i ][ j ], j == 2 ? '\n' : ' ' );
            }
        }
        printf( "\n" );
    }
    return 0;
}
