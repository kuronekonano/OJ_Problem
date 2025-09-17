#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int  x[ 50 ], y[ 50 ];
bool vis[ 300 ][ 300 ];
struct rec {
    int x1, y1, s, x2, y2;
};
bool cmp( rec a, rec b ) {
    return a.s > b.s;
}
int main() {
    int n, i, j;
    while ( scanf( "%d", &n ) != EOF ) {
        if ( n == 0 )
            return 0;
        memset( vis, false, sizeof( vis ) );
        for ( i = 0; i < n; i++ ) {
            scanf( "%d%d", &x[ i ], &y[ i ] );
            vis[ x[ i ] ][ y[ i ] ] = true;
        }
        int num = 0;
        rec a[ 1008 ];
        for ( i = 0; i < n; i++ ) {
            for ( j = i + 1; j < n; j++ ) {
                if ( x[ i ] == x[ j ] || y[ i ] == y[ j ] )
                    continue;
                if ( vis[ x[ i ] ][ y[ j ] ] && vis[ x[ j ] ][ y[ i ] ] ) {
                    num++;
                    int dx = abs( x[ i ] - x[ j ] ), dy = abs( y[ i ] - y[ j ] );
                    a[ num ].x1 = min( x[ i ], x[ j ] );
                    a[ num ].y1 = min( y[ i ], y[ j ] );
                    a[ num ].x2 = max( x[ i ], x[ j ] );
                    a[ num ].y2 = max( y[ i ], y[ j ] );
                    a[ num ].s  = dx * dy;
                }
            }
        }
        sort( a + 1, a + num + 1, cmp );
        int ans = 0, tmp = 0;
        for ( i = 1; i <= num; i++ ) {
            for ( j = i + 1; j <= num; j++ ) {
                if ( a[ i ].x1 < a[ j ].x1 && a[ i ].y1 < a[ j ].y1 && a[ i ].x2 > a[ j ].x2 && a[ i ].y2 > a[ j ].y2 ) {
                    ans = max( ans, a[ i ].s );
                    continue;
                }
                if ( ( a[ i ].x1 >= a[ j ].x1 && a[ i ].x1 <= a[ j ].x2 && a[ i ].y1 >= a[ j ].y1 && a[ i ].y1 <= a[ j ].y2 )
                     || ( a[ i ].x2 >= a[ j ].x1 && a[ i ].x2 <= a[ j ].x2 && a[ i ].y1 >= a[ j ].y1 && a[ i ].y1 <= a[ j ].y2 )
                     || ( a[ j ].x1 >= a[ i ].x1 && a[ j ].x1 <= a[ i ].x2 && a[ j ].y1 >= a[ i ].y1 && a[ j ].y1 <= a[ i ].y2 )
                     || ( a[ j ].x2 >= a[ i ].x1 && a[ j ].x2 <= a[ i ].x2 && a[ j ].y1 >= a[ i ].y1 && a[ j ].y1 <= a[ i ].y2 ) )
                    continue;
                //                printf("=======%d %d   %d %d
                //                %d\n",a[i].x1,a[i].y1,a[i].x2,a[i].y2,a[i].s);
                //                printf("-------%d %d   %d %d
                //                %d\n\n",a[j].x1,a[j].y1,a[j].x2,a[j].y2,a[j].s);
                ans = max( ans, a[ i ].s + a[ j ].s );
            }
        }
        if ( ans == 0 )
            printf( "imp\n" );
        else
            printf( "%d\n", ans );
    }
}
