#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
const int Maxn = 20005;
int       a[ Maxn ], SA[ Maxn ], rank[ Maxn ], tax[ 1000006 ], tp[ Maxn ], height[ Maxn ], n, m;
void      Rsort() {
    for ( int i = 0; i <= m; i++ )
        tax[ i ] = 0;
    for ( int i = 1; i <= n; i++ )
        tax[ rank[ tp[ i ] ] ]++;
    for ( int i = 1; i <= m; i++ )
        tax[ i ] += tax[ i - 1 ];
    for ( int i = n; i >= 1; i-- )
        SA[ tax[ rank[ tp[ i ] ] ]-- ] = tp[ i ];
}
void SSA() {
    for ( int i = 1; i <= n; i++ )
        tp[ i ] = i;
    m = 1000000;
    Rsort();
    int p = 1, i;
    for ( int dis = 1; p < n; dis += dis, m = p ) {
        for ( p = 0, i = n - dis + 1; i <= n; i++ )
            tp[ ++p ] = i;
        for ( i = 1; i <= n; i++ )
            if ( SA[ i ] > dis )
                tp[ ++p ] = SA[ i ] - dis;
        Rsort();
        swap( rank, tp );
        rank[ SA[ 1 ] ] = p = 1;
        for ( int i = 2; i <= n; i++ )
            rank[ SA[ i ] ] = ( tp[ SA[ i ] ] == tp[ SA[ i - 1 ] ] && tp[ SA[ i ] + dis ] == tp[ SA[ i - 1 ] + dis ] ) ? p : ++p;
    }
    int j, k = 0;
    for ( i = 1; i <= n; height[ rank[ i++ ] ] = k )
        for ( k = k ? k - 1 : 0, j = SA[ rank[ i ] - 1 ]; a[ i + k ] == a[ j + k ]; ++k )
            ;
}
bool judge( int len, int k ) {
    int i = 1, cnt = 0;
    for ( int i = 1; i <= n; i++ ) {
        if ( height[ i ] >= len ) {
            cnt++;
            if ( cnt + 1 >= k )
                return true;
        }
        else
            cnt = 0;
    }
    return false;
}
int main() {
    int cnt[ Maxn ], k;
    while ( scanf( "%d%d", &n, &k ) != EOF ) {
        if ( n == 0 )
            break;
        memset( cnt, 0, sizeof( cnt ) );
        for ( int i = 1; i <= n; i++ ) {
            scanf( "%d", &a[ i ] );
            rank[ i ] = a[ i ];
        }
        SSA();
        //        for(int i=1;i<=n;i++)
        //        {
        //            printf("%d %d ",height[i],i);
        //            for(int j=SA[i];j<=n;j++)printf("%d",a[j]);
        //            printf("\n");
        //        }
        for ( int i = 1; i <= n; i++ )
            cnt[ height[ i ] ]++;
        int l = 1, r = n, mid, ans = 0;
        while ( l <= r )  /// 二分查找结果
        {
            mid = ( l + r ) / 2;
            if ( judge( mid, k ) )
                l = mid + 1, ans = mid;
            else
                r = mid - 1;
        }
        printf( "%d\n", ans );
    }
}
