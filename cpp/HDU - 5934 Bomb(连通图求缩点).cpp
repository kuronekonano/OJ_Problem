#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1008;
struct node {
    double x, y, r;
    int    cos;
} a[ maxn ];
int          n, low[ maxn ], dfn[ maxn ], cnt, in, id[ maxn ], num, cost[ maxn ], inum[ maxn ];
bool         maps[ maxn ][ maxn ], vis[ maxn ];
stack< int > q;
void         tarjan( int u ) {
    int i;
    low[ u ] = dfn[ u ] = ++cnt;
    q.push( u );
    vis[ u ] = true;
    for ( int i = 1; i <= n; i++ ) {
        if ( !maps[ u ][ i ] )
            continue;
        if ( !dfn[ i ] ) {
            tarjan( i );
            low[ u ] = min( low[ u ], low[ i ] );
        }
        else if ( vis[ i ] ) {
            low[ u ] = min( low[ u ], dfn[ i ] );
        }
    }
    if ( low[ u ] == dfn[ u ] ) {
        num++;
        while ( !q.empty() ) {
            int tmp = q.top();
            q.pop();
            id[ tmp ] = num;
            if ( cost[ id[ tmp ] ] > a[ tmp ].cos )
                cost[ id[ tmp ] ] = a[ tmp ].cos;
            vis[ tmp ] = 0;
            if ( tmp == u )
                break;
        }
    }
}
double dis( double x1, double y1, double x2, double y2 ) {
    return sqrt( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) );
}
int main() {
    int t, cas = 1;
    scanf( "%d", &t );
    while ( t-- ) {
        memset( vis, false, sizeof( vis ) );
        memset( maps, false, sizeof( maps ) );
        memset( low, 0, sizeof( low ) );
        memset( dfn, 0, sizeof( dfn ) );
        memset( inum, 0, sizeof( inum ) );
        memset( id, 0, sizeof( id ) );
        memset( cost, 0x3f, sizeof( cost ) );
        while ( !q.empty() )
            q.pop();
        cnt = in = num = 0;
        scanf( "%d", &n );
        for ( int i = 1; i <= n; i++ ) {
            scanf( "%lf%lf%lf%d", &a[ i ].x, &a[ i ].y, &a[ i ].r, &a[ i ].cos );
            for ( int j = 1; j < i; j++ ) {
                double tmp = dis( a[ i ].x, a[ i ].y, a[ j ].x, a[ j ].y );
                if ( a[ i ].r >= tmp )
                    maps[ i ][ j ] = true;
                if ( a[ j ].r >= tmp )
                    maps[ j ][ i ] = true;
            }
        }
        for ( int i = 1; i <= n; i++ )
            if ( !dfn[ i ] )
                tarjan( i );
        for ( int i = 1; i <= n; i++ )
            for ( int j = 1; j <= n; j++ )
                if ( maps[ i ][ j ] && id[ i ] != id[ j ] )
                    inum[ id[ j ] ]++;
        int ans = 0;
        for ( int i = 1; i <= num; i++ )
            if ( !inum[ i ] )
                ans += cost[ i ];
        printf( "Case #%d: %d\n", cas++, ans );
    }
}
