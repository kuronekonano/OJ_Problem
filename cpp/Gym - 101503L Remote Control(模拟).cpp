#include <algorithm>
#include <stdio.h>  ///模拟
#include <stdlib.h>
#include <string.h>
using namespace std;
int  a[ 20 ];
bool judge( int x )  /// 判断x位是否可行
{
    if ( x < 10 )
        if ( a[ x ] )
            return true;
        else
            return false;
    else {
        if ( a[ x / 10 ] && a[ x % 10 ] && a[ 12 ] )
            return true;  /// 如果是判断十位和百位，那么双位按键必须有用
        else
            return false;
    }
}
int main() {
    int n, m;
    while ( ~scanf( "%d", &a[ 1 ] ) ) {
        int n, m, ans = 0x7fffffff;
        scanf( "%d%d%d%d%d%d%d%d%d%d%d%d", &a[ 2 ], &a[ 3 ], &a[ 10 ], &a[ 4 ], &a[ 5 ], &a[ 6 ], &a[ 11 ], &a[ 7 ], &a[ 8 ], &a[ 9 ], &a[ 12 ], &a[ 0 ] );
        scanf( "%d%d", &n, &m );
        if ( n == m )  /// 如果从自己到自己则不需要懂，不用考虑哪个按键是否损坏
        {
            printf( "0\n" );
            continue;
        }
        int dis = abs( m - n );  /// 计算两台距离
        if ( a[ 10 ] )           /// 只按向前
            if ( n < m )
                ans = min( ans, dis );
            else
                ans = min( ans, m + 100 - n );
        if ( a[ 11 ] )  /// 只按后退
            if ( n < m )
                ans = min( ans, n + 100 - m );
            else
                ans = min( ans, dis );
        if ( m < 10 )  /// 目的位置为个位
        {
            if ( judge( m ) )  /// 从直接跳过去判断
            {
                ans = min( ans, 1 );
            }
            if ( !judge( m ) && a[ 10 ] )  /// 不能自己直接跳，就先跳至最近的台，然后只按前进或后退
            {                              /// 跳跃后向前
                int tmp = m, sum = 0;
                while ( !judge( tmp ) && sum < 101 )  /// 如果根本不能通过这种途径到达，那么这个循环会跳不出去，因此要设定一个最大步数跳出循环
                {
                    tmp--;
                    sum++;
                    if ( tmp < 0 )
                        tmp += 100;  /// 频道是循环的
                }
                int num = tmp < 10 ? 1 : 3;       /// 注意如果最近的台是个位，那么只用按一次操作，否则要按3次
                ans     = min( ans, num + sum );  /// 这里直接计算会错，应用步数计数较保险
            }
            if ( !judge( m ) && a[ 11 ] ) {  /// 跳跃后向后
                int tmp = m, sum = 0;
                while ( !judge( tmp ) && sum < 101 ) {
                    tmp++;
                    sum++;
                    if ( tmp > 99 )
                        tmp %= 100;  /// 频道循环
                }
                int num = tmp < 10 ? 1 : 3;
                ans     = min( ans, num + sum );  /// 不断取最小值
            }
        }
        else  /// 目的位置大于10
        {
            if ( judge( m ) )
                ans = min( 3, ans );  /// 直接跳跃双位
            if ( !judge( m ) && a[ 10 ] ) {
                int tmp = m, sum = 0;
                while ( !judge( tmp ) && sum < 101 ) {
                    tmp--;
                    sum++;
                    if ( tmp < 0 )
                        tmp += 100;
                }
                int num = tmp < 10 ? 1 : 3;
                ans     = min( ans, num + sum );
            }
            if ( !judge( m ) && a[ 11 ] ) {
                int tmp = m, sum = 0;
                while ( !judge( tmp ) && sum < 101 ) {
                    tmp++;
                    sum++;
                    if ( tmp > 99 )
                        tmp %= 100;
                }
                int num = tmp < 10 ? 1 : 3;
                ans     = min( ans, sum + num );
            }
        }
        if ( ans == 0x7fffffff )
            ans = -1;  /// 如果没有任何途径到达那个台，步骤数不会被更新，仍是最大值
        printf( "%d\n", ans );
    }
}
