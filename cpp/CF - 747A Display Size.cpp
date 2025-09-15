#include <math.h>
#include <stdio.h>
int main() {
    int n, i;
    while ( scanf( "%d", &n ) != EOF ) {
        for ( i = sqrt( n ); i >= 1; i-- ) {
            if ( n % i == 0 ) {
                break;
            }
        }
        printf( "%d %d\n", i, n / i );
    }
}
