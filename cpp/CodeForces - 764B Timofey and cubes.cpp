#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
    int n, a[ 200008 ], i;
    while ( scanf( "%d", &n ) != EOF ) {
        for ( i = 1; i <= n; i++ )
            scanf( "%d", &a[ i ] );
        for ( i = 1; i <= n / 2; i++ )
            if ( i % 2 )
                swap( a[ i ], a[ n - i + 1 ] );
        for ( i = 1; i <= n; i++ )
            printf( "%d%c", a[ i ], i == n ? '\n' : ' ' );
    }
}
