#include <algorithm>
#include <stdio.h>  ///并查集+贪心
#include <string.h>
using namespace std;
struct dragon {
    int ci, si, ni;
} a[ 1002 ];
int n, m, k, city[ 305 ];
int finds( int i ) {
    int r = i, t;
    while ( city[ r ] != r )  /// 可以不用路径压缩，但是一定要记得返回boss
    {
        t         = r;
        r         = city[ r ];
        city[ t ] = city[ r ];
    }
    return r;
}
int join( int x, int y ) {
    int a = finds( x ), b = finds( y );
    if ( a != b )
        city[ a ] = b;
}
bool cmp( dragon a,
          dragon b )  /// 按头的生长速度从大到小排序，这样先判断生长速度较快的龙，可以先派人在初始时杀死，这样形成的初始人群，在后来的遍历中也可以作为一个基数再增长
{
    return a.ni > b.ni;  /// 基数作为杀死初始头数的人数之和，避免龙生长到无法控制。之后基数逐渐累加，也会比一些龙的生长速度大了，就不需要增加了
}
int main() {
    while ( scanf( "%d%d%d", &n, &m, &k ) != EOF ) {
        if ( !n && !m && !k )
            return 0;
        int x, y;
        for ( int i = 0; i <= n; i++ )
            city[ i ] = i;
        for ( int i = 0; i < m; i++ ) {
            scanf( "%d%d", &x, &y );
            join( x, y );  /// 形成集团的互通城市
        }
        for ( int i = 0; i < k; i++ )
            scanf( "%d%d%d", &a[ i ].ci, &a[ i ].si, &a[ i ].ni );
        sort( a, a + k, cmp );
        int sum[ 305 ];
        memset( sum, 0, sizeof( sum ) );  /// 每个集团的最小人数数组
        for ( int i = 0; i < k; i++ )     /// 遍历每头龙
        {
            int mi = finds( a[ i ].ci );  /// 找到记录这个城市集团的boss
            if ( sum[ mi ] + a[ i ].si
                 < a[ i ].ni + 1 )  /// 如果当前总人数+初始头数仍小于生长速度+1，说明无法在龙增长的过程中磨死，要将龙先杀死，那么就加上这头龙的初始头数，将其优先杀死,这里取不取等无所谓
                sum[ mi ] += a[ i ].si;
            else
                sum[ mi ] = sum[ mi ] > a[ i ].ni + 1 ? sum[ mi ] : a[ i ].ni + 1;  /// 如果人数+初始头数本来就超过了生长速度，说明可以利用较少人数在生长过程中杀死，取其中的较大值
        }  /// 因为sum[mi]原本数量是杀死这头龙之前的必要数量，如果少了，就增加到这头龙的生长速度+1的人数，如果多了，那也不能减少
        int ans = 0;
        for ( int i = 1; i <= n; i++ )
            if ( city[ i ] = i )
                ans += sum[ i ];  /// 最后求出每个城市集团之和
        printf( "%d\n", ans );
    }
}
