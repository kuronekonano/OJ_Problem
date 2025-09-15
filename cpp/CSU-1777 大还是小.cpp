#include <stdio.h>
#include <string.h>
int main() {
    char a[ 150 ], b[ 150 ];
    int  cas = 1;
    while ( scanf( "%s %s", a, b ) != EOF ) {
        int lena = strlen( a );
        int lenb = strlen( b );
        if ( strchr( a, '.' ) != NULL ) {
            while ( a[ --lena ] == '0' )
                ;
            if ( a[ lena ] == '.' ) {
                lena--;
            }
            a[ ++lena ] = '\0';
        }
        if ( strchr( b, '.' ) != NULL ) {
            while ( b[ --lenb ] == '0' )
                ;
            if ( b[ lenb ] == '.' ) {
                lenb--;
            }
            b[ ++lenb ] = '\0';
        }
        if ( strcmp( a, b ) == 0 ) {
            printf( "Case %d: Same\n", cas++ );
        }
        else if ( strcmp( a, b ) > 0 ) {
            printf( "Case %d: Bigger\n", cas++ );
        }
        else {
            printf( "Case %d: Smaller\n", cas++ );
        }
    }
}
