#include <stdio.h>
#include <string.h>
int main() {
    bool num[ 11 ][ 7 ] = { { true, true, true, false, true, true, true },  { false, false, true, false, false, true, false }, { true, false, true, true, true, false, true },
                            { true, false, true, true, false, true, true }, { false, true, true, true, false, true, false },   { true, true, false, true, false, true, true },
                            { true, true, false, true, true, true, true },  { true, false, true, false, false, true, false },  { true, true, true, true, true, true, true },
                            { true, true, true, true, false, true, true } };
    int  n, i, j;
    char a[ 18 ];
    while ( scanf( "%d", &n ) != EOF ) {
        scanf( "%s", a );
        int len = strlen( a );
        for ( i = 0; i < len; i++ )  /// Êı×ÖÊıÁ¿
        {
            printf( " " );
            for ( j = 0; j < n; j++ ) {
                printf( "%c", num[ a[ i ] - '0' ][ 0 ] ? '-' : ' ' );
            }
            printf( " " );
            printf( "%c", i == len - 1 ? '\n' : ' ' );
        }
        for ( i = 0; i < n; i++ ) {
            for ( j = 0; j < len; j++ ) {
                printf( "%c", num[ a[ j ] - '0' ][ 1 ] ? '|' : ' ' );
                for ( int k = 0; k < n; k++ )
                    printf( " " );
                printf( "%c%c", num[ a[ j ] - '0' ][ 2 ] ? '|' : ' ', j == len - 1 ? '\n' : ' ' );
            }
        }
        for ( i = 0; i < len; i++ ) {
            printf( " " );
            for ( j = 0; j < n; j++ ) {
                printf( "%c", num[ a[ i ] - '0' ][ 3 ] ? '-' : ' ' );
            }
            printf( " " );
            printf( "%c", i == len - 1 ? '\n' : ' ' );
        }
        for ( i = 0; i < n; i++ ) {
            for ( j = 0; j < len; j++ ) {
                printf( "%c", num[ a[ j ] - '0' ][ 4 ] ? '|' : ' ' );
                for ( int k = 0; k < n; k++ )
                    printf( " " );
                printf( "%c%c", num[ a[ j ] - '0' ][ 5 ] ? '|' : ' ', j == len - 1 ? '\n' : ' ' );
            }
        }
        for ( i = 0; i < len; i++ ) {
            printf( " " );
            for ( j = 0; j < n; j++ ) {
                printf( "%c", num[ a[ i ] - '0' ][ 6 ] ? '-' : ' ' );
            }
            printf( " " );
            printf( "%c", i == len - 1 ? '\n' : ' ' );
        }
        printf( "\n" );
    }
}
