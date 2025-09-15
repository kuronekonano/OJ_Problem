#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, a[ 10008 ];
    while ( scanf( "%d", &n ) != EOF ) {
        for ( int i = 0; i < n; i++ )
            scanf( "%d", &a[ i ] );
        int num = 0, ans = 0;
        while ( 1 ) {
            for ( int i = 0; i < n; i++ ) {
                if ( a[ i ] < 0 ) {
                    a[ i ] = abs( a[ i ] );
                    a[ ( i - 1 + n ) % n ] -= a[ i ];
                    a[ ( i + 1 ) % n ] -= a[ i ];
                    num++;
                }
            }
            if ( num == 0 )
                break;
            else
                ans += num, num = 0;
        }
        printf( "%d\n", ans );
    }
}
