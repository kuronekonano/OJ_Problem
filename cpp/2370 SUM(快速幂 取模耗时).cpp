#include <stdio.h>
#include <string.h>
#define LL long long
using namespace std;
const LL MOD = 1000000007;
LL       a[ 100008 ];
LL       poww( LL a, LL b ) {
    LL ans = 1;
    while ( b ) {
        if ( b & 1 )
            ans = ( ans * ( a % MOD ) ) % MOD;  /// 多次取模会超时
        a = ( a * ( a % MOD ) ) % MOD;
        b >>= 1;
    }
    return ans;
}
int main() {
    int t;
    LL  n, d;
    scanf( "%d", &t );
    while ( t-- ) {
        LL sum = 1;
        scanf( "%lld%lld", &n, &d );
        for ( int i = 2; i <= n; i++ ) {
            sum = ( sum + poww( i, d ) % MOD ) % MOD;  /// 多次取模会超时
        }
        printf( "%lld\n", sum );
    }
}
