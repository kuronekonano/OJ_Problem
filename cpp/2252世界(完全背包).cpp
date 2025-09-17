#include <algorithm>
#include <stdio.h>  ///完全背包
#include <string.h>
using namespace std;
struct brave {
    int cost, w;
} a[ 1005 ];
int main() {
    int t, i, j, n, m, s;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d%d", &n, &m );  /// n是勇气个数，m是需要的勇气
        for ( i = 0; i < n; i++ ) {
            scanf( "%d%d", &a[ i ].cost, &a[ i ].w );
        }
        bool flag = false;
        for ( i = 1;; i++ )  /// 容积，为得到最小容积必须从1开始,那么dp数组也将随之扩大
        {
            int dp[ i + 5 ];  /// 数组下标123456是用来表示当前容积的所能存下的最大价值
            memset( dp, 0, sizeof( dp ) );
            for ( j = 0; j < n; j++ )  /// 选择物品
            {
                for ( s = a[ j ].cost; s <= i; s++ )  /// 如果第j件物品大于目前正在填充的容积i，那么这个物品将暂时不会放到这个背包里，因此s是当前遍历容积的值
                {                                     /// 其中dp[s-a[j].cost]讲直接调出不放这件物品的容积的最大价值是多少
                    dp[ s ] = max( dp[ s ],
                                   dp[ s - a[ j ].cost ] + a[ j ].w );  /// 每次只放一件物品，放这件物品的时候，将会考虑当前容积放这个东西是否划算
                    if ( dp[ s ] >= m ) {
                        flag = true;  /// 当大于需要的勇气值时，跳出循环
                        break;
                    }
                }
                if ( flag ) {
                    break;
                }
            }
            if ( flag ) {
                break;
            }
        }
        printf( "%d\n", i );  /// 那么当前的容积i即是最小花费
    }
}
