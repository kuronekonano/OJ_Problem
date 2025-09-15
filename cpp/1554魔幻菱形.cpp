#include <stdio.h>
int main() {
    int i, j, n, t, k;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &n );
        if ( n == 1 ) {
            printf( "*\n" );  // 单独输出一颗星时的情况
        }
        else {
            for ( i = 1; i <= n; i++ )  // 每行
            {
                for ( j = 1; j <= n - i; j++ )  // 空格数
                {
                    printf( " " );
                }
                printf( "*" );                      // 输出玩空格输出星号
                for ( k = 1; k <= i * 2 - 3; k++ )  // 继续空格，数量是实心减掉两遍
                    printf( " " );
                if ( i > 1 )  /// 第一行不输出第二个星号
                {
                    printf( "*" );
                }
                printf( "\n" );
            }
            for ( i = n - 1; i >= 1; i-- )  /// 下半部分，直接逆序输出就好
            {
                for ( j = 1; j <= n - i; j++ ) {
                    printf( " " );
                }
                printf( "*" );
                for ( k = 1; k <= i * 2 - 3; k++ ) {
                    printf( " " );
                }
                if ( i > 1 ) {
                    printf( "*" );
                }
                printf( "\n" );
            }
        }
        printf( "\n" );
    }
    return 0;
}
