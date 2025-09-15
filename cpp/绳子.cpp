#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
    int n, a[ 1005 ];
    while ( scanf( "%d", &n ) != EOF )  // 绳子数目
    {
        for ( int i = 0; i < n; i++ )  // 绳子承受力
        {
            scanf( "%d", &a[ i ] );
        }
        sort( a, a + n );  // 排序，从小到大的承受力
        int max = 0;
        for ( int i = 0; i < n; i++ )  // 最小承受力小的绳子，可以包括的绳子越多，因此是当前承受力的绳子，乘上大于此承受力的所有绳子的根数
        {
            a[ i ] = a[ i ] * ( n - i );
            if ( a[ i ] > max ) {
                max = a[ i ];  // 取最大值
            }
        }
        printf( "%d\n", max );
    }
    return 0;
}
