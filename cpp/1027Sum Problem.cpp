#include <stdio.h>
int main() {
    long long n, t;
    while ( scanf( "%lld", &n ) != EOF ) {
        t = n * ( n + 1 ) / 2 % 2011;
        printf( "%lld\n", t );
    }
}
