#include <stdio.h>  ///判断是否是X字符组成一个矩形即可
#include <string.h>
int main() {
    int  n, m, i, j;
    char a[ 508 ][ 509 ];
    while ( scanf( "%d%d", &n, &m ) != EOF ) {
        int flag = 0, minx = 600, miny = 600, maxx = -1, maxy = -1;
        for ( i = 1; i <= n; i++ ) {
            scanf( "%s", a[ i ] + 1 );
            for ( j = 1; j <= m; j++ ) {
                if ( a[ i ][ j ] == 'X' ) {
                    flag++;
                    if ( i < minx )
                        minx = i;
                    if ( i > maxx )
                        maxx = i;
                    if ( j < miny )
                        miny = j;
                    if ( j > maxy )
                        maxy = j;
                }
            }
        }
        int sum = ( maxx - minx + 1 ) * ( maxy - miny + 1 );
        if ( sum == flag )
            printf( "YES\n" );
        else
            printf( "NO\n" );
    }
}
