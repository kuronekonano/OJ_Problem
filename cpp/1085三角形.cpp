#include <stdio.h>
int main() {
    int    x1, x2, x3, t, d, h, a;  // 输入的高度h特么用不着，x3特么也用不着！！！！
    double k;
    scanf( "%d", &t );
    for ( i = 1; i <= t; i++ ) {
        scanf( "%d%d%d%d%d", &x1, &x2, &x3, &h, &d );
        a = ( x1 + x2 ) / 2;
        if ( a > d || d < x1 ) {
            printf( "JiaoZhuV5!\n" );
        }
        else
            printf( "Orz!\n" );
    }
    return 0;
}
