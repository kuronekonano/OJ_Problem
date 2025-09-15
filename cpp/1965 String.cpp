#include <stdio.h>   ///gets方法，还有一种scanf方法，区别在于
#include <string.h>  ///这里停止while用！=NULL，而且因为gets读取回车，当什么都不输入的时候会判断成yes，此时应该什么都不输出
int main() {
    char a[ 1005 ];
    int  n, i, j, flag;
    while ( gets( a ) != NULL ) {
        if ( strlen( a ) == NULL )  /// 为解决这个问题，要判断如果s为空，则从头开始，这样就不会有输出了
        {
            continue;
        }
        flag = 0;
        n    = strlen( a );
        for ( i = 1; i < n; i++ ) {
            for ( j = 0; j < i; j++ ) {
                if ( a[ i ] == a[ j ] ) {
                    flag++;
                    continue;
                }
            }
        }
        if ( flag != 0 ) {
            printf( "no\n" );
        }
        else if ( flag == 0 ) {
            printf( "yes\n" );
        }
    }
    return 0;
}
