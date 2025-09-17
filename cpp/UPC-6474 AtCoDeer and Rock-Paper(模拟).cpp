#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
char      str[ maxn ];
int       main() {
    while ( scanf( "%s", str ) != EOF ) {
        int gg = 0, pp = 0, ans = 0;
        int len = strlen( str );
        for ( int i = 0; i < len; i++ ) {
            if ( str[ i ] == 'g' ) {
                if ( pp < gg )
                    ans++, pp++;
                else
                    gg++;
            }
            else {
                if ( pp < gg )
                    pp++;
                else
                    gg++, ans--;
            }
        }
        printf( "%d\n", ans );
    }
}
