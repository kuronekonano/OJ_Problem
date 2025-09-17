#include <stdio.h>
int main() {
    long long a, b;
    while ( scanf( "%lld%lld", &a, &b ) != EOF ) {
        if ( a % 2 == 1 && b % 2 == 1 ) {
            printf( "%lld\n", a * b / 2 + 1 );
        }
        else {
            printf( "%lld\n", a * b / 2 );
        }
    }
    return 0;
}
