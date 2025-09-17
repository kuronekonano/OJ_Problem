#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
int  dist[ 203 ], n, m, mp[ 206 ][ 206 ];
bool vis[ 203 ];
void SPFA( int s ) {
    queue< int > q;
    while ( !q.empty() )
        q.pop();
    memset( dist, 0x3f, sizeof( dist ) );
    memset( vis, false, sizeof( vis ) );
    dist[ s ] = 0;
    vis[ s ]  = true;
    q.push( s );
    while ( !q.empty() ) {
        int top = q.front();
        q.pop();
        vis[ top ] = false;
        for ( int i = 0; i < n; i++ ) {
            if ( dist[ i ] > dist[ top ] + mp[ top ][ i ] ) {
                dist[ i ] = dist[ top ] + mp[ top ][ i ];
                if ( !vis[ i ] ) {
                    vis[ i ] = true;
                    q.push( i );
                }
            }
        }
    }
}
int main() {
    while ( scanf( "%d%d", &n, &m ) != EOF ) {
        int from, to, val;
        memset( mp, 0x3f, sizeof( mp ) );
        for ( int i = 0; i < m; i++ ) {
            scanf( "%d%d%d", &from, &to, &val );
            if ( mp[ from ][ to ] > val )
                mp[ from ][ to ] = mp[ to ][ from ] = val;
        }
        int s, e;
        scanf( "%d%d", &s, &e );
        SPFA( s );
        printf( "%d\n", dist[ e ] == 0x3f3f3f3f ? -1 : dist[ e ] );
    }
}
