#include <algorithm>
#include <stdio.h>
#define LL long long
using namespace std;
const int maxn = 2e5 + 10;
LL        sum[ maxn ], a[ maxn ], num[ maxn ];
int       main() {
    int n, m;
    while ( scanf( "%d%d", &n, &m ) != EOF ) {
        sum[ 0 ] = sum[ 1 ] = 0;
        for ( int i = 1; i <= n; i++ ) {
            scanf( "%lld", &a[ i ] );
            sum[ i + 1 ] += sum[ i ] + a[ i ];
        }
        for ( int i = 1; i <= m; i++ )
            scanf( "%lld", &num[ i ] );
        for ( int i = 1; i <= m; i++ ) {
            LL tmp = lower_bound( sum + 1, sum + n + 1, num[ i ] ) - sum - 1;
            printf( "%lld %lld\n", tmp, num[ i ] - sum[ tmp ] );
        }
    }
}
