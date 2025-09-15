#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 1003;
int       t, n;
char      a[ 102 ][ maxn ];
int       vis[ 30 ];
int       num = 0;
int       len[ 102 ];
int       main() {
    while ( scanf( "%s", a[ num++ ] ) != EOF )
        ;
    memset( vis, 0, sizeof vis );
    for ( int k = 0; k < num; k++ ) {
        len[ k ] = strlen( a[ k ] );
        for ( int i = 0; i < len[ k ]; i++ ) {
            if ( a[ k ][ i ] == '`' ) {
                a[ k ][ i ] = ' ';
                continue;
            }
            if ( a[ k ][ i ] == '}' ) {
                a[ k ][ i ] = '.';
                continue;
            }
            if ( a[ k ][ i ] == '(' ) {
                a[ k ][ i ] = ',';
                continue;
            }
            if ( a[ k ][ i ] >= 'A' && a[ k ][ i ] <= 'Z' )
                vis[ a[ k ][ i ] - 'A' ]++;
            else
                vis[ a[ k ][ i ] - 'a' ]++;
        }
    }
    int point = -1, maxx = 0;
    for ( int i = 0; i < 26; i++ )
        if ( maxx < vis[ i ] )
            point = i, maxx = vis[ i ];
    int dis = ( point - 4 + 26 ) % 26;
    //        printf("%d=====%d\n",point,dis);
    for ( int k = 0; k < num; k++ ) {
        for ( int i = 0; i < len[ k ]; i++ ) {
            if ( a[ k ][ i ] >= 'a' && a[ k ][ i ] <= 'z' )
                printf( "%c", ( a[ k ][ i ] - 'a' - dis + 26 ) % 26 + 'a' );
            else if ( a[ k ][ i ] >= 'A' && a[ k ][ i ] <= 'Z' )
                printf( "%c", ( a[ k ][ i ] - 'A' - dis + 26 ) % 26 + 'A' );
            else
                printf( "%c", a[ k ][ i ] );
        }
        printf( "\n" );
    }
}
