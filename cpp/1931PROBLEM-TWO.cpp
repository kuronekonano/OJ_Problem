#include <math.h>
#include <stdio.h>
int main() {
    for ( int i = 1; i <= 10000; i++ ) {
        if ( ( int )sqrt( 100 + i ) * ( int )sqrt( 100 + i ) == ( 100 + i ) )  /// 判断完全平方数，别忘了强制转换
        {
            if ( ( int )sqrt( 268 + i ) * ( int )sqrt( 268 + i ) == ( 268 + i ) )  /// 再加上168
            {
                printf( "%d\n", i );
            }
        }
    }
    return 0;
}
