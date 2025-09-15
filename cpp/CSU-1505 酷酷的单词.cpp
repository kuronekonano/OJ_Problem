#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
    int  n, i, cas = 1;
    char a[ 38 ];
    int  flag[ 30 ];
    while ( scanf( "%d", &n ) != EOF ) {
        int sum = 0;
        while ( n-- ) {
            scanf( "%s", a );
            bool ans = false;
            if ( strlen( a ) == 1 )
                continue;
            memset( flag, 0, sizeof( flag ) );
            for ( i = 0; i < strlen( a ); i++ ) {
                flag[ a[ i ] - 'a' ]++;
            }
            sort( flag, flag + 26 );
            for ( i = 0; i < 26; i++ ) {
                if ( flag[ i ] != 0 && flag[ i ] == flag[ i + 1 ] ) {
                    ans = true;
                    break;
                }
            }
            if ( !ans )
                sum++;
        }
        printf( "Case %d: %d\n", cas++, sum );
    }
}
