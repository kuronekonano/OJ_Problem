#include <stdio.h>
#include <string.h>
int main() {
    char a[ 105 ];
    int  sum, n, i;
    while ( gets( a ) ) {
        n   = strlen( a );
        sum = 0;
        for ( i = 0; i < n; i++ ) {
            if ( a[ i ] == 'T' && a[ i + 1 ] == 'T' || a[ i ] == 'T' && a[ i + 1 ] == '\0' ) {
                sum++;
            }
            else {
                int x = 0;
                while ( a[ i + 1 ] != 'T' && i + 1 < n )  // 检查数字并乘为大数的新方法
                {
                    x = a[ i + 1 ] - '0' + x * 10;
                    i++;
                }
                sum = sum + x * 2;
            }
        }
        printf( "%d\n", sum );
    }
    return 0;
}
