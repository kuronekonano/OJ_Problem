#include <algorithm>
#include <stdio.h>   ///严重警告:这题虽然是冒泡次数算逆序数，但是将会有重复的数字出现，这就导致一个很难发现的问题，在排序时，相同数字的位序，排序时根本不知道谁前谁后
#include <string.h>  ///因此排序时注意！如果数字值相同，按照位序从小到大排序
using namespace std;
struct num {
    int n, i;
} a[ 500005 ];
int tree[ 500005 ], ls[ 500005 ], n;
int lowbit( int x ) {
    return x & ( -x );
}
int sum( int p ) {
    int sum = 0;
    while ( p > 0 ) {
        sum += tree[ p ];
        p -= lowbit( p );
    }
    return sum;
}
void update( int p ) {
    while ( p <= n ) {
        tree[ p ]++;
        p += lowbit( p );
    }
}
bool cmp( num a, num b ) {

    if ( a.n == b.n )
        return a.i < b.i;
    return a.n < b.n;
}
int main() {
    while ( scanf( "%d", &n ) && n ) {
        for ( int i = 1; i <= n; i++ ) {
            scanf( "%d", &a[ i ].n );
            a[ i ].i = i;
        }
        sort( a + 1, a + n + 1, cmp );
        for ( int i = 1; i <= n; i++ )
            ls[ a[ i ].i ] = i;
        memset( tree, 0, sizeof( tree ) );
        long long ans = 0;
        for ( int i = 1; i <= n; i++ ) {
            update( ls[ i ] );
            ans += i - sum( ls[ i ] );
            printf( "---->%d  %d\n", i, sum( ls[ i ] ) );
        }
        printf( "%lld\n", ans );
    }
}
