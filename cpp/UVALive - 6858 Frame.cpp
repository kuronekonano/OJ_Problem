#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
    int x, y, n, a;
    while ( scanf( "%d%d", &x, &y ) != EOF ) {
        scanf( "%d", &n );
        while ( n-- ) {
            bool ans = false;
            scanf( "%d", &a );
            if ( y % a == 0 && ( x - 2 ) % a == 0 )
                ans = true;  /// 长边能整除，完整分配，短边也能整除
            if ( y % a == 1 && ( ( x - 1 ) % a == 0 || ( x - 2 ) % a == 0 && x % a == 0 ) )
                ans = true;  /// 长边多出1，分配给短边整除，或短边-2和短边同时被整除
            if ( y % a == 2 && ( x % a == 0 ) )
                ans = true;  /// 长边-2整除，短边完整分配
            swap( x, y );
            if ( y % a == 0 && ( x - 2 ) % a == 0 )
                ans = true;
            if ( y % a == 1 && ( ( x - 1 ) % a == 0 || ( x - 2 ) % a == 0 && x % a == 0 ) )
                ans = true;
            if ( y % a == 2 && ( x % a == 0 ) )
                ans = true;
            printf( "%s\n", ans ? "YES" : "NO" );
        }
    }
}
