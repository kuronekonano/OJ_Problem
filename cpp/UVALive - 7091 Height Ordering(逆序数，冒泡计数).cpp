#include <algorithm>
#include <stdio.h>  ///树状数组求逆序数+数据离散化
#include <string.h>
using namespace std;
struct num {
    int n, i;
} a[ 29 ];
int tree[ 29 ], ls[ 29 ];
int lowbit( int x )  /// 树状数组求逆序数，树状数组记录某个数值是否出现过
{
    return x & ( -x );
}
int sum( int p ) {
    int sum = 0;
    while ( p > 0 ) {
        sum += tree[ p ];
        p -= lowbit( p );
    }
    return sum;
}
void update( int p ) {
    while ( p <= 20 ) {
        tree[ p ]++;
        p += lowbit( p );
    }
}
bool cmp( num a, num b ) {
    return a.n < b.n;
}
int main()  /// 数据范围9e9很大，但是数据元素只有5e5个，并且每个元素唯一，因此将所有元素映射到一个5e5之内的数即是离散化，避免空间浪费
{
    int t, k;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &k );
        for ( int i = 1; i <= 20; i++ ) {
            scanf( "%d",
                   &a[ i ].n );  /// 记录每个元素的位序，按数值大小排序，按数值从小到大遍历，将数值按位序重新标记成一个较小的数。各个数值大小关系不变
            a[ i ].i = i;
        }
        sort( a + 1, a + 21, cmp );
        for ( int i = 1; i <= 20; i++ )
            ls[ a[ i ].i ] = i;  /// 离散化
        memset( tree, 0, sizeof( tree ) );
        long long ans = 0;
        for ( int i = 1; i <= 20; i++ ) {
            update( ls[ i ] );          /// 按数值从小到大遍历数据，更新当前遍历数字位序的状态，使之变成出现过
            ans += i - sum( ls[ i ] );  /// sum求和，计数在ls[i]出现之前，先出现的小于ls[i]的数的个数，这些是正常位序
        }  /// 当前遍历的数字数量i，是目前出现的数总数，用i减去正常出现的数的个数，剩余数量就是在ls[i]出现之前
        printf( "%d %lld\n", k,
                ans );  /// 优先出现的大于ls[i]的数值数量，这就是ls[i]的逆序数，不断对ans累加就是结果
    }
}
