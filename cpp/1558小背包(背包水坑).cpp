#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[ 20 ][ 34000 ];  /// 好坑啊，题目说了背包那么大，但是实际16个物品每个物品2012的体积，根本用不了那么大
struct box {
    int cost;
    int value;
} num[ 20 ];
int main() {
    int i, j, n, m;
    while ( scanf( "%d%d", &m, &n ) != EOF ) {
        int sum = 0, sum2 = 0;
        memset( dp, 0, sizeof( dp ) );
        for ( i = 1; i <= n; i++ ) {
            scanf( "%d%d", &num[ i ].cost, &num[ i ].value );
            sum  = sum + num[ i ].cost;
            sum2 = sum2 + num[ i ].value;
        }
        if ( sum < m )  /// 注意自己输入的是m，即使合在一起的体积没那么大，容积还是会在遍历时用到m的数值，而发生数组越界，因此注意
        {
            printf( "%d\n",
                    sum2 );  /// 当输入的容积大于总体积时，可以直接输出所有的价值和，不用一个一个装上去了
            continue;
        }
        for ( i = num[ 1 ].cost; i <= m; i++ ) {
            dp[ 1 ][ i ] = num[ 1 ].value;
        }
        for ( i = 2; i <= n; i++ ) {
            for ( j = 1; j <= m; j++ ) {
                if ( j >= num[ i ].cost ) {
                    dp[ i ][ j ] = max( dp[ i - 1 ][ j ],
                                        dp[ i - 1 ][ j - num[ i ].cost ] + num[ i ].value );  /// 记住啊，容积减掉当前遍历的那个物品的体积，个数也要减掉一个诶
                }
                else
                    dp[ i ][ j ] = dp[ i - 1 ][ j ];  /// 是物品-1，不是容积-1，是如果装不了，那就继承上面那个物品的在此容积下的价值！！！
            }
        }
        //        for(i=0;i<=n;i++)
        //        {
        //            for(j=0;j<=m;j++)
        //            {
        //                printf(" %d",dp[i][j]);
        //            }
        //            printf("\n");
        //        }
        printf( "%d\n", dp[ n ][ m ] );
    }
    return 0;
}
