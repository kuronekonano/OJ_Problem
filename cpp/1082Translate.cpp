#include <stdio.h>
#include <string.h>
int main() {
    int  i, t, n;
    char s[ 35 ];
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%s", s );
        n = strlen( s );
        for ( i = 0; i < n; i++ ) {
            switch ( s[ i ] ) {
            case '0':
                printf( "zero" );
                break;
            case '1':
                printf( "one" );
                break;
            case '2':
                printf( "two" );
                break;
            case '3':
                printf( "three" );
                break;
            case '4':
                printf( "four" );
                break;
            case '5':
                printf( "five" );
                break;
            case '6':
                printf( "six" );
                break;
            case '7':
                printf( "seven" );
                break;
            case '8':
                printf( "eight" );
                break;
            case '9':
                printf( "nine" );
                break;
            }
            if ( i != n - 1 )
                printf( "-" );
        }
        printf( "\n" );
    }
    return 0;
}
