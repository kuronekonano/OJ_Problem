#include <stdio.h>
#include <string.h>
int num( char a[] ) {
    if ( strcmp( a, "one" ) == 0 ) {
        return 1;
    }
    if ( strcmp( a, "two" ) == 0 ) {
        return 2;
    }
    if ( strcmp( a, "three" ) == 0 ) {
        return 3;
    }
    if ( strcmp( a, "four" ) == 0 ) {
        return 4;
    }
    if ( strcmp( a, "five" ) == 0 ) {
        return 5;
    }
    if ( strcmp( a, "six" ) == 0 ) {
        return 6;
    }
    if ( strcmp( a, "seven" ) == 0 ) {
        return 7;
    }
    if ( strcmp( a, "eight" ) == 0 ) {
        return 8;
    }
    if ( strcmp( a, "nine" ) == 0 ) {
        return 9;
    }
    if ( strcmp( a, "zero" ) == 0 ) {
        return 0;
    }
}
int main() {
    char a[ 50 ], b[ 50 ], add[ 100 ];
    int  ax, bx, i;
    while ( gets( add ) ) {
        ax       = 0;
        bx       = 0;
        int flag = 1;
        int n    = strlen( add );
        int j    = 0;
        for ( i = 0; i < n; i++ ) {
            if ( add[ i ] >= 'a' && add[ i ] <= 'z' ) {
                a[ j ] = add[ i ];
                j++;
                a[ j ] = '\0';
            }
            if ( add[ i + 1 ] == ' ' ) {
                ax   = ax * flag + num( a );
                j    = 0;
                flag = flag * 10;
            }
            if ( add[ i + 2 ] == '+' )
                break;
        }
        int k = 0;
        flag  = 1;
        for ( i += 3; i < n; i++ ) {
            if ( add[ i ] >= 'a' && add[ i ] <= 'z' ) {
                b[ k ] = add[ i ];
                k++;
                b[ k ] = '\0';
            }
            if ( add[ i + 1 ] == ' ' ) {
                bx   = bx * flag + num( b );
                k    = 0;
                flag = flag * 10;
            }
            if ( add[ i + 2 ] == '=' )
                break;
        }
        if ( ax == 0 && bx == 0 ) {
            return 0;
        }
        else
            printf( "%d\n", ax + bx );
    }
    return 0;
}
