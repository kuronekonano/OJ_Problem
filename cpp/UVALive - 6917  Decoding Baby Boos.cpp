#include <stdio.h>
#include <string.h>
int main() {
    int t;
    scanf( "%d", &t );
    while ( t-- ) {
        char a[ 1000008 ];
        int  abc[ 30 ];
        bool flag[ 30 ];
        memset( flag, false,
                sizeof( flag ) );  /// 记得对出现的字母标记，对被代替的字母取消标记，没出现的字母不能更改
        scanf( "%s", a );
        int len = strlen( a );
        for ( int i = 0; i < len; i++ ) {
            if ( a[ i ] != '_' )
                flag[ a[ i ] - 'A' ] = true;
        }
        int  q;
        char from[ 2 ], to[ 2 ];
        for ( int i = 0; i < 26; i++ )
            abc[ i ] = i;
        scanf( "%d", &q );
        for ( int i = 0; i < q; i++ ) {
            scanf( "%s %s", from, to );
            if ( from[ 0 ] == to[ 0 ] || !flag[ to[ 0 ] - 'A' ] )
                continue;
            abc[ to[ 0 ] - 'A' ] = from[ 0 ] - 'A';
            for ( int i = 0; i < 26; i++ ) {
                if ( abc[ i ] + 'A' == to[ 0 ] )
                    abc[ i ] = from[ 0 ] - 'A';
            }
            flag[ from[ 0 ] - 'A' ] = true;
            flag[ to[ 0 ] - 'A' ]   = false;
        }
        for ( int i = 0; i < len; i++ ) {
            printf( "%c", a[ i ] == '_' ? a[ i ] : abc[ a[ i ] - 'A' ] + 'A' );
        }
        printf( "\n" );
    }
}
