#include <algorithm>
#include <stdio.h>  ///基础DP
#include <string.h>
using namespace std;  /// 他找的是人数所以求最小和就好
int a[ 1001 ][ 1001 ];
int b[ 1001 ][ 1001 ];
int main() {
    int n, i, j;
    while ( scanf( "%d", &n ) != EOF ) {
        memset( a, 0, sizeof( a ) );
        for ( i = 0; i < n; i++ )  /// 输入
        {
            for ( j = 0; j < n; j++ ) {
                scanf( "%d", &a[ i ][ j ] );
            }
        }
        memset( b, 0, sizeof( b ) );
        b[ 0 ][ 0 ] = a[ 0 ][ 0 ];  /// 边界初始处理
        for ( i = 0, j = 1; j < n; j++ ) {
            b[ i ][ j ] = b[ i ][ j - 1 ] + a[ i ][ j ];
        }
        for ( i = 1, j = 0; i < n; i++ ) {
            b[ i ][ j ] = b[ i - 1 ][ j ] + a[ i ][ j ];
        }
        for ( i = 1; i < n; i++ )  /// dp
        {
            for ( j = 1; j < n; j++ ) {
                b[ i ][ j ] = a[ i ][ j ] + min( b[ i - 1 ][ j ], b[ i ][ j - 1 ] );  /// 找小的dp
            }
        }
        printf( "%d\n", b[ i - 1 ][ j - 1 ] );  /// 输出最后出口的人数和
    }
    return 0;
}
