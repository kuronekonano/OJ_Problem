#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char a[ 108 ];
    int  i, q, base;
    while ( scanf( "%s %d", a, &q ) != EOF ) {
        if ( a[ 0 ] == '0' && q == 0 )
            return 0;
        if ( a[ 0 ] == '0' && a[ 1 ] == 'x' )
            base = 16;
        else if ( a[ 0 ] == '0' && a[ 1 ] != 'x' )
            base = 8;
        else
            base = 10;
        long tmp = strtol( a, NULL, base );
        char add[ 5 ];
        int  ans = 0, num = 0;
        while ( q-- ) {
            scanf( "%s %d", add, &ans );
            if ( add[ 0 ] == '-' ) {
                tmp--;
                if ( ans == tmp )
                    num++;
                else
                    tmp = ans;
            }
            else if ( add[ 0 ] == '+' ) {
                tmp++;
                if ( ans == tmp )
                    num++;
                else
                    tmp = ans;
            }
            else if ( add[ 0 ] == 'i' && add[ 1 ] == '+' ) {
                if ( tmp == ans ) {
                    num++;
                    tmp++;
                }
                else {
                    tmp = ans + 1;
                }
            }
            else if ( add[ 0 ] == 'i' && add[ 1 ] == '-' ) {
                if ( tmp == ans ) {
                    num++;
                    tmp--;
                }
                else {
                    tmp = ans - 1;
                }
            }
            else {
                if ( tmp == ans )
                    num++;
                else
                    tmp = ans;
            }
        }
        printf( "%d\n", num );
    }
}
