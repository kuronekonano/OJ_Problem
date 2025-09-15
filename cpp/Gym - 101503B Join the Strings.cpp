#include <algorithm>
#include <iostream>
#include <stdio.h>  ///字符串数组相加字典序最小排序
#include <string>
using namespace std;
bool cmp( string a, string b ) {
    return a + b < b + a;
}
int main() {
    string a[ 108 ];
    int    n;
    while ( scanf( "%d", &n ) != EOF ) {
        for ( int i = 0; i < n; i++ )
            cin >> a[ i ];
        sort( a, a + n, cmp );
        for ( int i = 0; i < n; i++ )
            cout << a[ i ];
        cout << endl;
    }
}
