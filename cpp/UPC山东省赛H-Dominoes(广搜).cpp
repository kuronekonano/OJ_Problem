#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn = 1e4 + 9;
struct node {
    int x, y, dir;
    node() {}
    node( int a, int b, int c ) {
        x   = a;
        y   = b;
        dir = c;
    }
};
int           walkx[] = { 1, 0, -1, 0 };
int           walky[] = { 0, -1, 0, 1 };
int           n, m, k;
bool          vis[ 11 ][ maxn ];
short int     mp[ 11 ][ maxn ];
queue< node > q;

int main() {
    while ( scanf( "%d%d%d", &n, &m, &k ) != EOF ) {
        int x1, y1, x2, y2;
        while ( !q.empty() )
            q.pop();
        memset( mp, 0, sizeof( mp ) );
        memset( vis, false, sizeof vis );
        for ( int i = 0; i < k; i++ ) {
            scanf( "%d%d%d%d", &x1, &y1, &x2, &y2 );
            if ( x1 == x2 )
                mp[ x1 ][ y1 ] = mp[ x2 ][ y2 ] = 1;
            else
                mp[ x1 ][ y1 ] = mp[ x2 ][ y2 ] = 2;
        }
        //        for(int i=1;i<=n;i++)
        //            for(int j=1;j<=m;j++)
        //            printf("%d%c",mp[i][j],j==m?'\n':' ');
        bool flag = false;
        node st;
        for ( int i = 1; i <= n; i++ ) {
            for ( int j = 1; j <= m; j++ ) {
                if ( mp[ i ][ j ] == 0 ) {
                    flag   = true;
                    st.x   = i;
                    st.y   = j;
                    st.dir = -4;
                    break;
                }
            }
            if ( flag )
                break;
        }
        int ans = -1;
        q.push( st );
        while ( !q.empty() ) {
            node tmp = q.front();
            q.pop();
            ans++;
            vis[ tmp.x ][ tmp.y ] = true;
            for ( int i = 0; i < 4; i++ ) {
                int nx = tmp.x + walkx[ i ];
                int ny = tmp.y + walky[ i ];
                if ( nx <= n && nx > 0 && ny <= m && ny > 0 && ( tmp.dir + 2 ) % 4 != i ) {
                    if ( ny == tmp.y && mp[ nx ][ ny ] == 2 ) {
                        if ( tmp.x + 2 * walkx[ i ] > 0 && tmp.x + 2 * walkx[ i ] <= n && !vis[ tmp.x + 2 * walkx[ i ] ][ tmp.y ] )
                            q.push( node( tmp.x + 2 * walkx[ i ], tmp.y, i ) );
                    }
                    if ( nx == tmp.x && mp[ nx ][ ny ] == 1 ) {
                        if ( tmp.y + 2 * walky[ i ] > 0 && tmp.y + 2 * walky[ i ] <= m && !vis[ tmp.x ][ tmp.y + 2 * walky[ i ] ] )
                            q.push( node( tmp.x, tmp.y + 2 * walky[ i ], i ) );
                    }
                }
            }
        }
        //        printf("=====================\n");
        //        for(int i=1;i<=n;i++)
        //            for(int j=1;j<=m;j++)
        //            printf("%d%c",vis[i][j],j==m?'\n':' ');
        printf( "%d\n", ans );
    }
}
