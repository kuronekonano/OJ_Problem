#include <stdio.h>
#include <string.h>
int main() {
    int t, i, j;
    scanf( "%d", &t );
    char a[ 59 ];
    while ( t-- ) {
        scanf( "%s", a );
        int n = strlen( a );
        if ( n < 8 || n > 16 ) {
            printf( "NO\n" );
            continue;
        }
        bool flag[ 5 ];
        memset( flag, false, sizeof( flag ) );
        for ( i = 0; i < n; i++ ) {
            if ( a[ i ] >= '0' && a[ i ] <= '9' )
                flag[ 0 ] = true;
            else if ( a[ i ] >= 'a' && a[ i ] <= 'z' )
                flag[ 1 ] = true;
            else if ( a[ i ] >= 'A' && a[ i ] <= 'Z' )
                flag[ 2 ] = true;
            else
                flag[ 3 ] = true;
        }
        int sum = 0;
        for ( i = 0; i < 4; i++ ) {
            if ( flag[ i ] )
                sum++;
        }
        printf( "%s\n", sum >= 3 ? "YES" : "NO" );
    }
}
