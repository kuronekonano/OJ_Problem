#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 10;
int       n, x;
LL        a[ maxn ];
int       main() {
    while ( scanf( "%d%d", &n, &x ) != EOF ) {
        LL ans = 0;
        for ( int i = 1; i <= n; i++ ) {
            scanf( "%d", &a[ i ] );
            if ( a[ i ] > x )
                ans += a[ i ] - x, a[ i ] = x;
        }
        for ( int i = 2; i <= n; i++ )
            if ( a[ i ] + a[ i - 1 ] > x ) {
                LL tmp = a[ i ] + a[ i - 1 ];
                a[ i ] -= tmp - x;
                ans += tmp - x;
            }
        printf( "%lld\n", ans );
    }
}
