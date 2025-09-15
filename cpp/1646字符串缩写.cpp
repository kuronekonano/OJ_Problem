#include <stdio.h>
#include <string.h>
int main() {
    int  t, n, i;
    char a[ 106 ];
    scanf( "%d", &t );
    getchar();
    while ( t-- ) {
        gets( a );
        n = strlen( a );
        if ( a[ 0 ] >= 'A' && a[ 0 ] <= 'Z' ) {
            printf( "%c", a[ 0 ] );
        }
        else {
            printf( "%c", a[ 0 ] - 'a' + 'A' );
        }
        for ( i = 1; i < n; i++ ) {
            if ( a[ i ] == ' ' && a[ i + 1 ] >= 'A' && a[ i + 1 ] <= 'Z' ) {
                printf( "%c", a[ i + 1 ] );
            }
            else if ( a[ i ] == ' ' && a[ i + 1 ] >= 'a' && a[ i + 1 ] <= 'z' ) {
                printf( "%c", a[ i + 1 ] - 'a' + 'A' );
            }
        }
        printf( "\n" );
    }
    return 0;
}
