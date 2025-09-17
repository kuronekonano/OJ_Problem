#include <map>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
struct num {
    char qsk;
    int  sum[ 3 ];
} a[ 100008 ];
map< string, int > m;
int                main() {
    int n;
    while ( scanf( "%d", &n ) != EOF ) {
        int tot = 0;
        m.clear();
        char type[ 2 ], call[ 30 ], flag[ 2 ];
        while ( n-- ) {
            scanf( "%s", type );
            if ( type[ 0 ] == 'A' )  /// 查询
            {
                scanf( "%s", call );
                if ( m[ call ] )  /// 已标记
                {
                    int tmp = m[ call ];
                    int ans = -1, ii;
                    for ( int i = 0; i < 3; i++ )
                        if ( a[ tmp ].sum[ i ] > ans )
                            ans = a[ tmp ].sum[ i ], ii = i;
                    char q;
                    if ( ii == 0 )
                        q = 'q';
                    if ( ii == 1 )
                        q = 's';
                    if ( ii == 2 )
                        q = 'k';
                    printf( "%c=%d\n", q, ans );
                }
                else  /// 未标记
                {
                    printf( "N\n" );
                }
            }
            else {
                scanf( "%s %s", call, flag );
                if ( !m[ call ] )  /// 未标记
                {
                    int tmp;
                    m[ call ] = ++tot;
                    memset( a[ tot ].sum, 0, sizeof( a[ tot ].sum ) );
                    if ( flag[ 0 ] == 'q' )
                        tmp = 0;
                    if ( flag[ 0 ] == 's' )
                        tmp = 1;
                    if ( flag[ 0 ] == 'k' )
                        tmp = 2;
                    a[ tot ].sum[ tmp ] = 1;
                }
                else  /// 已标记
                {
                    int tmp = m[ call ];
                    int q;
                    if ( flag[ 0 ] == 'q' )
                        q = 0;
                    if ( flag[ 0 ] == 's' )
                        q = 1;
                    if ( flag[ 0 ] == 'k' )
                        q = 2;
                    a[ tmp ].sum[ q ]++;
                }
                printf( "Y\n" );
            }
        }
    }
}
