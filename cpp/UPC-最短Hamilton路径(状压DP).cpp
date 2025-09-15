#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int       dp[ ( 1 << 20 ) + 10 ][ maxn ];
int       n, a[ maxn ][ maxn ];
int       main() {
    while ( scanf( "%d", &n ) != EOF ) {
        memset( dp, 0x3f, sizeof dp );
        for ( int i = 1; i <= n; i++ )
            for ( int j = 1; j <= n; j++ )
                scanf( "%d", &a[ i ][ j ] );
        dp[ 1 ][ 1 ] = 0;
        for ( int i = 1; i < ( 1 << n ); i++ )  /// 遍历所有可能状态
            for ( int j = 1; j <= n; j++ )
                if ( ( i >> ( j - 1 ) ) & 1 )       /// 在每一个状态中我们计算经过j市的最短距离
                    for ( int k = 1; k <= n; k++ )  /// 计算经过j市的最短距离需要经过k市的最短距离加上，从k到j市距离
                        if ( ( i >> ( k - 1 ) ) & 1 )
                            dp[ i ][ j ] = min( dp[ i ][ j ], dp[ i ^ ( 1 << ( j - 1 ) ) ][ k ] + a[ k ][ j ] );
        printf( "%d\n",
                      dp[ ( 1 << n ) - 1 ][ n ] );  /// 最后输出经过所有城市且到达n市的最短距离
    }
}
/// dp[i][j]表示从1点出发，经过二进制i状态上位为1的所有城市，到达j的最短距离
