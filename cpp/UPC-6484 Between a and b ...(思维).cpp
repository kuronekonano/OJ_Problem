#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 10;
LL        a, b, x;
int       main() {
    while ( scanf( "%lld%lld%lld", &a, &b, &x ) != EOF ) {
        LL ans = b / x - a / x;
        if ( a % x == 0 )
            ans++;
        printf( "%lld\n", ans );
    }
}
