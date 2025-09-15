#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 1e3 + 10;
int       n, a[ maxn ], ans[ maxn ], has[ maxn ][ maxn << 1 ];
int       main() {
    while ( scanf( "%d", &n ) != EOF ) {
        memset( has, 0, sizeof has );
        memset( ans, 0, sizeof ans );
        for ( int i = 0; i < n; i++ ) {
            scanf( "%d", &a[ i ] );
            int cnt = 0;
            for ( int j = i - 1; j >= 0; j-- ) {
                if ( a[ j ] > a[ i ] )
                    cnt++;
                else
                    cnt--;
                if ( !cnt )
                    ans[ i ]++;
                has[ i ][ cnt + maxn ]++;
            }
        }
        for ( int i = 0; i < n; i++ ) {
            int cnt = 0;
            for ( int j = i + 1; j < n; j++ ) {
                if ( a[ j ] < a[ i ] )
                    cnt++;
                else
                    cnt--;
                if ( !cnt )
                    ans[ i ]++;
                ans[ i ] += has[ i ][ maxn + cnt ];
            }
        }
        for ( int i = 0; i < n; i++ )
            printf( "%d%c", ans[ i ] + 1, i == n - 1 ? '\n' : ' ' );
    }
}
