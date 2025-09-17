#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
    int a[ 105 ][ 111 ], n, i, j;
    while ( scanf( "%d", &n ) != EOF ) {
        for ( i = 0; i < n; i++ ) {
            for ( j = 0; j <= i; j++ ) {
                scanf( "%d", &a[ i ][ j ] );
            }
        }
        for ( i = n - 2; i >= 0; i-- )  // 从倒数第二行开始找
        {
            for ( j = 0; j <= i; j++ ) {
                a[ i ][ j ] = a[ i ][ j ] + max( a[ i + 1 ][ j ], a[ i + 1 ][ j + 1 ] );
            }
        }
        printf( "%d\n", a[ 0 ][ 0 ] );
    }
    return 0;
}
