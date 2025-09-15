#include <stdio.h>
int main() {
    long long i, j, n, a[ 1008 ];
    while ( scanf( "%lld", &n ) != EOF ) {
        long long ans = -1;
        for ( i = 0; i < n; i++ ) {
            scanf( "%lld", &a[ i ] );
            for ( j = i - 1; j >= 0; j-- ) {
                long long tmp = a[ i ] * a[ j ];
                if ( tmp < 10 ) {
                    ans = tmp > ans ? tmp : ans;
                }
                else {
                    long long temp = tmp, c = temp % 10;
                    bool      flag = false;
                    while ( temp >= 10 ) {
                        temp /= 10;
                        if ( c != temp % 10 + 1 )
                            flag = true;
                        c = temp % 10;
                    }
                    if ( !flag )
                        ans = tmp > ans ? tmp : ans;
                }
            }
        }
        printf( "%lld\n", ans );
    }
}
