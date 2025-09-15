#include <bits/stdc++.h>
const int maxn = 1e5 + 10;
using namespace std;
struct node {
    int cnt, num;
} b[ maxn ];
int  tre[ maxn ], a[ maxn ], sasum[ maxn ];
void updata( int pos, int val ) {
    for ( int i = pos; i < maxn; i += i & -i )
        tre[ i ] += val;
}
int query( int pos ) {
    int ans = 0;
    for ( int i = pos; i > 0; i -= i & -i )
        ans += tre[ i ];
    return ans;
}
int t, n, m;
int main() {
    scanf( "%d", &t );
    while ( t-- ) {
        memset( tre, 0, sizeof tre );
        scanf( "%d%d", &n, &m );
        for ( int i = 0; i < n; i++ )
            scanf( "%d", &a[ i ] );
        sort( a, a + n );
        int sum = 1, mix = 1;
        b[ sum ].num = a[ 0 ];
        b[ sum ].cnt = 1;
        for ( int i = 1; i < n; i++ ) {
            if ( a[ i ] == a[ i - 1 ] )
                b[ sum ].cnt++;
            else {
                if ( b[ sum ].cnt > mix )
                    mix = b[ sum ].cnt;
                updata( b[ sum ].cnt + 1, -1 );
                sum++;
                b[ sum ].cnt = 1;
                b[ sum ].num = a[ i ];
            }
        }
        updata( b[ sum ].cnt + 1, -1 );
        if ( b[ sum ].cnt > mix )
            mix = b[ sum ].cnt;
        bool flag = false;
        updata( 1, sum );
        sasum[ mix ] = query( mix );
        for ( int i = mix - 1; i; i-- )
            sasum[ i ] = query( i ) + sasum[ i + 1 ];
        for ( int i = sum; i; i-- ) {
            if ( sasum[ b[ i ].cnt ] - 1 <= m ) {
                printf( "%d\n", b[ i ].num );
                flag = true;
                break;
            }
        }
        if ( !flag )
            printf( "-1\n" );
    }
    return 0;
}
