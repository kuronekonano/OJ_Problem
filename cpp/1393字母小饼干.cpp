#include <stdio.h>
#include <string.h>
int main() {
    int  n;
    char a[ 105 ], b[ 105 ];
    while ( scanf( "%d", &n ) != EOF ) {
        int x[ 30 ], y[ 30 ];
        memset( x, 0, sizeof( x ) );  /// 记得清空数组
        memset( y, 0, sizeof( y ) );
        scanf( "%s", a );
        scanf( "%s", b );
        for ( int i = 0; i < n; i++ ) {
            x[ a[ i ] - 'A' ]++;
        }
        int t = strlen( b );
        for ( int i = 0; i < t; i++ ) {
            y[ b[ i ] - 'A' ]++;
        }
        bool flag = true;
        for ( int i = 0; i < 26; i++ ) {
            if ( x[ i ] < y[ i ] ) {
                flag = false;
            }
        }
        if ( flag ) {
            printf( "Yes\n" );
        }
        else {
            printf( "No\n" );
        }
    }
    return 0;
}
