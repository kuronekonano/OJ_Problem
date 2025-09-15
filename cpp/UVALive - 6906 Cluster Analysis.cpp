#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
    int t, a[ 108 ], cas = 1;
    scanf( "%d", &t );
    while ( t-- ) {
        int n, k;
        scanf( "%d%d", &n, &k );
        for ( int i = 0; i < n; i++ )
            scanf( "%d", &a[ i ] );
        sort( a, a + n );
        int ans = 1;
        for ( int i = 0; i < n - 1; i++ )
            if ( a[ i + 1 ] > a[ i ] + k )
                ans++;
        printf( "Case #%d: %d\n", cas++, ans );
    }
}
