#include <stdio.h>
int people[ 1000000 ];
int find( int a ) {
    int r = a, t;
    while ( r != people[ r ] ) {
        t           = r;
        r           = people[ r ];
        people[ t ] = people[ r ];
    }
    return r;
}
void join( int x, int y ) {
    int fa = find( x ), fb = find( y );
    if ( fa != fb ) {
        people[ fa ] = fb;
    }
}
int main() {
    int t, m, n, i, j, x, y;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d%d", &m, &n );
        for ( i = 1; i <= m; i++ ) {
            people[ i ] = i;
        }
        for ( i = 1; i <= n; i++ ) {
            scanf( "%d%d", &x, &y );
            join( x, y );
        }
        int ans = 0;
        for ( i = 1; i <= m; i++ ) {
            if ( people[ i ] == i )
                ans++;
        }
        printf( "%d\n", ans );
    }
}
