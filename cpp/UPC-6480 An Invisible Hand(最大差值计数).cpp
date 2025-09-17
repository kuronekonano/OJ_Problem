#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int       n, a[ maxn ], t;
int       main() {
    while ( scanf( "%d%d", &n, &t ) != EOF ) {
        int mindis = 0;
        int minum  = 0x7fffffff;
        int ans    = 0;
        for ( int i = 1; i <= n; i++ ) {
            scanf( "%d", &a[ i ] );
            if ( a[ i ] < minum )
                minum = a[ i ];
            if ( a[ i ] > minum ) {
                if ( mindis < a[ i ] - minum ) {
                    ans    = 1;
                    mindis = a[ i ] - minum;
                }
                else if ( mindis == a[ i ] - minum )
                    ans++;
            }
        }
        //        printf("====%d\n",mindis);
        printf( "%d\n", ans );
    }
}
/*
7 10
7 8 2 4 3 6 1
*/
