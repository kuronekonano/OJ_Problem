#include <stdio.h>
#include <string.h>
int main() {
    int  i, t, n;
    char a[ 105 ];
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%s", a );
        n = strlen( a );
        for ( i = 0; i < n; i++ ) {
            if ( a[ i ] == 'Z' )
                a[ i ] = 'A';
            else if ( a[ i ] == 'z' )
                a[ i ] = 'a';
            else
                a[ i ] = a[ i ] + 1;
        }
        for ( i = 0; i < n; i++ ) {
            printf( "%c", a[ i ] );
        }
        printf( "\n" );
    }
    return 0;
}
