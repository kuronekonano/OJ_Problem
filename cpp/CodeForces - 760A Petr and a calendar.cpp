#include <stdio.h>
int main() {
    int m, d, i, j, month[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    while ( scanf( "%d%d", &m, &d ) != EOF ) {
        int flag = 1, week = d;
        for ( i = 1; i <= month[ m ]; i++ ) {
            if ( week >= 8 ) {
                week %= 7;
                flag++;
            }
            week++;
        }
        printf( "%d\n", flag );
    }
}
