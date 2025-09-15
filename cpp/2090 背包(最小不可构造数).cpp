#include <stdio.h>
int n, i, a[ 10000005 ];
int main() {
    int t;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &n );
        for ( i = 0; i < n; i++ ) {
            scanf( "%d", &a[ i ] );
        }
        long long sum = 1;         /// sum表示将要表示的下一个数
        for ( i = 0; i < n; i++ )  /// 如，先判断sum=1时，是否能构造，如果最小的数都大于1，那么就无法构造，如果能构造，那说明有1，加到sum上，sum=2，再用下一个a[i]判断是否能构造出2这个数
        {                          /// 如果下一个a[i]>sum,也就是说除了1外无法构造出2本身，就break掉。
            /// 接下来的3,4,5同理，如果有了1,2，再判断3，有了1，2，3再判断6，如果a[i]<6那么就可以被之前存在的任一一个数构造出来
            if ( a[ i ] <= sum )  /// 判断在有序的序列中，是否能利用当前a[i]表示sum
            {                     /// 如果a[i]比sum还大，那么从上一个数到sum这段区间就有数无法表示
                sum += a[ i ];
            }
            else
                break;
        }
        printf( "%lld\n", sum );
    }
    return 0;
}
