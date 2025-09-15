#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int  a[ 16000 ];
bool cmp( int a, int b ) {
    return a > b;
}
int main() {
    int n, m,
        dis[ 16000 ];  /// 直接算出两坑之间的距离，然后选出前m-1长的距离，因为要分成m段，用总间距减去较长的间距，剩下的较短间距之和即ans
    while ( scanf( "%d%d", &n, &m ) != EOF ) {
        int j = 0, ans = 0;
        for ( int i = 1; i <= n; i++ ) {
            scanf( "%d", &a[ i ] );
            if ( i != 1 )
                dis[ j++ ] = a[ i ] - a[ i - 1 ];
        }
        ans = a[ n ] - a[ 1 ] + 1;
        sort( dis, dis + j, cmp );
        //        for(int i=0;i<j;i++)printf("%d%c",dis[i],i==j-1?'\n':' ');
        for ( int i = 0; i < m - 1; i++ )
            ans = ans - dis[ i ] + 1;
        printf( "%d\n", ans );
    }
}
