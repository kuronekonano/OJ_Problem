#include <math.h>              ///计算分割方法的总数mod1e9+7,关于分割方法，将序列先分成最小长度能被m整除的数，因为是最小分割
#include <stdio.h>             ///输入一个序列，将这个序列分割成若干子序列，使得每个子序列作为一个十进制数能被m整除
#include <string.h>            ///因此不存在将分割切开与下一段分割合成一个新的被m整除的数的情况，这样会使前半段分割变成一个不可整除的数
const int mod = 1e9 + 7;       /// 得到最小分割的数字数量之后，将其进行相邻合并。
long long poww( long long b )  /// 设某个可以被整除的数为m*k1,另一个为m*k2，将m*k1*10^n后加上m*k2,提公因式，因子中仍有m，因此合并之后还是被m整除的数
{                              /// 关于合并方法，将每个是单独的子序列看成被隔板分割，sum个子序列就有sum-1个隔板，每个隔板拆与不拆的情况形成一个新的子序列，也就是2^(sum-1)种排列
    long long ans = 1, tmp = 2;
    while ( b != 0 ) {
        if ( b & 1 )
            ans = ( ( ans % mod ) * ( tmp % mod ) ) % mod;
        tmp = ( ( tmp % mod ) * ( tmp % mod ) ) % mod;
        b /= 2;
    }
    return ans;
}
int main() {
    long long n, m;
    char      a[ 300008 ];
    while ( scanf( "%lld%lld", &n, &m ) != EOF ) {
        bool flag = false;
        memset( a, 0, sizeof( a ) );
        scanf( "%s", a );
        int sum = 0, num = 0;
        for ( int i = 0; i < n; i++ ) {
            num = num * 10 + a[ i ] - '0';
            ;
            if ( num % m == 0 ) {
                sum++;
                num = 0;
            }
            else
                num %= m;
            if ( i == n - 1 && num != 0 )
                flag = true;  /// 若加上最后一个数后，最后一个子序列仍无法被m整除，那么这个子序列是不可合并的，所有种数直接为0
        }
        if ( flag ) {
            printf( "0\n" );
            continue;
        }
        else {
            long long ans = poww( sum - 1 );
            printf( "%lld\n", ans );
        }
    }
}
