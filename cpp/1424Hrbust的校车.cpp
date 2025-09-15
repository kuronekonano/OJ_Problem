#include <stdio.h>
int main() {
    int n, m;
    while ( scanf( "%d%d", &n, &m ) != EOF )  /// 分情况讨论，全部情况列出即可
    {
        if ( n == 0 && m != 0 )  /// 没有大人 只有小孩是不可能上车的
        {
            printf( "Impossible\n" );
            continue;
        }
        else if ( n != 0 && m != 0 )  /// 有大人有小孩分两种
        {
            if ( n > m ) {
                printf( "%d %d\n", n, n + m - 1 );  /// 大人多于小孩
            }
            else {
                printf( "%d %d\n", m, n + m - 1 );  /// 其他情况
            }
        }
        else if ( n != 0 && m == 0 )  /// 只有大人
        {
            printf( "%d %d\n", n, n );
        }
        else {
            printf( "0 0\n" );  /// 都没有
        }
    }
    return 0;
}
