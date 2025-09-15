#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
    int n, i, j, a[ 101 ][ 105 ];
    while ( scanf( "%d", &n ) != EOF ) {
        for ( i = 0; i < n; i++ ) {
            for ( j = 0; j <= i; j++ ) {
                scanf( "%d", &a[ i ][ j ] );
            }
        }
        for ( i = n - 2; i >= 0; i-- ) {
            for ( j = 0; j <= i; j++ ) {
                a[ i ][ j ] = max( a[ i ][ j ] + a[ i + 1 ][ j ], a[ i ][ j ] + a[ i + 1 ][ j + 1 ] );
            }
        }
        printf( "%d\n", a[ 0 ][ 0 ] );
    }
    return 0;
}
