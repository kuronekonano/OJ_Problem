#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
    int t, i, j, b, m, n, a[ 101 ][ 101 ];
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d%d", &n, &m );
        if ( n == 1 ) {
            for ( i = 1; i <= m; i++ ) {
                for ( j = 1; j <= i; j++ ) {
                    printf( "%d*%d=%d%c", j, i, j * i, j == i ? '\n' : ' ' );
                }
            }
        }
        if ( n == 2 ) {
            for ( i = 0; i < m; i++ ) {
                for ( j = 0; j <= i; j++ ) {
                    if ( j == 0 || j == i ) {
                        a[ i ][ j ] = 1;
                    }
                    else {
                        a[ i ][ j ] = a[ i - 1 ][ j - 1 ] + a[ i - 1 ][ j ];
                    }
                }
            }
            for ( i = 0; i < m; i++ ) {
                for ( j = 0; j <= i; j++ ) {
                    printf( "%d", a[ i ][ j ] );
                    if ( j < i ) {
                        printf( " " );
                    }
                }
                printf( "\n" );
            }
        }
        if ( n == 3 ) {
            int b[ 101 ][ 101 ], c[ 101 ][ 101 ];
            int flag = 1;
            for ( i = 1; i <= m; i++ ) {
                for ( j = 1; j <= m; j++ ) {
                    a[ i ][ j ] = flag;
                    flag++;
                }
            }
            for ( i = 1; i <= m; i++ ) {
                for ( j = 1; j <= m; j++ ) {
                    b[ i ][ j ] = a[ m + 1 - j ][ i ];
                }
            }
            memset( c, 0, sizeof( c ) );
            for ( i = 1; i <= m; i++ ) {
                for ( j = 1; j <= m; j++ ) {
                    c[ i ][ j ] = a[ i ][ j ] * b[ i ][ j ];
                }
            }
            for ( i = 1; i <= m; i++ ) {
                for ( j = 1; j <= m; j++ ) {
                    printf( "%d%c", c[ i ][ j ], j == m ? '\n' : ' ' );
                }
            }
        }
    }
    return 0;
}
