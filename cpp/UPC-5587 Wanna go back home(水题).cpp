#include <bits/stdc++.h>
using namespace std;
int main() {
    char a[ 1005 ];
    while ( scanf( "%s", a ) != EOF ) {
        int w = 0, e = 0, s = 0, n = 0;
        for ( int i = 0; i < strlen( a ); i++ ) {
            if ( a[ i ] == 'E' )
                e++;
            if ( a[ i ] == 'W' )
                w++;
            if ( a[ i ] == 'S' )
                s++;
            if ( a[ i ] == 'N' )
                n++;
        }
        if ( w == 0 && e == 0 || s == 0 && n == 0 )
            if ( w != 0 && e != 0 && s == 0 && n == 0 )
                printf( "Yes\n" );
            else if ( w == 0 && e == 0 && s != 0 && n != 0 )
                printf( "Yes\n" );
            else
                printf( "No\n" );
        else if ( w != 0 && e != 0 && s != 0 && n != 0 )
            printf( "Yes\n" );
        else
            printf( "No\n" );
    }
}
