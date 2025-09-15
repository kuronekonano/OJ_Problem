#include <stdio.h>   ///允许有一个以上最高的人
#include <string.h>  ///左右各进行一边最长递增子序列
int main() {
    int    n, maxn[ 1050 ], minn[ 1050 ];
    double a[ 1050 ];
    while ( scanf( "%d", &n ) != EOF ) {
        for ( int i = 0; i < n; i++ )
            scanf( "%lf", &a[ i ] );
        memset( maxn, 0, sizeof( maxn ) );
        memset( minn, 0, sizeof( minn ) );
        maxn[ 0 ]     = 1;
        minn[ n - 1 ] = 1;
        for ( int i = 1, x = n - 2; i < n; i++, x-- ) {
            int flag = 0, flag2 = 0;
            for ( int j = 0; j < i; j++ )
                if ( a[ i ] > a[ j ] && maxn[ j ] > flag )
                    flag = maxn[ j ];
            maxn[ i ] = flag + 1;
            for ( int j = n - 1; j > x; j-- )
                if ( a[ x ] > a[ j ] && minn[ j ] > flag2 )
                    flag2 = minn[ j ];
            minn[ x ] = flag2 + 1;
        }
        int ans = 0;
        for ( int i = 0; i < n; i++ )
            for ( int j = i + 1; j < n; j++ )
                if ( ans < maxn[ i ] + minn[ j ] )
                    ans = maxn[ i ] + minn[ j ];
        printf( "%d\n", n - ans );
    }
}
