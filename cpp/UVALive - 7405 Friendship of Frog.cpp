#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
    int  t, i, n, pos[ 30 ], dis[ 30 ], cas = 0;
    char a[ 1008 ];
    scanf( "%d", &t );
    while ( t-- ) {
        cas++;
        memset( pos, -1, sizeof( pos ) );
        memset( dis, 0x3f, sizeof( dis ) );
        scanf( "%s", a );
        n = strlen( a );
        for ( i = 0; i < n; i++ ) {
            if ( pos[ a[ i ] - 'a' ] == -1 ) {
                pos[ a[ i ] - 'a' ] = i;
            }
            else {
                if ( dis[ a[ i ] - 'a' ] > i - pos[ a[ i ] - 'a' ] ) {
                    dis[ a[ i ] - 'a' ] = i - pos[ a[ i ] - 'a' ];
                }
                pos[ a[ i ] - 'a' ] = i;
            }
        }
        sort( dis, dis + 26 );
        printf( "Case #%d: %d\n", cas, dis[ 0 ] > 27 ? -1 : dis[ 0 ] );
    }
}
