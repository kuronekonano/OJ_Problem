#include <stdio.h>
int main() {
    long long t, k, a, b;
    scanf( "%lld", &t );
    while ( t-- ) {
        scanf( "%lld %lld/%lld", &k, &a, &b );
        if ( a < b )
            printf( "%lld %lld/%lld\n", k, b, b - a );
        else {
            if ( b == 1 )
                printf( "%lld %lld/%lld\n", k, b, a + 1 );
            else {
                long long fa = a - b, fb = b, num = 0;
                while ( fa > fb )
                    fa = fa - fb, fb = b, num++;
                a = fb, b = fb - fa;
                while ( num-- )
                    b += a;
                printf( "%lld %lld/%lld\n", k, a, b + a );
            }
        }
    }
}
