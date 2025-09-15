#include <bits/stdc++.h>
#define LL long long
#define M( a, b ) memset( a, b, sizeof a )
#define pb( x ) push_back( x )
using namespace std;
const int maxn = 1e5 + 7;
struct edge {
    int to, nxt;
    edge() {}
    edge( int a, int b ) {
        to  = a;
        nxt = b;
    }
} mp[ maxn * 3 ];
int  head[ maxn ], cnt;
int  n, m, du[ maxn ], sum[ maxn ];
void addedge( int to, int from ) {
    du[ to ]++, du[ from ]++;
    mp[ cnt ]    = edge( to, head[ from ] );
    head[ from ] = cnt++;
    mp[ cnt ]    = edge( from, head[ to ] );
    head[ to ]   = cnt++;
}
int dfs( int x ) {
    if ( sum[ x ] )
        return sum[ x ];
    for ( int i = head[ x ]; i != -1; i = mp[ i ].nxt ) {
        if ( du[ mp[ i ].to ] <= du[ x ] )
            continue;
        sum[ x ] = max( sum[ x ], dfs( mp[ i ].to ) + 1 );
    }
    return sum[ x ];
}
int main() {
    int from, to, ans = 0;
    cnt = 0;
    M( head, -1 );
    M( du, 0 );
    M( sum, 0 );
    scanf( "%d%d", &n, &m );
    for ( int i = 1; i <= m; i++ )
        scanf( "%d%d", &from, &to ), addedge( from, to );
    for ( int i = 0; i < n; i++ )
        ans = max( ans, dfs( i ) + 1 );
    printf( "%d\n", ans );
}
