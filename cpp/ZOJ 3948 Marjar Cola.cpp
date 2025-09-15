#include <stdio.h>
int main() {
    int i, j, x, y, a, b;
    int t;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d%d%d%d", &x, &y, &a, &b );

        int sum = 0, num = 0;
        int one;
        while ( a >= x || b >= y ) {
            num = a / x + b / y;
            sum = sum + num;
            a   = a % x + num;
            b   = b % y + num;
            num = 0;
            if ( sum > 1000 ) {
                break;
            }
        }
        if ( sum > 1000 ) {
            printf( "INF\n" );
            continue;
        }
        printf( "%d\n", sum );
    }
    return 0;
}
