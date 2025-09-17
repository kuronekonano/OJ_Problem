#include <stdio.h>                     ///有n个人，求其中满足至少n-k个人排对位置的种数，也就是有k到0个人排错的种数
long long tC[ 1002 ][ 10 ], cP[ 25 ];  /// 用组合数+错排公式相乘
void      init() {
    for ( int i = 0; i <= 1000; i++ )  /// 组合数预处理的操作！！！
    {
        tC[ i ][ 0 ] = 1;
        for ( int j = 1; j <= 4 && j < i; j++ ) {
            tC[ i ][ j ] = tC[ i - 1 ][ j - 1 ] + tC[ i - 1 ][ j ];
        }
        tC[ i ][ i ] = 1;
    }
    cP[ 0 ] = 1;  /// 所有人都排对的情况
    cP[ 1 ] = 0;
    cP[ 2 ] = 1;
    for ( int i = 3; i <= 20; i++ ) {
        cP[ i ] = ( i - 1 ) * ( cP[ i - 1 ] + cP[ i - 2 ] );  /// 错排递推公式
    }
}
int main() {
    int n, k;
    init();
    while ( scanf( "%d%d", &n, &k ) != EOF ) {
        long long ans = 0;
        for ( int i = k; i >= 0; i-- )  /// 算上i==0时的情况(所有人都排对时)，为1种，这样就不会少+1
        {
            ans += cP[ i ] * tC[ n ][ i ];
        }
        printf( "%lld\n", ans );
    }
}
