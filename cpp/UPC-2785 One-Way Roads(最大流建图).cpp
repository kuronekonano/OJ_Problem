#include <bits/stdc++.h>
#define LL long long
#define M( a, b ) memset( a, b, sizeof a )
#define pb( x ) push_back( x )
using namespace std;
const int maxn = 5080;
const int inf  = 0x3f3f3f3f;
struct edge {
    int to, val, nxt;
    edge() {}
    edge( int a, int b, int c ) {
        to = a, val = b, nxt = c;
    }
} mp[ maxn * 10 ];
int head[ maxn ], cnt;
int n, m;
struct node {
    int from, to;
} a[ maxn ];
void addedge( int from, int to, int val ) {
    mp[ cnt ]    = edge( to, val, head[ from ] );
    head[ from ] = cnt++;
    mp[ cnt ]    = edge( from, 0, head[ to ] );
    head[ to ]   = cnt++;
}
int  dep[ maxn ];
bool bfs( int st, int ed ) {
    M( dep, -1 );
    queue< int > q;
    while ( !q.empty() )
        q.pop();
    dep[ st ] = 0;
    q.push( st );
    while ( !q.empty() ) {
        int tmp = q.front();
        q.pop();
        if ( tmp == ed )
            return true;
        for ( int i = head[ tmp ]; i != -1; i = mp[ i ].nxt ) {
            int &to = mp[ i ].to, flow = mp[ i ].val;
            if ( dep[ to ] == -1 && flow ) {
                dep[ to ] = dep[ tmp ] + 1;
                q.push( to );
                if ( to == ed )
                    return true;
            }
        }
    }
    return false;
}
int cur[ maxn ];
int dfs( int s, int t, int flow ) {
    if ( s == t || flow == 0 )
        return flow;
    int pre = 0;
    for ( int& i = cur[ s ]; i != -1; i = mp[ i ].nxt ) {
        int &to = mp[ i ].to, val = mp[ i ].val;
        if ( dep[ s ] + 1 == dep[ to ] && val ) {
            int tmp = min( flow - pre, val );
            int sub = dfs( to, t, tmp );
            mp[ i ].val -= sub;
            mp[ i ^ 1 ].val += sub;
            pre += sub;
            if ( pre == flow )
                return pre;
        }
    }
    return pre;
}
int dinic( int st, int ed ) {
    int ans = 0;
    while ( bfs( st, ed ) ) {
        for ( int i = 1; i <= n + m + 2; i++ )
            cur[ i ] = head[ i ];
        ans += dfs( st, ed, inf );
    }
    return ans;
}
bool judge( int x ) {
    M( head, -1 );
    cnt    = 0;
    int st = n + m + 1;
    int ed = st + 1;
    for ( int i = 1; i <= m; i++ ) {
        addedge( st, i, 1 );
        addedge( i, m + a[ i ].from, 1 );
        addedge( i, m + a[ i ].to, 1 );
    }
    for ( int i = 1; i <= n; i++ )
        addedge( m + i, ed, x );
    return dinic( st, ed ) == m;
}
int main() {
    scanf( "%d%d", &n, &m );
    for ( int i = 1; i <= m; i++ )
        scanf( "%d%d", &a[ i ].from, &a[ i ].to );
    int l = 0, r = n, ans = 0;
    while ( l <= r ) {
        int mid = ( l + r ) >> 1;
        if ( judge( mid ) )
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    printf( "%d\n", ans );
}
