#include <bits/stdc++.h>
using namespace std;
bool num[ 11 ][ 7 ] = { { true, true, true, false, true, true, true },  { false, false, true, false, false, true, false }, { true, false, true, true, true, false, true },
                        { true, false, true, true, false, true, true }, { false, true, true, true, false, true, false },   { true, true, false, true, false, true, true },
                        { true, true, false, true, true, true, true },  { true, false, true, false, false, true, false },  { true, true, true, true, true, true, true },
                        { true, true, true, true, false, true, true } };
char a[ 10 ][ 200 ];
int  ans[ 18 ];
int  judge( int x, int y ) {
    if ( a[ x + 2 ][ y + 2 ] == 'x' )
        return -1;
    if ( a[ x + 1 ][ y ] == 'x' ) {
        if ( a[ x + 1 ][ y + 4 ] == 'x' ) {
            if ( a[ x ][ y + 1 ] == 'x' ) {
                if ( a[ x + 3 ][ y + 1 ] == 'x' ) {
                    if ( a[ x + 4 ][ y ] == 'x' )
                        return 8;
                    else
                        return 9;
                }
                else
                    return 0;
            }
            else
                return 4;
        }
        else {
            if ( a[ x + 4 ][ y ] == 'x' )
                return 6;
            else
                return 5;
        }
    }
    else {
        if ( a[ x + 3 ][ y + 1 ] == 'x' ) {
            if ( a[ x + 4 ][ y ] == 'x' )
                return 2;
            else
                return 3;
        }
        else {
            if ( a[ x ][ y + 1 ] == 'x' )
                return 7;
            else
                return 1;
        }
    }
}
int main() {
    while ( scanf( "%s", a[ 0 ] ) != EOF ) {
        for ( int i = 1; i < 7; i++ ) {
            scanf( "%s", a[ i ] );
        }
        long long b[ 3 ];
        b[ 0 ] = b[ 1 ] = 0;
        int len         = strlen( a[ 0 ] );
        int flag        = 0;
        for ( int i = 0; i < len; i += 6 ) {
            int num = judge( 0, i );
            if ( num == -1 ) {
                flag++;
                continue;
            }
            b[ flag ] = b[ flag ] * 10 + num;
        }
        long long sum = b[ 0 ] + b[ 1 ];
        flag          = 0;
        while ( sum > 0 ) {
            ans[ flag++ ] = sum % 10;
            sum /= 10;
        }
        for ( int j = flag - 1; j >= 0; j-- ) {
            printf( "%c", num[ ans[ j ] ][ 0 ] || num[ ans[ j ] ][ 1 ] ? 'x' : '.' );
            for ( int k = 2; k <= 4; k++ ) {
                printf( "%c", num[ ans[ j ] ][ 0 ] ? 'x' : '.' );
            }
            printf( "%c", num[ ans[ j ] ][ 0 ] || num[ ans[ j ] ][ 2 ] ? 'x' : '.' );
            printf( "%c", j == 0 ? '\n' : '.' );
        }
        for ( int i = 1; i <= 2; i++ ) {
            for ( int j = flag - 1; j >= 0; j-- ) {
                printf( "%c", num[ ans[ j ] ][ 1 ] ? 'x' : '.' );
                for ( int k = 1; k <= 3; k++ )
                    printf( "." );
                printf( "%c", num[ ans[ j ] ][ 2 ] ? 'x' : '.' );
                printf( "%c", j == 0 ? '\n' : '.' );
            }
        }
        for ( int j = flag - 1; j >= 0; j-- ) {
            printf( "%c", num[ ans[ j ] ][ 1 ] || num[ ans[ j ] ][ 3 ] || num[ ans[ j ] ][ 4 ] ? 'x' : '.' );
            for ( int k = 2; k <= 4; k++ ) {
                printf( "%c", num[ ans[ j ] ][ 3 ] ? 'x' : '.' );
            }
            printf( "%c", num[ ans[ j ] ][ 2 ] || num[ ans[ j ] ][ 3 ] || num[ ans[ j ] ][ 5 ] ? 'x' : '.' );
            printf( "%c", j == 0 ? '\n' : '.' );
        }
        for ( int i = 1; i <= 2; i++ ) {
            for ( int j = flag - 1; j >= 0; j-- ) {
                printf( "%c", num[ ans[ j ] ][ 4 ] ? 'x' : '.' );
                for ( int k = 1; k <= 3; k++ )
                    printf( "." );
                printf( "%c", num[ ans[ j ] ][ 5 ] ? 'x' : '.' );
                printf( "%c", j == 0 ? '\n' : '.' );
            }
        }
        for ( int j = flag - 1; j >= 0; j-- ) {
            printf( "%c", num[ ans[ j ] ][ 6 ] || num[ ans[ j ] ][ 4 ] ? 'x' : '.' );
            for ( int k = 2; k <= 4; k++ ) {
                printf( "%c", num[ ans[ j ] ][ 6 ] ? 'x' : '.' );
            }
            printf( "%c", num[ ans[ j ] ][ 6 ] || num[ ans[ j ] ][ 5 ] ? 'x' : '.' );
            printf( "%c", j == 0 ? '\n' : '.' );
        }
    }
}
/*
....x.xxxxx.xxxxx.x...x.xxxxx.xxxxx.xxxxx.......xxxxx.xxxxx.xxxxx
....x.....x.....x.x...x.x.....x.........x...x...x...x.x...x.x...x
....x.....x.....x.x...x.x.....x.........x...x...x...x.x...x.x...x
....x.xxxxx.xxxxx.xxxxx.xxxxx.xxxxx.....x.xxxxx.xxxxx.xxxxx.x...x
....x.x.........x.....x.....x.x...x.....x...x...x...x.....x.x...x
....x.x.........x.....x.....x.x...x.....x...x...x...x.....x.x...x
....x.xxxxx.xxxxx.....x.xxxxx.xxxxx.....x.......xxxxx.xxxxx.xxxxx
*/
