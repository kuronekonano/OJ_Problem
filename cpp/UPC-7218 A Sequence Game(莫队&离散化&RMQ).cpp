#include <bits/stdc++.h>
#define LL long long
#define M( a, b ) memset( a, b, sizeof a )
#define pb( x ) push_back( x )
using namespace std;
const int     maxn = 1e5 + 7;
int           dmin[ maxn ][ 18 ];
int           dmax[ maxn ][ 18 ];
int           cnt[ maxn ];
int           pos[ maxn ], id[ maxn ];
bool          ans[ maxn ];
int           n, m, t, sum;
vector< int > a, b;
struct node {
    int  l, r, id;
    bool operator<( const node& a ) const {
        return pos[ l ] == pos[ a.l ] ? r < a.r : pos[ l ] < pos[ a.l ];
    }
} q[ maxn ];
int getid( int x ) {
    return lower_bound( a.begin(), a.end(), x ) - a.begin() + 1;
}
int rmq( int l, int r ) {
    int k    = log2( r - l + 1 );
    int minn = min( dmin[ l ][ k ], dmin[ r - ( 1 << k ) + 1 ][ k ] );
    int maxx = max( dmax[ l ][ k ], dmax[ r - ( 1 << k ) + 1 ][ k ] );
    return maxx - minn + 1;
}
void add( int x ) {
    if ( cnt[ id[ x ] ] == 0 )
        sum++;
    cnt[ id[ x ] ]++;
}
void del( int x ) {
    cnt[ id[ x ] ]--;
    if ( cnt[ id[ x ] ] == 0 )
        sum--;
}
int main() {
    scanf( "%d", &t );
    while ( t-- ) {
        M( cnt, 0 );
        a.clear();
        b.clear();
        scanf( "%d%d", &n, &m );
        int sz = sqrt( n );
        for ( int i = 1; i <= n; i++ ) {
            scanf( "%d", &dmax[ i ][ 0 ] );
            dmin[ i ][ 0 ] = dmax[ i ][ 0 ];
            a.pb( dmax[ i ][ 0 ] );
            pos[ i ] = i / sz;
        }
        b = a;
        sort( a.begin(), a.end() );
        a.erase( unique( a.begin(), a.end() ), a.end() );
        for ( int i = 1; i <= n; i++ )
            id[ i ] = getid( b[ i - 1 ] );
        for ( int j = 1; ( 1 << j ) < n; j++ )
            for ( int i = 1; i + ( 1 << j ) - 1 <= n; i++ ) {
                dmin[ i ][ j ] = min( dmin[ i ][ j - 1 ], dmin[ i + ( 1 << ( j - 1 ) ) ][ j - 1 ] );
                dmax[ i ][ j ] = max( dmax[ i ][ j - 1 ], dmax[ i + ( 1 << ( j - 1 ) ) ][ j - 1 ] );
            }
        for ( int i = 1; i <= m; i++ )
            scanf( "%d%d", &q[ i ].l, &q[ i ].r ), q[ i ].id = i;
        sort( q + 1, q + 1 + m );
        int L = 1, R = 0;
        sum = 0;
        for ( int i = 1; i <= m; i++ ) {
            while ( L < q[ i ].l )
                del( L++ );
            while ( L > q[ i ].l )
                add( --L );
            while ( R < q[ i ].r )
                add( ++R );
            while ( R > q[ i ].r )
                del( R-- );
            ans[ q[ i ].id ] = rmq( q[ i ].l, q[ i ].r ) == sum ? true : false;
        }
        for ( int i = 1; i <= m; i++ )
            printf( "%s\n", ans[ i ] ? "YES" : "NO" );
    }
}
