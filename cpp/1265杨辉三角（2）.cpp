#include <stdio.h>
int main() {
    int i, j, n, x;
    int a[ 50 ][ 50 ];
    while ( scanf( "%d%d", &n, &x ) != EOF ) {
        for ( i = 0; i <= n; i++ ) {
            for ( j = 0; j <= i; j++ )  // j是可以等于i的，必须等于
            {
                if ( j == 0 || j == i )  // 边缘和末尾时的数等于1
                {
                    a[ i ][ j ] = 1;
                }
                else {
                    a[ i ][ j ] = a[ i - 1 ][ j - 1 ] + a[ i - 1 ][ j ];  // 某数等于左上角的数加上其正上方的数
                }
            }
        }
        printf( "%d\n", a[ n - 1 ][ x - 1 ] );
    }
    return 0;
}
