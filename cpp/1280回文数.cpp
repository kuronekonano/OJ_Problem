#include <stdio.h>
bool tab( int a, int b )  /// 进制转换并判断
{
    if ( a % b == 0 )  /// 如果刚好是当前进制能整除的数，那么一定不是回文数
    {
        return false;
    }
    int c[ 108 ] = { 0 }, k = 0;
    while ( a )  /// 转换进制就是求余和除的过程
    {
        c[ k++ ] = a % b;  /// 将其放入数组中，最后倒序就是相应进制的表示方法
        a        = a / b;
    }
    for ( int i = 0, j = k - 1; i < j; i++, j-- )  /// 正序数组和倒序数组的对比
    {
        if ( c[ i ] != c[ j ] )  /// 若有不同直接返回不成立
        {
            return false;
        }
    }
    return true;  /// 全部顺序都相等则回文
}
bool play( int x )  /// 判断函数，先判断是否大于2种进制可回文
{
    int sum = 0;                     /// 计数器初始化
    for ( int i = 2; i <= 10; i++ )  /// 判断从2到10进制
    {
        if ( tab( x, i ) )  /// 判断是否成立回文的函数
        {
            sum++;  /// 计数
        }
    }
    if ( sum >= 2 )  /// 判断是否大于两种
    {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    int n, s, flag = 1;
    while ( scanf( "%d%d", &n, &s ) != EOF ) {
        printf( "Case %d:\n", flag++ );
        int v = 0;       /// 初始化计数器
        s++;             /// 记住读题，从大于ｓ的数开始
        while ( v < n )  /// 用while循环就正常，用for循环就GG
        {
            if ( play( s ) )  /// 从s开始的判断函数
            {
                printf( "%d\n", s );  /// 输出并计数
                v++;
            }
            s++;  /// s后移
        }
    }
    return 0;
}
