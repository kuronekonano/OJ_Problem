#include <stdio.h>
int yueshu( int a, int b )  // 专门找最大公约数的函数
{
    int t;
    while ( a % b != 0 ) {
        t = a % b;
        a = b;
        b = t;
    }
    return b;
}
int main() {
    int t, a, b, c, i;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d%d", &a, &b );
        for ( i = 2;; i++ ) {
            c = b * i;
            if ( yueshu( a, c ) == b ) {
                printf( "%d\n", c );
                break;
            }
        }
    }
    return 0;
}
