#include <algorithm>
#include <stdio.h>
#include <string.h>  ///身高从小到大，年龄是乱序
using namespace std;
struct num {
    long long pos, dig;
} a[ 100080 ];
bool cmp( num a, num b ) {
    if ( a.dig == b.dig )
        return a.pos > b.pos;
    return a.dig > b.dig;
}
int main() {
    long long age[ 100080 ], i, n, t, ans[ 100080 ];
    bool      flag[ 100080 ];
    scanf( "%lld", &t );
    while ( t-- ) {
        scanf( "%lld", &n );
        for ( i = 0; i < n; i++ ) {
            scanf( "%lld", &age[ i ] );
            a[ i ].pos = i;
            a[ i ].dig = age[ i ];
        }
        memset( ans, -1, sizeof( ans ) );
        memset( flag, false, sizeof( flag ) );
        sort( a, a + n, cmp );
        long long j = 0;
        for ( i = n - 1; i >= 0; i-- ) {
            if ( flag[ i ] )
                continue;
            while ( j < n ) {
                if ( age[ i ] == a[ j ].dig ) {
                    flag[ a[ j ].pos ] = true;
                    j++;
                    break;
                }
                ans[ a[ j ].pos ]  = i - a[ j ].pos - 1;
                flag[ a[ j ].pos ] = true;
                j++;
            }
        }
        for ( i = 0; i < n; i++ ) {
            printf( "%d%c", ans[ i ], i == n - 1 ? '\n' : ' ' );
        }
    }
    return 0;
}
