#include <stdio.h>
#include <string.h>
#define LL long long
using namespace std;
const int mod = 20182018;
struct matrix {
    LL mat[ 2 ][ 2 ];
};
LL     n, m;
matrix mul( matrix a, matrix b ) {
    matrix ans;
    for ( int i = 0; i < 2; i++ ) {
        for ( int j = 0; j < 2; j++ ) {
            ans.mat[ i ][ j ] = 0;
            for ( int k = 0; k < 2; k++ ) {
                LL tmp            = a.mat[ i ][ k ] * b.mat[ k ][ j ] % mod;
                ans.mat[ i ][ j ] = ( ans.mat[ i ][ j ] + tmp ) % mod;
            }
        }
    }
    return ans;
}
matrix poww( matrix a, LL b ) {
    matrix ans = a;
    b--;
    while ( b ) {
        if ( b & 1 )
            ans = mul( ans, a );
        a = mul( a, a );
        b >>= 1;
    }
    return ans;
}
int t;
int main() {
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%lld", &n );
        matrix ma;
        ma.mat[ 1 ][ 0 ] = 0;
        ma.mat[ 0 ][ 0 ] = 1;
        ma.mat[ 0 ][ 1 ] = 1;
        ma.mat[ 1 ][ 1 ] = 3;
        matrix ans       = poww( ma, n );
        matrix tmp;
        tmp.mat[ 0 ][ 1 ] = 0;
        tmp.mat[ 0 ][ 0 ] = 0;
        tmp.mat[ 1 ][ 1 ] = 0;
        tmp.mat[ 1 ][ 0 ] = 1;
        ans               = mul( ans, tmp );
        printf( "%lld\n", ans.mat[ 0 ][ 0 ] % mod );
    }
}
/*
三叉树的总结点数本来是(3^n)/2
但是因为本体n过大，并且有除法操作，因此不能快速幂取模或者欧拉降幂
因此只能递推，递推不需要除2，递推的快速方法即矩阵快速幂，因此直接构造矩阵递推即可
*/
#include <bits/stdc++.h>
#define LL long long
#define M( a, b ) memset( a, b, sizeof a )
#define pb( x ) push_back( x )
using namespace std;
const int maxn = 1e5 + 7;
LL        n, m, q;

int main() {
    scanf( "%lld", &q );
    while ( q-- ) {
        scanf( "%lld%lld", &n, &m );
        LL tmp = 1 + ( n - 1 ) * n / 2;
        LL ans = tmp + m - 1;
        printf( "%lld\n", n & 1 ? ans : tmp + ( n - m ) );
    }
}
/*
1
3 2
4 5 6
10 9 8 7
11 12 13 14 15

*/
