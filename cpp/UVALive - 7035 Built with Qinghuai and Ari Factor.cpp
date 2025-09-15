#include <stdio.h>
int main() {
    int t, cas = 0, n, i, tmp;
    scanf( "%d", &t );
    while ( t-- ) {
        bool flag = false;
        scanf( "%d", &n );
        cas++;
        for ( i = 0; i < n; i++ ) {
            scanf( "%d", &tmp );
            if ( tmp % 3 != 0 )
                flag = true;
        }
        printf( "Case #%d: %s\n", cas, flag ? "No" : "Yes" );
    }
}
