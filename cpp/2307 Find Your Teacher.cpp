#include <stdio.h>   ///和许可证一样的依赖性问题，因为数据量都不是很大，所以暴力遍历了
#include <string.h>  ///嵌套了三层for
int main() {
    int  t, i, j, k;
    bool wap[ 55 ][ 55 ];
    scanf( "%d", &t );
    while ( t-- ) {
        memset( wap, false, sizeof( wap ) );  /// 最后一定要记得清空数组
        int n, m, x, y;
        scanf( "%d%d", &n, &m );
        for ( i = 1; i <= m; i++ ) {
            scanf( "%d%d", &x, &y );
            wap[ x ][ y ] = true;  /// 标记两两有关系
        }
        for ( i = 1; i <= n; i++ ) {
            for ( j = 1; j <= n; j++ ) {
                for ( k = 1; k <= n; k++ ) {
                    if ( wap[ i ][ j ] == true && wap[ j ][ k ] == true ) {
                        wap[ i ][ k ] = true;  /// 关联关系
                    }
                }
            }
        }
        //        for(i=1;i<=n;i++)
        //        {
        //            for(j=1;j<=n;j++)
        //                printf("%d",wap[i][j]);
        //            printf("\n");
        //        }
        if ( wap[ 1 ][ n ] == true ) {
            printf( "^_^\n" );
        }
        else
            printf( "T_T\n" );
    }
    return 0;
}
