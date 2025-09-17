#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 1e5 + 10;
int       main() {
    int n, vis[ 10 ];
    while ( scanf( "%d", &n ) != EOF ) {
        memset( vis, 0, sizeof vis );
        int tmp, ans = 0;
        for ( int i = 1; i <= n; i++ )
            scanf( "%d", &tmp ), vis[ tmp ]++;
        ans += vis[ 5 ];
        vis[ 5 ] = 0;
        ans += min( vis[ 1 ], vis[ 4 ] );
        if ( vis[ 1 ] <= vis[ 4 ] )
            vis[ 4 ] -= vis[ 1 ], vis[ 1 ] = 0;
        else
            vis[ 1 ] -= vis[ 4 ], vis[ 4 ] = 0;
        ans += min( vis[ 2 ], vis[ 3 ] );
        if ( vis[ 2 ] <= vis[ 3 ] )
            vis[ 3 ] -= vis[ 2 ], vis[ 2 ] = 0;
        else
            vis[ 2 ] -= vis[ 3 ], vis[ 3 ] = 0;
        tmp = vis[ 2 ] / 2;
        ans += min( vis[ 1 ], tmp );
        if ( tmp <= vis[ 1 ] )
            vis[ 1 ] -= tmp, vis[ 2 ] %= 2;
        else
            vis[ 2 ] -= 2 * vis[ 1 ], vis[ 1 ] = 0;
        tmp = vis[ 1 ] / 2;
        ans += min( vis[ 3 ], tmp );
        if ( tmp <= vis[ 3 ] )
            vis[ 3 ] -= tmp, vis[ 1 ] %= 2;
        else
            vis[ 1 ] -= 2 * vis[ 3 ], vis[ 3 ] = 0;
        ans += vis[ 1 ] / 5;
        vis[ 1 ] %= 5;
        if ( vis[ 1 ] != 1 )
            vis[ vis[ 1 ] % 5 ]++, vis[ 1 ] = 0;
        ans += vis[ 2 ] / 2;
        vis[ 2 ] %= 2;
        //        printf("%d   %d   %d    %d\n",vis[1],vis[2],vis[3],ans);
        if ( vis[ 3 ] == 0 && vis[ 4 ] == 0 && ( vis[ 1 ] || vis[ 2 ] ) )
            ans++;
        ans += vis[ 3 ];
        if ( vis[ 3 ] == 0 && vis[ 4 ] != 0 && ( vis[ 2 ] || vis[ 1 ] > 1 ) )
            ans++;
        ans += vis[ 4 ];
        //        if(vis[3]==2&&vis[4]==0&&(vis[2]+vis[1]>2))ans++;
        printf( "%d\n", ans );
    }
}
