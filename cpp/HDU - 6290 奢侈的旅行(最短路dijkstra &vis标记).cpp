#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 200005;
const LL  inf  = 1LL << 60;
LL        b2pow[ 70 ];
int       n, m, t;
int       head[ maxn ], cnt;
struct edge {
    LL  a;
    int to, b, next;
} mp[ maxn ];
void add( int from, int to, LL a, int b ) {
    mp[ ++cnt ].next = head[ from ];
    mp[ cnt ].to     = to;
    mp[ cnt ].a      = a;
    mp[ cnt ].b      = b;
    head[ from ]     = cnt;
}
struct Edge {
    LL  dist;
    int to;
    Edge( int a, LL b ) {
        to   = a;
        dist = b;
    }
    bool operator<( const Edge& k ) const {
        return dist > k.dist;
    }
};
void init() {
    b2pow[ 0 ] = 1;
    for ( int i = 1; i <= 60; i++ )
        b2pow[ i ] = b2pow[ i - 1 ] << 1;
}
LL   dist[ maxn ];
void dijkstra( int s ) {
    bool vis[ maxn ];
    for ( int i = 0; i <= n; i++ )
        dist[ i ] = inf;
    for ( int i = 0; i <= n; i++ )
        vis[ i ] = false;
    dist[ s ] = 1;
    priority_queue< Edge > q;
    q.push( Edge( s, dist[ s ] ) );
    while ( !q.empty() ) {
        Edge top = q.top();
        q.pop();
        if ( vis[ top.to ] )
            continue;
        vis[ top.to ] = true;
        for ( int i = head[ top.to ]; i != 0; i = mp[ i ].next ) {
            edge tmp = mp[ i ];
            if ( tmp.a / dist[ top.to ] + 1 < b2pow[ tmp.b ] )
                continue;
            if ( dist[ tmp.to ] > tmp.a + dist[ top.to ] ) {
                dist[ tmp.to ] = tmp.a + dist[ top.to ];
                q.push( Edge( tmp.to, dist[ tmp.to ] ) );
            }
        }
    }
}
int main() {
    init();
    scanf( "%d", &t );
    while ( t-- ) {
        int from, to, b;
        LL  a;
        cnt = 0;
        for ( int i = 0; i <= n; i++ )
            head[ i ] = 0;
        scanf( "%d%d", &n, &m );
        for ( int i = 0; i < m; i++ ) {
            scanf( "%d%d%lld%d", &from, &to, &a, &b );
            add( from, to, a, b );
        }
        dijkstra( 1 );
        printf( "%.0f\n", dist[ n ] == inf ? -1 : floor( log2( dist[ n ] ) ) );
    }
}
