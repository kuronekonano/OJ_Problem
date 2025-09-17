#include <stdio.h>
#include <string.h>
int main() {
    long long dp[ 600 ];
    int       i, n, j;
    while ( scanf( "%d", &n ) != EOF ) {
        memset( dp, 0, sizeof( dp ) );
        int sum  = n * ( n + 1 ) / 2;  /// 等差数列前n项求和公式
        int half = sum / 2;
        if ( sum % 2 != 0 )  /// 因为要把sum总和分成两个相等求和的集合，因此sum总和必须能被2整除否则一个方法也没有
        {
            printf( "0\n" );
            continue;
        }
        dp[ 0 ] = 1;                /// 当输入0时肯定只有一种分法
        for ( i = 1; i <= n; i++ )  /// dp第i个数字
        {
            for ( j = half; j >= i; j-- ) {
                dp[ j ] = dp[ j ] + dp[ j - i ];  /// 达到每一个总和的方法，都是减去这个数所继承的上一个数的方法个数
            }
            //            for(int k=half;k>=0;k--)
            //            {
            //                printf("%d\n",dp[k]);
            //            }
            //            printf("====\n");
        }
        printf( "%lld\n",
                dp[ half ] / 2 );  /// 此处算上的是两个集合交换位置，有重复的，要除2
    }
    return 0;
}
