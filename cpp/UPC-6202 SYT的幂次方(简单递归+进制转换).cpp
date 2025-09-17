#include <stdio.h>
void dfs( int x ) {
    if ( x == 0 )
        printf( "0" );
    else {
        int tmp = x, bin[ 30 ], i = 0;
        while ( tmp )  /// 进制转换
        {
            bin[ i++ ] = tmp % 2;
            tmp /= 2;
        }
        bool flag = false;                  /// 加号标记
        for ( int j = i - 1; j >= 0; j-- )  /// 从最高位开始遍历二进制位，对于一个新的幂次，若不是1也不是2，则对齐进行递归继续计算，否则直接输出即可
        {
            if ( bin[ j ] ) {
                if ( flag )
                    printf( "+" );
                if ( !flag )
                    flag = true;
                if ( j != 1 ) {
                    printf( "2(" );
                    dfs( j );
                    printf( ")" );
                }
                else
                    printf( "2" );
            }
        }
    }
    return;
}
int main()  /// 对于每个数，将其分为2进制，然后可以得到是由2的几次方加和而成的
{
    int n;
    while ( scanf( "%d", &n ) != EOF ) {
        dfs( n );
        printf( "\n" );
    }
}
