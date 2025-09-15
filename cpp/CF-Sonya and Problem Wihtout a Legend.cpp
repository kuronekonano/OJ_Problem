#include <algorithm>  ///dp改动长度
#include <math.h>
#include <stdio.h>  ///改变为递增序列需要做的最小改动
using namespace std;
long long dp[ 3009 ][ 3008 ];
int       main() {
    int       i, j, n, t;
    long long a[ 3009 ], b[ 3008 ];
    while ( scanf( "%d", &n ) != EOF ) {

        for ( i = 1; i <= n; i++ ) {
            scanf( "%lld", &a[ i ] );
            a[ i ] = a[ i ] - i;
            b[ i ] = a[ i ];
        }
        sort( b + 1, b + n + 1 );
        for ( i = 1; i <= n; i++ ) {
            long long minn = 1e18;
            for ( j = 1; j <= n; j++ ) {
                minn         = min( minn, dp[ i - 1 ][ j ] );
                dp[ i ][ j ] = minn + abs( a[ i ] - b[ j ] );
            }
        }
        printf( "    " );
        for ( i = 1; i <= n; i++ )
            printf( "%3lld%c", a[ i ], i == n ? '\n' : ' ' );
        for ( i = 1; i <= n; i++ ) {
            printf( "%3lld ", b[ i ] );
            for ( j = 1; j <= n; j++ ) {
                printf( "%3lld%c", dp[ i ][ j ], j == n ? '\n' : ' ' );
            }
        }
        long long ans = 1e18;
        for ( i = 1; i <= n; i++ ) {
            ans = min( ans, dp[ n ][ i ] );
        }
        printf( "%lld\n", ans );
    }
    return 0;
}
