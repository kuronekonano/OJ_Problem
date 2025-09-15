#include <stdio.h>
int main() {
    int m, d, i, a[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    while ( scanf( "%d%d", &m, &d ) != EOF ) {
        int sum = 0;
        if ( m == 2 && d == 29 )  // 四年一次生日，我服
        {
            printf( "11540\n" );
            continue;
        }
        for ( i = 1; i < m; i++ ) {
            sum = sum + a[ i ];
        }
        sum = sum + d;
        printf( "%d\n", ( sum - 1 ) * 10 );
    }
    return 0;
}
