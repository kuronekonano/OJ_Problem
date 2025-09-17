#include <stdio.h>
int gys( int a, int b )  // 采用递归方法的最大公约数
{
    if ( a % b == 0 ) {
        return b;
    }
    else {
        return gys( b, a % b );
    }
}
int gbs( int x, int y )  // 最小公倍数
{
    return ( x * y ) / gys( x, y );  // 两数乘积除以最大公约数等于最小公倍数
}
int main() {
    int n, a, b, i, j, c[ 10 ];
    while ( scanf( "%d%d%d", &n, &a, &b ) != EOF )  // 找出在a至b范围内能同时被n个数整除的数，就是求着n个数的公倍数，同时也是n个数最小公倍数的倍数
    {
        for ( i = 0; i < n; i++ ) {
            scanf( "%d", &c[ i ] );
        }
        int sum = gbs( c[ 0 ], c[ 1 ] );  // 先找出两个数的最小公倍数
        for ( i = 2; i < n; i++ ) {
            sum = gbs( sum, c[ i ] );  // 再循环找出所有数的最小公倍数
        }
        i        = 1;
        int flag = 0;
        while ( i * sum >= a && i * sum <= b )  // 找的数是最小公倍数在a至b范围内的倍数
        {
            i++;
            flag++;
        }
        printf( "%d\n", flag );
    }
    return 0;
}
