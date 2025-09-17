#include <stdio.h>
int main() {
    int t, n, a[ 56 ];
    scanf( "%d", &t );  // 设人数为n，被吹走的帽子为m
    while ( t-- )       // 剩下的帽子为n-m，则带着帽子的人看到的帽子数量为n-m-1，没带帽子的人看见的帽子数量为n-m
    {
        int sum = 0;                    // n-m为带着帽子的人数，m为没带帽子的人数，(n-m)*(n-m-1)+m*(n-m)=sum
        scanf( "%d", &n );              //(n-m)*(n-1)=sum
        for ( int i = 1; i <= n; i++ )  // 所有人看到的帽子数量sum一定为剩下帽子数量的n-1倍
        {
            scanf( "%d", &a[ i ] );
            sum = sum + a[ i ];
        }
        if ( sum % ( n - 1 ) == 0 ) {
            printf( "%d\n", sum / ( n - 1 ) );
        }
        else
            printf( "-1\n" );
    }
    return 0;
}
