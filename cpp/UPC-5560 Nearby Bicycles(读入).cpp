#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL     px[ 1005 ], py[ 1005 ], cx[ 1005 ], cy[ 1005 ];
double dis[ 1005 ][ 1005 ];
double cal( int x, int y ) {
    return sqrt( ( px[ x ] - cx[ y ] ) * ( px[ x ] - cx[ y ] ) + ( py[ x ] - cy[ y ] ) * ( py[ x ] - cy[ y ] ) );
}
int main() {
    int n, m;
    while ( scanf( "%d%d", &m, &n ) != EOF ) {
        if ( m == 0 && n == 0 )
            break;
        getchar();
        char b;
        for ( int i = 0; i < m; i++ ) {
            while ( b != '(' )
                b = getchar();
            b = ' ';
            scanf( "%lld,%lld)", &cx[ i ], &cy[ i ] );
            //            printf("%d===%lld %lld\n",i,cx[i],cy[i]);
        }
        for ( int i = 0; i < n; i++ ) {
            while ( b != '(' )
                b = getchar();
            b = ' ';
            scanf( "%lld,%lld)", &px[ i ], &py[ i ] );
            for ( int j = 0; j < m; j++ )
                dis[ i ][ j ] = cal( i, j );
        }
        int flag;
        for ( int i = 0; i < n; i++ ) {
            int ans = 0;
            scanf( "%d", &flag );
            for ( int j = 0; j < m; j++ )
                if ( dis[ i ][ j ] <= flag )
                    ans++;
            printf( "%d%c", ans, i == n - 1 ? '\n' : ' ' );
        }
    }
}
