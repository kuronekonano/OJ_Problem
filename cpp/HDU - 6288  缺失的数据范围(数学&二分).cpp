#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define LL long long
using namespace std;
const int maxn = 1e6 + 10;
const LL  inf  = 1000000000000000010;
LL        n, t, a, b;
LL        k;
LL        judge( LL mid ) {
    LL midb = 1;
    LL tmp  = 1;
    LL aa = a, bb = b;
    LL logb = 0;
    while ( tmp < mid ) {
        tmp <<= 1;
        logb++;
    }
    while ( bb-- ) {
        if ( k / midb < logb )
            return inf;
        midb *= logb;
    }
    while ( aa-- ) {
        if ( k / midb < mid )
            return inf;
        midb *= mid;
    }
    return midb;
}
int main() {
    scanf( "%lld", &t );
    while ( t-- ) {
        scanf( "%lld%lld%lld", &a, &b, &k );
        LL l = 0, r = inf;
        LL ans = 1;
        while ( l < r ) {
            LL mid     = ( l + r ) >> 1;
            LL realnum = judge( mid );
            if ( realnum == k )
                break;
            if ( realnum > k ) {
                r = mid - 1;
            }
            else {
                ans = mid;
                l   = mid + 1;
            }
        }
        while ( judge( ans ) <= k )
            ans++;
        printf( "%lld\n", ans - 1 );
    }
}

/*
n^a*[log2n]^b<=k
n*[log2 n] <= 1e8
99
10 10 1000000000000000000
1 1 100000000
2 1 100000000
1 3 200000000
9 9 1000000
*/
