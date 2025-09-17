#include <bits/stdc++.h>
using namespace std;
const int                                            maxn = 505;
int                                                  n, m;
int                                                  vis[ maxn ];
bool                                                 mp[ maxn ][ maxn ];
priority_queue< int, vector< int >, greater< int > > q;
int                                                  main() {
    while ( scanf( "%d%d", &n, &m ) != EOF ) {
        int p1, p2;
        while ( !q.empty() )
            q.pop();
        memset( vis, 0, sizeof( vis ) );
        memset( mp, false, sizeof( mp ) );
        for ( int i = 0; i < m; i++ ) {
            scanf( "%d%d", &p1, &p2 );
            if ( !mp[ p1 ][ p2 ] ) {
                mp[ p1 ][ p2 ] = true;
                vis[ p2 ]++;
            }
        }
        for ( int i = 1; i <= n; i++ )
            if ( vis[ i ] == 0 )
                q.push( i ), vis[ i ]--;
        int cnt = 0;
        while ( !q.empty() ) {
            int tmp = q.top();
            q.pop();
            cnt++;
            printf( "%d%c", tmp, cnt == n ? '\n' : ' ' );
            if ( cnt == n )
                break;
            for ( int i = 1; i <= n; i++ ) {
                if ( mp[ tmp ][ i ] && vis[ i ] > 0 )
                    vis[ i ]--;
                if ( vis[ i ] == 0 )
                    q.push( i ), vis[ i ]--;
            }
        }
    }
}
