#include <bits/stdc++.h>
#define LL long long
#define M( a, b ) memset( a, b, sizeof a )
#define pb( x ) push_back( x )
using namespace std;
const int maxn = 1000008;
const LL  inf  = 1LL << 60;
struct edge {
    int nxt, to;
    LL  val;
    edge() {}
    edge( int a, LL b, int c ) {
        to = a, val = b, nxt = c;
    }
} mp[ maxn << 1 ];
int head[ maxn ], cnt;
struct node {
    int to;
    LL  val;
    node( int a, LL b ) {
        to = a, val = b;
    }
    bool operator<( const node& a ) const {
        return val > a.val;
    }
};
void addedge( int from, int to, LL val ) {
    mp[ cnt ]    = edge( to, val, head[ from ] );
    head[ from ] = cnt++;
    mp[ cnt ]    = edge( from, 0, head[ to ] );
    head[ to ]   = cnt++;
}
int  n, m;
void dijkstra( int st, LL dist[] ) {
    bool vis[ maxn ];
    for ( int i = 1; i <= n + m; i++ )
        vis[ i ] = false, dist[ i ] = inf;
    dist[ st ] = 0;
    priority_queue< node > q;
    q.push( node( st, 0 ) );
    while ( !q.empty() ) {
        node tp = q.top();
        q.pop();
        if ( vis[ tp.to ] )
            continue;
        vis[ tp.to ] = true;
        for ( int i = head[ tp.to ]; i != -1; i = mp[ i ].nxt ) {
            edge tmp = mp[ i ];
            if ( dist[ tmp.to ] > tp.val + tmp.val ) {
                dist[ tmp.to ] = tp.val + tmp.val;
                q.push( node( tmp.to, dist[ tmp.to ] ) );
            }
        }
    }
}
LL  dist1[ maxn ], dist2[ maxn ];
int main() {
    int t, x, cas = 0;
    scanf( "%d", &t );
    while ( t-- ) {
        cas++;
        M( head, -1 );
        cnt = 0;
        LL  ti;
        int si;
        scanf( "%d%d", &n, &m );
        for ( int i = 1; i <= m; i++ ) {
            scanf( "%lld%d", &ti, &si );
            for ( int j = 1; j <= si; j++ ) {
                scanf( "%d", &x );
                addedge( x, n + i, ti );
            }
        }
        dijkstra( 1, dist1 );
        if ( dist1[ n ] == inf ) {
            printf( "Case #%d: Evil John\n", cas );
            continue;
        }
        dijkstra( n, dist2 );
        LL mi = inf;
        for ( int i = 1; i <= n; i++ ) {
            LL tmp = max( dist1[ i ], dist2[ i ] );
            if ( tmp < mi )
                mi = tmp;
        }
        printf( "Case #%d: %lld\n", cas, mi );
        bool flag = false;
        for ( int i = 1; i <= n; i++ ) {
            LL tmp = max( dist1[ i ], dist2[ i ] );
            if ( tmp == mi ) {
                if ( !flag )
                    printf( "%d", i ), flag = true;
                else
                    printf( " %d", i );
            }
        }
        puts( "" );
    }
}
