#include <bits/stdc++.h>
#define LL long long
#define M( a, b ) memset( a, b, sizeof a )
using namespace std;
LL n, dp[ 15 ][ 110 ][ 110 ][ 110 ],
    a[ 15 ];  /// 一维记录数位长度，二维记录数位加和，三维记录实际数同余模，四维记录具体模数
LL dfs( int pos, int sum, int numod, bool limit, int calnum ) {
    if ( pos == -1 )
        return sum == calnum && !numod;  /// 符合条件的的数判断，当数位加和等于模数，且实际数对其取模后等于0说明是beautiful
                                         /// number
    if ( !limit && dp[ pos ][ sum ][ numod ][ calnum ] != -1 )
        return dp[ pos ][ sum ][ numod ][ calnum ];
    LL  ans   = 0;
    int maxup = limit ? a[ pos ] : 9;  /// 判断该遍历的位是否是上限，若是上限只能达到给出N的该位，否则可以遍历0~9
    for ( int i = 0; i <= maxup; i++ ) {
        if ( sum + i > calnum )
            break;  /// 加和超过遍历的取模数
        ans += dfs( pos - 1, sum + i, ( numod * 10 + i ) % calnum, limit && i == a[ pos ], calnum );
    }
    if ( !limit )
        dp[ pos ][ sum ][ numod ][ calnum ] = ans;  /// 如果不是上限值，此时计算的ans是有用的，能够被之后的计算直接整块调用的，记录到dp数组中
    return ans;
}
int main() {
    int t, cas = 0;
    M( dp, -1 );
    scanf( "%d", &t );
    while ( t-- ) {
        int cnt = 0;
        scanf( "%lld", &n );
        while ( n )  /// 拆分各位
        {
            a[ cnt++ ] = n % 10;
            n /= 10;
        }
        LL ans = 0;
        for ( int i = 1; i <= 108; i++ )
            ans += dfs( cnt - 1, 0, 0, true,
                        i );  /// 遍历每一种数位和，用作同余模的模数，当累加实际数取模为0时是符合条件的
        printf( "Case %d: %lld\n", ++cas, ans );
    }
}
