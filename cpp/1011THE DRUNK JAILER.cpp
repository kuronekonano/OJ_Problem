#include <stdio.h>  ///开灯问题
#include <string.h>
int main() {
    bool cell[ 105 ];
    int  t, n, i, j;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &n );
        memset( cell, true, sizeof( cell ) );
        for ( i = 1; i <= n; i++ )  /// 执行n次，n个犯人，n个房间
        {
            for ( j = i; j <= n; j += i )  /// 题意没读懂，是第几次就是几的倍数的房间开关
            {
                cell[ j ] = cell[ j ] ? false : true;
            }
        }
        int flag = 0;
        for ( i = 1; i <= n; i++ )  /// 遍历计数
        {
            if ( cell[ i ] == false ) {
                flag++;
            }
        }
        printf( "%d\n", flag );
    }
    return 0;
}
