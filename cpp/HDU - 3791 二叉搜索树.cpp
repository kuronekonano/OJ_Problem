#include <stdio.h>
#include <string.h>
int  tree[ 3000 ], btre[ 3000 ];
char a[ 20 ];
int  creatree( char aa[], int tree[] ) {
    for ( int i = 0; i < 3000; i++ )
        tree[ i ] = -1;  /// 节点初始化
    int len = strlen( aa ), maxn = 0;
    for ( int i = 0; i < len; i++ ) {
        int pos = 1;
        while ( tree[ pos ] != -1 )  /// 走到叶子节点
            if ( aa[ i ] - '0' < tree[ pos ] )
                pos *= 2;  /// 比当前节点小的插左边
            else
                pos = pos * 2 + 1;    /// 大的插右孩子
        tree[ pos ] = aa[ i ] - '0';  /// 找到节点后赋值
        if ( pos > maxn )
            maxn = pos;  /// 记录最大节点标号
    }
    return maxn;
}
int main() {
    int t;
    while ( scanf( "%d", &t ) != EOF ) {
        if ( !t )
            return 0;
        int maxn = 0;
        scanf( "%s", a );
        maxn = creatree( a, tree );
        for ( int i = 0; i < t; i++ ) {
            bool flag = true;
            memset( btre, -1, sizeof( btre ) );
            int maxx = 0;
            scanf( "%s", a );
            maxx = creatree( a, btre );
            if ( maxx != maxn )
                flag = false;
            if ( flag )
                for ( int i = 1; i <= maxn; i++ ) {
                    if ( tree[ i ] != btre[ i ] )
                        flag = false;
                }
            printf( "%s\n", flag ? "YES" : "NO" );
        }
    }
}
