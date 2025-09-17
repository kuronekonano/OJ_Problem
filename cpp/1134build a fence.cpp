#include <math.h>
#include <stdio.h>
int main() {
    double area, l, pi = acos( -1 );  // 最大面积则为半圆，记住acos(-1)时等于π
    while ( scanf( "%lf", &l ) ) {
        if ( l == 0 )
            break;
        area = ( l / pi ) * ( l / pi ) * pi / 2;
        printf( "%.2f\n", area );
    }
    return 0;
}
