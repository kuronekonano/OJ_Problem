#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
using namespace std;
int main() {
    int    n, i, k, j, tmp;
    double maxn, sum;
    string name, ans;
    while ( scanf( "%d", &n ) != EOF ) {
        maxn = 0;
        for ( i = 0; i < n; i++ ) {
            scanf( "%d", &k );
            cin >> name;
            sum = 0;
            for ( j = 1; j <= k; j++ ) {
                scanf( "%d", &tmp );
                sum += log10( tmp );
            }
            if ( maxn < sum ) {
                maxn = sum;
                ans  = name;
            }
        }
        cout << ans << endl;
    }
}
