#include <stdio.h>
#include <string.h>
int z[ 100004 ], tree[ 100005 ], num[ 100005 ];
int n, t, m, real;
int lowbit( int x )  /// 树状数组用于更新不同人数出现的帮派数的前缀和
{
    return x & ( -x );
}
int update( int p, int x ) {
    while ( p <= n ) {
        tree[ p ] += x;
        p += lowbit( p );
    }
}
int sum( int p ) {
    int sum = 0;
    while ( p > 0 ) {
        sum += tree[ p ];
        p -= lowbit( p );
    }
    return sum;
}
int finds( int x ) {
    int tmp;
    while ( z[ x ] != x ) {
        tmp      = x;
        x        = z[ x ];
        z[ tmp ] = z[ x ];
    }
    return x;
}
void join( int a, int b ) {
    int fa = finds( a ), fb = finds( b );
    if ( fa != fb ) {
        z[ fb ] = fa;
        update( num[ fa ],
                -1 );  /// 当帮派合并，两个帮派的人数都被改变，那么该人数存在的帮派数量也要相应改变
        update( num[ fb ], -1 );
        num[ fa ] += num[ fb ];  /// 表示a吞并b
        num[ fb ] = 0;           /// b帮派重置为0人
        update( num[ fa ], 1 );  /// 新的a帮派人数，将增加一个帮派数量
        real--;                  /// 注意真实帮派数的减少，当连接两帮派时不一定减少，因为还有可能是无效操作，确定减少了再减去这个
                                 /// 真实值
    }
}
int main() {
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d%d", &n, &m );
        for ( int i = 1; i <= n; i++ )
            num[ i ] = 1, z[ i ] = i;
        memset( tree, 0, sizeof( tree ) );
        update( 1, n );
        real = n;
        while ( m-- ) {
            int flag;
            scanf( "%d", &flag );
            if ( flag == 1 ) {
                int x, y;
                scanf( "%d%d", &x, &y );
                join( x, y );
            }
            else {
                int k;
                scanf( "%d", &k );
                if ( k > real ) {
                    printf( "-1\n" );
                    continue;
                }
                k     = real - k + 1;  /// 树状数组前缀和计算的是第k小人数，那么我要计算的第k大人数，应是实际帮派数-k+1(本身)的位置
                int l = 1,
                    r = n;       /// 要保留原人数的原因，因为二分时做一个最大人数的最大边界，不能因为帮派数量减少就减少搜索区间
                while ( l < r )  /// 根据k值二分查找前缀和中第一个大于等于k的位置，也就是该帮派的人数
                {
                    int mid = ( l + r ) / 2;
                    if ( sum( mid ) >= k )
                        r = mid;
                    else
                        l = mid + 1;
                }
                printf( "%d\n", l );
            }
        }
    }
}
/// 树状数组中存储的是当人数为i时的帮派数量，也是人数的出现次数
/// 如果求第k小人数的帮派人数。那么就是说该人数的前缀和，就包括了所有小于等于该人数的帮派数量，当前缀和大于等于k时，说明该人数之前已经有小于k个帮派，那么数量k的帮派位于的下标即第k小帮派人数
/// 若前缀和，从1到某值的下标，表示不同人数出现的次数，那么前缀和为k表示了在此之前有k-1个帮派存在，那么第k个帮派的人数就是下标
/// 求第k大帮派人数，即当前存在的总帮派数-k值+1得到在树状数组中求第新的k的人数，也就是下标
