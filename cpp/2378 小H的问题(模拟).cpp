#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#define LL long long
using namespace std;
const LL MOD = 1000000007;
char     a[ 150 ];
bool     judge( int pos ) {
    if ( ( a[ pos ] >= '0' && a[ pos ] <= '9' ) || ( a[ pos ] >= 'A' && a[ pos ] <= 'Z' ) || ( a[ pos ] >= 'a' && a[ pos ] <= 'z' ) || a[ pos ] == '-' || a[ pos ] == '_' )
        return true;
    return false;
}
int main() {
    int                 t, n;
    vector< string >    ans;
    map< string, bool > vis;
    scanf( "%d", &t );
    while ( t-- ) {
        ans.clear();
        vis.clear();
        scanf( "%d", &n );
        getchar();
        while ( n-- ) {
            gets( a );
            //            printf("%d......%s\n",n,a);
            int len = strlen( a );
            for ( int i = 0; i < len; i++ ) {
                if ( a[ i ] == '@' && judge( i + 1 ) ) {
                    if ( i == 0 ) {
                        i++;
                        string tmp;
                        tmp.clear();
                        while ( judge( i ) )
                            tmp += a[ i++ ];
                        //                        cout<<tmp<<endl;
                        if ( !vis[ tmp ] ) {
                            vis[ tmp ] = true;
                            ans.push_back( tmp );
                        }
                    }
                    else if ( !judge( i - 1 ) ) {
                        i++;
                        string tmp;
                        tmp.clear();
                        while ( judge( i ) )
                            tmp += a[ i++ ];
                        if ( !vis[ tmp ] ) {
                            vis[ tmp ] = true;
                            ans.push_back( tmp );
                        }
                    }
                }
            }
        }
        sort( ans.begin(), ans.end() );
        printf( "%d\n", ans.size() );
        for ( int i = 0; i < ans.size(); i++ )
            cout << ans[ i ] << endl;
    }
}
