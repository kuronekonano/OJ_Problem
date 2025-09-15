#include <stdio.h>
#include <string.h>
int main() {
    int  n, i;
    char home[ 5 ], a[ 10 ], b[ 5 ];
    while ( scanf( "%d", &n ) != EOF ) {
        scanf( "%s", home );
        int go = 0, to = 0, k;
        for ( i = 0; i < n; i++ ) {
            scanf( "%s", a );
            for ( k = 0; k < 3; k++ )
                b[ k ] = a[ k ];
            b[ k ] = '\0';
            if ( strcmp( b, home ) == 0 )
                to++;
            int num = 0;
            for ( k = 5; k < 8; k++ )
                b[ num++ ] = a[ k ];
            b[ num ] = '\0';
            if ( strcmp( b, home ) == 0 )
                go++;
        }
        printf( "%s\n", to == go ? "home" : "contest" );
    }
}
