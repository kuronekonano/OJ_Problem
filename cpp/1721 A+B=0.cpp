#include <algorithm>
#include <map>
#include <stdio.h>  ///map”¶”√
using namespace std;
int main() {
    int t, i, n;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &n );
        int              temp[ 100008 ];
        map< int, bool > q;
        q.clear();
        int zero = 0;
        for ( i = 1; i <= n; i++ ) {
            scanf( "%d", &temp[ i ] );
            q[ temp[ i ] ] = true;
            if ( temp[ i ] == 0 )
                zero++;
        }
        if ( n == 1 ) {
            printf( "<empty>\n" );
            continue;
        }
        sort( temp + 1, temp + n + 1 );
        bool flag = false;
        for ( i = 1; temp[ i ] < 0; i++ ) {
            if ( q[ -temp[ i ] ] && q[ temp[ i ] ] ) {
                flag = true;
                printf( "%d %d\n", temp[ i ], -temp[ i ] );
                q[ temp[ i ] ] = false;
            }
        }
        if ( zero > 1 ) {
            flag = true;
            printf( "0 0\n" );
        }
        if ( !flag )
            printf( "<empty>\n" );
        printf( "\n" );
    }
}
