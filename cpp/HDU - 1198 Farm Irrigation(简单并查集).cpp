#include <algorithm>
#include <stdio.h>
#include <string.h>
#define M( a, b ) memset( a, b, sizeof a )
#define pb( x ) push_back( x )
using namespace std;
const int maxn = 50 + 10;
int       n, m;
char      a[ maxn ][ maxn ];
char      num[ 12 ][ 5 ] = { "1001", "1100", "0011", "0110", "1010", "0101", "1101", "1011", "0111", "1110", "1111" };
int       z[ maxn * maxn ];
int       finds( int x ) {
    return z[ x ] == x ? x : z[ x ] = finds( z[ x ] );
}
void join( int x1, int y1, int x2, int y2 ) {
    if ( x1 == x2 ) {
        if ( y1 < y2 ) {
            if ( num[ a[ x1 ][ y1 ] - 'A' ][ 1 ] == '1' && num[ a[ x2 ][ y2 ] - 'A' ][ 3 ] == '1' ) {
                int fa = finds( ( x1 - 1 ) * m + y1 ), fb = finds( ( x2 - 1 ) * m + y2 );
                if ( z[ fa ] != z[ fb ] )
                    z[ fb ] = fa;
            }
        }
        else {
            if ( num[ a[ x1 ][ y1 ] - 'A' ][ 3 ] == '1' && num[ a[ x2 ][ y2 ] - 'A' ][ 1 ] == '1' ) {
                int fa = finds( ( x1 - 1 ) * m + y1 ), fb = finds( ( x2 - 1 ) * m + y2 );
                if ( z[ fa ] != z[ fb ] )
                    z[ fb ] = fa;
            }
        }
    }
    else {
        if ( x1 < x2 ) {
            if ( num[ a[ x1 ][ y1 ] - 'A' ][ 2 ] == '1' && num[ a[ x2 ][ y2 ] - 'A' ][ 0 ] == '1' ) {
                int fa = finds( ( x1 - 1 ) * m + y1 ), fb = finds( ( x2 - 1 ) * m + y2 );
                if ( z[ fa ] != z[ fb ] )
                    z[ fb ] = fa;
            }
        }
        else {
            if ( num[ a[ x1 ][ y1 ] - 'A' ][ 0 ] == '1' && num[ a[ x2 ][ y2 ] - 'A' ][ 2 ] == '1' ) {
                int fa = finds( ( x1 - 1 ) * m + y1 ), fb = finds( ( x2 - 1 ) * m + y2 );
                if ( z[ fa ] != z[ fb ] )
                    z[ fb ] = fa;
            }
        }
    }
}
int main() {
    while ( scanf( "%d%d", &n, &m ) != EOF ) {
        if ( n < 0 || m < 0 )
            return 0;
        for ( int i = 1; i <= n; i++ )
            scanf( "%s", a[ i ] + 1 );
        for ( int j = 1; j <= n * m; j++ )
            z[ j ] = j;
        for ( int i = 1; i <= n; i++ ) {
            for ( int j = 1; j <= m; j++ ) {
                if ( i != 1 )
                    join( i, j, i - 1, j );
                if ( j != m )
                    join( i, j, i, j + 1 );
                if ( i != n )
                    join( i, j, i + 1, j );
                if ( j != 1 )
                    join( i, j, i, j - 1 );
            }
        }
        int ans = 0;
        for ( int i = 1; i <= n * m; i++ )
            if ( z[ i ] == i )
                ans++;
        printf( "%d\n", ans );
    }
}
