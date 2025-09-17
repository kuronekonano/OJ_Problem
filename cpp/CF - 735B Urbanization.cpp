#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
    int n, n1, n2, a[ 100008 ], i;
    while ( scanf( "%d%d%d", &n, &n1, &n2 ) != EOF ) {
        for ( i = 0; i < n; i++ ) {
            scanf( "%d", &a[ i ] );
        }
        sort( a, a + n );
        double minn = min( n1, n2 );
        double maxn = max( n1, n2 );
        double sum  = 0;
        for ( i = 0; i < minn; i++ ) {
            sum += a[ --n ];
        }
        double ans = sum / minn;
        sum        = 0;
        for ( i = 0; i < maxn; i++ ) {
            sum += a[ --n ];
        }
        ans += sum / maxn;
        printf( "%.8f\n", ans );
    }
}
