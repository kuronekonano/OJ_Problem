#include <algorithm>
#include <stdio.h>  ///动态规划完全背包
#include <string.h>
using namespace std;
int a[ 100005 ];
int main() {
    int b[ 4 ] = { 150, 200, 350 }, t, n;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &n );  /// 给的钱数
        memset( a, 0, sizeof( a ) );
        for ( int i = 0; i < 3; i++ )  /// 选三件物品
        {
            for ( int j = 1; j <= n; j++ )  /// 一直增长的钱数，每次增长就可以多买一点，一直计算到第n的最优解时就是这个总钱数可以买到的最多东西
            {
                if ( j >= b[ i ] )  /// 如果当前的钱够买正在遍历的物品
                {
                    a[ j ] = max( a[ j ],
                                  a[ j - b[ i ] ] + b[ i ] );  // 向之前的标记点不断更新三次可以购买的东西，并保证是最大值
                }
            }
        }
        printf( "%d\n", n - a[ n ] );  /// 算的是补零钱
    }
    return 0;
}
