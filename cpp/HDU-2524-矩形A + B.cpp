#include <stdio.h>
int main() {
    int a[ 109 ], i, t, n, m;
    a[ 0 ] = 0;
    for ( i = 1; i <= 100; i++ )
        a[ i ] = a[ i - 1 ] + i;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d%d", &n, &m );
        printf( "%d\n", a[ n ] * a[ m ] );
    }
}
