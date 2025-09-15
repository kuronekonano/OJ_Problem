#include <stdio.h>
int t, n, m, k, p, a[ 1000006 ], b[ 1000006 ], i, j, cas = 0;
int main() {
    scanf( "%d", &t );
    while ( t-- ) {
        int ans = 0;
        cas++;
        scanf( "%d%d%d", &n, &m, &p );
        for ( i = 1; i <= n; i++ )
            scanf( "%d", &a[ i ] );
        for ( i = 1; i <= m; i++ )
            scanf( "%d", &b[ i ] );
        for ( i = 1; i + ( m - 1 ) * p <= n; i++ ) {
            for ( j = i, k = 1; k <= m; j += p, k++ ) {
                if ( a[ j ] != b[ k ] )
                    break;
            }
            if ( k > m )
                ans++;
        }
        printf( "Case #%d: %d\n", cas, ans );
    }
}
