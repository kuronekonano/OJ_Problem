#include <bits/stdc++.h>
#define LL long long
#define M( a, b ) memset( a, b, sizeof a )
#define pb( x ) push_back( x )
using namespace std;
const int maxn = 2e5 + 7;
const int mod  = 1000000007;
int       n, m, k;
struct node {
    int x, t,
        op;  /// op表示操作标识，查询或是更新，t表示操作顺序标号，x表示操作位置，即列数
    LL y;    /// x 表示列，y表示增加的值
} pro[ maxn ], update[ maxn ],
    query[ maxn ];  /// pro记录操作，update分类更新操作，query分类查询操作
LL ans[ maxn ], mp[ 45 ][ maxn ],
    C[ maxn ][ 45 ];  /// ans记录每个查询操作的结果，按序输出，
                      /// mp表示实际矩阵,C表示预处理组合数
void init()           /// 预处理组合数
{
    for ( int i = 0; i <= maxn; i++ )
        C[ i ][ 0 ] = 1;
    for ( int i = 1; i <= maxn; i++ )
        for ( int j = 1; j <= 40; j++ )
            C[ i ][ j ] = ( C[ i - 1 ][ j - 1 ] + C[ i - 1 ][ j ] ) % mod;
}
void CDQ( int l, int r ) {
    int mid = ( l + r ) >> 1;  /// 二分操作
    if ( l >= r )
        return;
    if ( mid - l + 1 >= 1000 )  /// CDQ得到的操作次数是大于2000的区间
    {
        for ( int i = 0; i <= n; i++ )
            mp[ 0 ][ i ] = 0;  /// 初始化
        for ( int i = l; i <= mid; i++ )
            if ( !pro[ i ].op )
                mp[ 0 ][ pro[ i ].x ] = ( mp[ 0 ][ pro[ i ].x ] + pro[ i ].y ) % mod;  /// 左区间更新(只更新第一行)
        for ( int i = 1; i <= k + 1; i++ )                                             /// 直接从第一行传递到第k+1行(暴力传递，相当于也计算了前缀和)
            for ( int j = 1; j <= n; j++ )
                mp[ i ][ j ] = ( mp[ i - 1 ][ j ] + mp[ i ][ j - 1 ] ) % mod;  /// 直接加上
        for ( int i = mid + 1; i <= r; i++ )
            if ( pro[ i ].op )
                ans[ pro[ i ].t ] = ( ans[ pro[ i ].t ] + mp[ k + 1 ][ pro[ i ].x ] ) % mod;
    }  /// 右区间查询答案赋值，由之前左边的影响直接传递到实际矩阵中，并更新ans
    else {
        int upt = 0, qpt = 0;  /// 将操作分类
        for ( int i = l; i <= mid; i++ )
            if ( !pro[ i ].op )
                update[ upt++ ] = pro[ i ];  /// 找到左区间的更新项
        for ( int i = mid + 1; i <= r; i++ )
            if ( pro[ i ].op )
                query[ qpt++ ] = pro[ i ];  /// 右区间的查询项
        for ( int i = 0; i < upt; i++ )
            for ( int j = 0; j < qpt; j++ )
                if ( update[ i ].x <= query[ j ].x )
                    ans[ query[ j ].t ] = ( ans[ query[ j ].t ] + update[ i ].y * C[ k + query[ j ].x - update[ i ].x ][ k ] % mod ) % mod;
    }
    CDQ( l, mid );  /// 先处理左边再处理右边，这样右边会得到左边的影响
    CDQ( mid + 1, r );
}
int main() {
    M( ans, -1 );
    init();
    scanf( "%d%d%d", &n, &m, &k );  /// n列，m次操作,查询第k行
    k--;
    for ( int i = 1; i <= m; i++ ) {
        scanf( "%d%d", &pro[ i ].op, &pro[ i ].x );
        pro[ i ].t = i;
        if ( pro[ i ].op )
            ans[ i ] = 0;
        else
            scanf( "%lld", &pro[ i ].y );
    }
    CDQ( 1, m );
    for ( int i = 1; i <= m; i++ )
        if ( ans[ i ] != -1 )
            printf( "%lld\n", ans[ i ] );
}
