#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn       = 1003;
int       ping[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int       run[ 13 ]  = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int       n;
double    t, money;
int       yeardays( int y ) {
    if ( ( y % 4 == 0 && y % 100 != 0 ) || ( y % 400 == 0 ) )
        return 366;
    else
        return 365;
}
int main() {
    int y, m, d, sum;
    scanf( "%d", &n );
    for ( int i = 0; i < n; i++ ) {
        sum = 0;
        scanf( "%d-%d-%d", &y, &m, &d );
        scanf( "%lf%lf", &money, &t );
        //            printf("====%d  %d  %d   %d  %d\n",y,m,d,money,t);
        if ( y == 2018 ) {
            if ( m == 4 )
                sum = 22 - d + 1;
            else {
                for ( int i = m + 1; i < 4; i++ )
                    sum += ping[ i ];
                sum += ping[ m ] - d + 22 + 1;
            }
        }
        else if ( y == 2017 ) {
            for ( int i = 1; i < m; i++ )
                sum += ping[ i ];
            sum += d;
            sum = 365 - sum + 112 + 1;
        }
        else {
            if ( ( y % 4 == 0 && y % 100 != 0 ) || ( y % 400 == 0 ) ) {
                for ( int i = 1; i < m; i++ )
                    sum += run[ i ];
                sum += d;
                sum = 366 - sum;
                for ( int i = y + 1; i < 2017; i++ )
                    sum += yeardays( i );
                sum += 477 + 1;
            }
            else {
                for ( int i = 1; i < m; i++ )
                    sum += ping[ i ];
                sum += d;
                sum = 365 - sum;
                for ( int i = y + 1; i < 2017; i++ )
                    sum += yeardays( i );
                sum += 477 + 1;
            }
        }
        bool G = false;
        bool H = false;
        if ( money / sum >= 100 )
            H = true;
        if ( t / 60.0 / sum >= 12 )
            G = true;
        if ( G && H )
            printf( "GH\n" );
        else if ( G == false && H )
            printf( "H\n" );
        else if ( G && H == false )
            printf( "G\n" );
        else
            printf( "O\n" );
    }
}
