#include <stdio.h>
#include <string.h>
int walkx[ 8 ] = { -1, -1, -1, 0, 0, 1, 1, 1 };  /// 周围一圈八个方向判断有没有雷
int walky[ 8 ] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int main() {
    char a[ 208 ][ 208 ];
    int  i, j, x, y, m, flag = 0;
    while ( scanf( "%d %d %d", &x, &y, &m ) != EOF ) {
        getchar();     /// 填完数字吃掉一个换行符
        if ( flag++ )  /// 为啥在这里换行，明明没输入完？
        {
            printf( "\n" );
        }
        memset( a, ' ', sizeof( a ) );  /// 清空为空格
        for ( i = 1; i <= x; i++ )      /// 从1开始，这样边界周围一圈遍历时不需要判断是否超出范围
        {
            for ( j = 1; j <= y; j++ ) {
                scanf( "%c", &a[ i ][ j ] );
            }
            getchar();  /// 输入完一行吃掉一个换行符
        }
        for ( i = 1; i <= x; i++ )  /// 统计整理矩阵
        {
            for ( j = 1; j <= y; j++ ) {
                char sum = '0';            /// 因为输出的矩阵里带星号，所以还是得字符
                if ( a[ i ][ j ] == '*' )  /// 碰到雷不用管
                {
                    continue;
                }
                else  /// 没碰到雷就看周围八个方向有没有雷
                {
                    for ( int k = 0; k < 8; k++ )  /// 最后错误:k打成i
                    {
                        int xx = i + walkx[ k ];
                        int yy = j + walky[ k ];
                        if ( a[ xx ][ yy ] == '*' ) {
                            sum++;
                        }
                    }
                    a[ i ][ j ] = sum;  /// 这里可以直接定义字符'0'往上加，不用又int+'0'转换成字符型，而且累加最多不超过8个，所以也不会超出到别的字符上
                }
            }
        }
        for ( i = 1; i <= x; i++ )  /// 输出部分
        {
            for ( j = 1; j <= y; j++ ) {
                printf( "%c", a[ i ][ j ] );
            }
            printf( "\n" );
        }
    }
    return 0;
}
