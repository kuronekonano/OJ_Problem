#include <stdio.h>
int main() {
    int i, n, vsum;
    while ( scanf( "%d", &n ) != EOF ) {
        int v[ n + 5 ];
        for ( i = 1; i <= n; i++ ) {
            scanf( "%d", &v[ i ] );
        }
        vsum = 0;
        for ( i = 1; i < n; i++ ) {
            if ( v[ i ] < 0 ) {
                vsum = v[ i ] - v[ i + 1 ];
            }
            else {
                vsum = v[ i ] + v[ i + 1 ];
            }
            v[ i + 1 ] = vsum;
        }
        printf( "%d\n", vsum );
    }
    return 0;
}
