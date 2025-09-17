#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, dis;
    while ( scanf( "%d%d", &a, &b ) != EOF ) {
        dis = b - a + 1;
        if ( ( dis & 1 ) && b < 0 )
            printf( "Negative\n" );
        else if ( ( dis & 1 ) == 0 && b < 0 )
            printf( "Positive\n" );
        else if ( a <= 0 && b >= 0 )
            printf( "Zero\n" );
        else
            printf( "Positive\n" );
    }
}
