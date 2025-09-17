#include <algorithm>
#include <stdio.h>  ///将LCS问题转换为LIS问题，记录相同数字的位序，与另一个串的位序相匹配，并求LIS
#include <string.h>
using namespace std;
int main() {
    int t, p, q, pos[ 10008 ], a[ 10008 ], maxx[ 10008 ];
    scanf( "%d", &t );
    while ( t-- ) {
        memset( pos, 0, sizeof( pos ) );
        scanf( "%d%d", &p, &q );
        for ( int i = 1; i <= p; i++ )
            scanf( "%d", &a[ i ] ),
                pos[ a[ i ] ] = i;  /// 记录A串中每个字符出现的位置字符a[i]出现在位置i
        for ( int i = 1; i <= q; i++ )
            scanf( "%d", &a[ i ] ), a[ i ] = pos[ a[ i ] ];  /// 对于B串
        maxx[ 1 ] = a[ 1 ];
        int flag  = 1;
        for ( int i = 2; i <= q; i++ ) {
            if ( a[ i ] > maxx[ flag ] )
                maxx[ ++flag ] = a[ i ];
            else {
                int half     = lower_bound( maxx + 1, maxx + flag, a[ i ] ) - maxx;
                maxx[ half ] = a[ i ];
            }
        }
        printf( "%d\n", flag );
    }
}
