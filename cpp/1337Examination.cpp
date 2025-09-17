#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
    int n, m, k, i;
    int a[ 1009 ], flag = 0;
    while ( scanf( "%d%d%d", &n, &m, &k ) != EOF ) {
        flag++;
        for ( i = 0; i < n * m; i++ ) {
            scanf( "%d", &a[ i ] );
        }
        sort( a, a + n * m );
        printf( "Scenario #%d\n", flag );
        printf( "%d\n\n", a[ n * m - k ] );
    }
    return 0;
}
