#include <algorithm>
#include <stdio.h>  ///01背包
#include <string.h>
using namespace std;
struct promble  /// 同样价值（分数）和 体积（时间）打包结构体
{
    int time;
    int mark;
} ps[ 105 ];  /// 最多一百题
int main() {
    int t, m, dp[ 105 ][ 1005 ], i;
    while ( scanf( "%d%d", &t, &m ) != EOF ) {
        memset( dp, 0, sizeof( dp ) );  /// 背包一定要记得清空动态规划数组
        for ( i = 0; i < m; i++ )       /// 输入部分
        {
            scanf( "%d%d", &ps[ i ].time, &ps[ i ].mark );
        }
        for ( i = ps[ 0 ].time; i <= t; i++ )  /// 横着的是逐渐增大的背包容积，当容积达到第一个可以放入其中的物品的体积时，假设只有这一个物品，那么这个容积往后的最大价值都初始化成物品价值
        {
            dp[ 0 ][ i ] = ps[ 0 ].mark;
        }
        for ( i = 1; i < m; i++ )  /// 开始动态规划，第一行是题目的数量，一个一个题的选，看看能不能放进去，看看放进去值不值得
        {
            for ( int j = 0; j <= t; j++ )  /// 逐渐增加的背包容积，最大值小于背包确定的容积
            {
                if ( j >= ps[ i ].time )  /// 判断，当当前的容积大于正在判断要不要放进去的这个道具的体积时
                {
                    dp[ i ][ j ] = max( dp[ i - 1 ][ j ],
                                        dp[ i - 1 ][ j - ps[ i ].time ] + ps[ i ].mark );  /// 可以选择
                                                                                           /// 值得就放进去，不值得就就不放，并保持上一个容积限度的价值总和
                }
                else  /// 如果当前增加到的容积放不进正在判断的这个物品体积，直接不要，并继承上一个容积的最大价值
                {
                    dp[ i ][ j ] = dp[ i - 1 ][ j ];
                }
            }
        }
        printf( "%d\n", dp[ m - 1 ][ t ] );  /// 动态规划底部是最后结果
    }
}
