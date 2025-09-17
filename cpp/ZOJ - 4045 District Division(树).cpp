#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int     maxn = 100005;
int           n, t, k;
vector< int > mp[ maxn ];
vector< int > ans;
bool          vis[ maxn ];
int           sum[ maxn ], fa[ maxn ];
void          dfs1( int rt, int pre ) {
    sum[ rt ] = 1;
    fa[ rt ]  = pre;
    for ( int i = 0; i < mp[ rt ].size(); i++ ) {
        int v = mp[ rt ][ i ];
        if ( mp[ rt ][ i ] != pre ) {
            dfs1( v, rt );
            sum[ rt ] += sum[ v ];
        }
    }
}
void dfs2( int rt, int pre ) {
    if ( sum[ rt ] % k == 0 )
        ans.push_back( rt ), vis[ rt ] = true;
    for ( int i = 0; i < mp[ rt ].size(); i++ )
        if ( mp[ rt ][ i ] != pre )
            dfs2( mp[ rt ][ i ], rt );
}
int dfs3( int rt, int pre ) {
    for ( int i = 0; i < mp[ rt ].size(); i++ ) {
        if ( !vis[ mp[ rt ][ i ] ] && mp[ rt ][ i ] != pre ) {
            printf( " %d", mp[ rt ][ i ] );
            dfs3( mp[ rt ][ i ], rt );
        }
    }
}
bool judge() {
    if ( ans.size() != n / k )
        return false;
    return true;
}
int main() {
    scanf( "%d", &t );
    while ( t-- ) {
        int from, to;
        scanf( "%d%d", &n, &k );
        ans.clear();
        for ( int i = 0; i <= n; i++ )
            mp[ i ].clear();
        memset( vis, false, sizeof vis );
        for ( int i = 0; i < n - 1; i++ ) {
            scanf( "%d%d", &from, &to );
            mp[ from ].push_back( to );
            mp[ to ].push_back( from );
        }
        dfs1( 1, 0 );
        dfs2( 1, 0 );
        bool ju = judge();
        printf( "%s\n", ju ? "YES" : "NO" );
        if ( ju ) {
            for ( int i = 0; i < ans.size(); i++ ) {
                printf( "%d", ans[ i ] );
                dfs3( ans[ i ], fa[ ans[ i ] ] );
                printf( "\n" );
            }
        }
    }
}
