#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
    int i, n, t, k, a[ 208 ], b[ 208 ], j, dp[ 208 ][ 208 ], cas = 0;
    scanf( "%d", &t );
    while ( t-- ) {
        cas++;
        scanf( "%d", &n );
        for ( i = 1; i <= n; i++ ) {
            scanf( "%d", &a[ i ] );
        }
        for ( i = 1; i <= n; i++ ) {
            scanf( "%d", &b[ i ] );
        }
        for ( int l = 1; l <= n; l++ ) {
            for ( i = 1; i <= n - l + 1; i++ ) {
                j            = l + i - 1;
                dp[ i ][ j ] = 0x7fffffff;
                for ( k = i; k <= j; k++ ) {
                    dp[ i ][ j ] = min( dp[ i ][ j ], dp[ i ][ k - 1 ] + dp[ k + 1 ][ j ] + a[ k ] + b[ i - 1 ] + b[ j + 1 ] );
                }
            }
        }
        printf( "Case #%d: %d\n", cas, dp[ 1 ][ n ] );
    }
}
