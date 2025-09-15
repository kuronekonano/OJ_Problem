#include <stdio.h>
int main() {
    int x1, x2, x3, y1, y2, y3;
    while ( scanf( "%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3 ) != EOF ) {
        if ( x2 * y1 == x1 * y2 && x2 * y3 == x3 * y2 && x1 * y3 == x3 * y1 ) {
            printf( "JiaoZhuV5!\n" );
        }
        else {
            printf( "Orz!\n" );
        }
    }
    return 0;
}
