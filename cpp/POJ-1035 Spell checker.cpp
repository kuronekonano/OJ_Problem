#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
    char dir[ 10008 ][ 17 ];
    int  i, num = 0;
    while ( scanf( "%s", dir[ ++num ] ) != EOF ) {
        if ( dir[ num ][ 0 ] == '#' )
            break;
    }
    char a[ 100 ];
    while ( scanf( "%s", a ) != EOF ) {
        if ( a[ 0 ] == '#' )
            break;
        bool check = true;
        for ( i = 1; i < num; i++ )  /// 这里用map标记内存和时间会比for遍历查找慢一倍大一倍，垃圾STL
        {
            if ( strcmp( a, dir[ i ] ) == 0 ) {
                printf( "%s is correct\n", a );
                check = false;
                break;
            }
        }
        if ( check ) {
            printf( "%s:", a );
        }
        else
            continue;
        for ( i = 1; i < num; i++ ) {
            int an  = strlen( a );
            int len = strlen( dir[ i ] );
            if ( len - an == 1 ) {
                int ia = 0, ie = 0, flag = 0;
                while ( ia < an && ie < len ) {
                    if ( a[ ia ] == dir[ i ][ ie ] ) {
                        ia++;
                        ie++;
                    }
                    else {
                        ie++;
                    }
                    if ( ie - ia > 1 ) {
                        flag = 1;
                        break;
                    }
                }
                if ( !flag ) {
                    printf( " %s", dir[ i ] );
                }
            }
            else if ( an == len ) {
                int ia = 0, ie = 0, flag = 0;
                while ( ia < an && ie < len ) {
                    if ( a[ ia ] != dir[ i ][ ie ] )
                        flag++;
                    if ( flag > 1 ) {
                        break;
                    }
                    ia++;
                    ie++;
                }
                if ( flag == 1 ) {
                    printf( " %s", dir[ i ] );
                }
            }
            else if ( an - len == 1 ) {
                int ia = 0, ie = 0, flag = 0;
                while ( ia < an && ie < len ) {
                    if ( a[ ia ] == dir[ i ][ ie ] ) {
                        ia++;
                        ie++;
                    }
                    else {
                        ia++;
                    }
                    if ( ia - ie > 1 ) {
                        flag = 1;
                        break;
                    }
                }
                if ( !flag ) {
                    printf( " %s", dir[ i ] );
                }
            }
        }
        printf( "\n" );
    }
}
