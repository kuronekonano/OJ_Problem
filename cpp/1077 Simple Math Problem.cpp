#include <stdio.h>
/// 打表判断，发现只有1 2 3是整数
int main() {
    int a;
    while ( scanf( "%d", &a ) != EOF ) {
        if ( a == 1 || a == 2 || a == 3 ) {
            printf( "yes\n" );
        }
        else {
            printf( "no\n" );
        }
    }
    return 0;
}
