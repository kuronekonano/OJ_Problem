#include <stdio.h>
#include <stdlib.h>
int main() {
    char s[ 20 ];  // 又是一个用到strtlo函数的题，这次是把一个原来是a进制的数字变成十进制，竟然也能用strtol，只需把base值变成原进制a，就可以把字符串输出成十进制
    int  a, t;
    while ( scanf( "%d%s", &a, &s ) != EOF ) {
        t = strtol( s, NULL, a );
        printf( "%ld\n", t );
    }
    return 0;
}
