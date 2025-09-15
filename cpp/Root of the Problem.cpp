#include <algorithm>
#include <cstring>
#include <math.h>
#include <stdio.h>
using namespace std;  // 循环从1开始遍历，
int main() {
    int a, i, b, n;
    while ( scanf( "%d%d", &b, &n ) != EOF ) {
        if ( b == 0 && n == 0 ) {
            return 0;
        }
        for ( i = 1; i <= b; i++ ) {
            if ( b - pow( i, n ) == 0 )  // 求差，若等于0则i的n次方为b,i为所求A值
            {
                printf( "%d\n", i );
                break;
            }
            else if ( pow( i, n ) < b && pow( i + 1, n ) > b ) {
                if ( fabs( pow( i, n ) - b ) > fabs( pow( i + 1, n ) - b ) ) {
                    printf( "%d\n", i + 1 );
                    break;
                }
                else {
                    printf( "%d\n", i );
                    break;
                }
            }
        }
    }
    return 0;
}
