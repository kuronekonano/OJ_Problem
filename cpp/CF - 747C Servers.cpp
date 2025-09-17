#include <stdio.h>
#include <string.h>
struct task {
    int t, k, d, sum;
} a[ 100008 ];
int main() {
    int  n, q, i, j;
    int  vis[ 108 ];
    bool check[ 108 ];
    while ( scanf( "%d%d", &n, &q ) != EOF ) {
        memset( vis, 0, sizeof( vis ) );
        memset( check, false, sizeof( check ) );
        for ( i = 0; i < q; i++ ) {
            scanf( "%d%d%d", &a[ i ].t, &a[ i ].k, &a[ i ].d );
        }
        for ( i = 0; i < q; i++ ) {
            int sum = 0, flag = 0;
            for ( j = 1; j <= n; j++ ) {
                if ( a[ i ].t > vis[ j ] ) {
                    vis[ j ] = 0;
                }
                if ( !vis[ j ] ) {
                    vis[ j ] += a[ i ].t + a[ i ].d - 1;
                    sum += j;
                    flag++;
                    check[ j ] = true;
                }
                if ( flag == a[ i ].k )
                    break;
            }
            //            for(int k=1; k<=n; k++)
            //            {
            //                printf("%d%c",vis[k],k==n?'\n':'=');
            //            }

            if ( sum == 0 || flag < a[ i ].k ) {
                printf( "-1\n" );
                for ( j = 1; j <= n; j++ ) {
                    if ( check[ j ] ) {
                        vis[ j ] = 0;
                    }
                }
                memset( check, false, sizeof( check ) );
            }
            else {
                printf( "%d\n", sum );
                memset( check, false, sizeof( check ) );
            }
        }
    }
}
