#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
    int a[ 13 ], t, i;
    scanf( "%d", &t );
    while ( t-- ) {
        int money;
        scanf( "%d", &money );
        for ( i = 0; i < 12; i++ ) {
            scanf( "%d", &a[ i ] );
        }
        if ( money == 0 ) {
            printf( "0\n" );
            continue;
        }
        sort( a, a + 12 );
        int sum = 0, flag = 0;
        for ( i = 11; i >= 0; i-- ) {
            sum = sum + a[ i ];
            flag++;
            if ( sum >= money ) {
                break;
            }
        }
        if ( sum < money ) {
            printf( "-1\n" );
            continue;
        }
        printf( "%d\n", flag );
    }
    return 0;
}
