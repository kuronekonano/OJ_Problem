#include <stdio.h>
int main() {
    int n, m, t;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d%d", &n, &m );
        printf( "%s\n", !( n & 1 ) && !( m & 1 ) ? "DS" : "xiaodao" );
    }
}
