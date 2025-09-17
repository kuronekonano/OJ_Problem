#include <stdio.h>
int main() {
    int n, i, sum, kuro, coin;
    while ( scanf( "%d", &n ) != EOF )  // 1 4 9 16
    {
        if ( n == 0 ) {
            return 0;
        }
        sum  = 0;
        coin = 0;
        kuro = 0;
        for ( i = 1; i <= n; i++ )  // 从1开始连加，直到n
        {
            sum = i + sum;  // 天数和
            if ( sum > n )  // 当天数和大于输入天数
            {
                kuro = n - ( sum - i );  // 减去多加的天数再用n求缺少的天数，第i天表示给几个金币
                break;
            }
            coin = coin + i * i;  // 求整部分的天数共得金币
        }
        coin = coin + i * kuro;  // 加上多余的不足i天的天数得的金币
        printf( "%d %d\n", n, coin );
    }
    return 0;
}
