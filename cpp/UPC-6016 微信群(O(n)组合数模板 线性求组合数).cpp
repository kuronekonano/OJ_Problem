#include <algorithm>
#include <stdio.h>
#define LL long long
using namespace std;
const LL MOD = 1e9 + 7;
LL       poww( LL x, LL n )  /// 快速幂
{
    LL res = 1;
    while ( n ) {
        if ( n & 1 )
            res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}
/// 组合数模板
LL   p[ 100005 ], f[ 100005 ];  /// p为阶乘数组，f为阶乘的逆元
void init()                     /// 预处理
{
    p[ 0 ] = 1;
    for ( int i = 1; i <= 100000; ++i )  /// 计算阶乘
        p[ i ] = p[ i - 1 ] * i % MOD;

    f[ 0 ] = 1;
    for ( int i = 1; i <= 100000; ++i )  /// 计算逆元
        f[ i ] = poww( p[ i ], MOD - 2 );
    return;
}
LL comb( int n, int m )  /// 计算组合数
{
    return ( f[ m ] * f[ n - m ] ) % MOD * p[ n ] % MOD;
}  /// 分子---->  n!
   /// 分母---->  m!*(n-m)!   计算逆元后相乘得到C(n,m)的组合数
int main() {
    LL k, n;
    while ( scanf( "%lld%lld", &n, &k ) != EOF ) {
        LL ans = 1;
        LL sum = poww( 2, n );  ///  组合数总和！！！C(n,0)+C(n,1)+......+C(n,n)=2^n
        LL tmp = n;
        for ( int i = 2; i <= k; i++ ) {
            ans = ( ans + tmp ) % MOD;
            //            printf("===%lld=====%lld\n",tmp,ans);
            tmp = ( ( tmp * ( n - i + 1 ) ) % MOD * poww( i, MOD - 2 ) ) % MOD;  /// 线性计算组合数，分子*n-i+1,分母*i
        }
        ans = ( sum - ans + MOD ) % MOD;  /// 减法运算取模，加上MOD再对MOD取模
        printf( "%lld\n", ans );
    }  /// 因为题目中计算K到N(1e9)
       /// 的组合数计算会超时，因此利用n的组合数总和2^n减去从0到k-1的组合数之和(较短段)，得到后半段k到n组合数之和(较长段)
}
// LL comb(LL n, LL m)///另一种组合数求法，在数塔中斜向求组合数
//{
//     if(m > n) return 0;
//     LL ret = 1;
//     m = min(n - m, m);
//     for(int i = 1; i <= m; i ++)
//     {
//         LL a = (n + i - m) % MOD;
//         LL b = i % MOD;
//         ret = ret * (a * mod_pow(b, MOD - 2) % MOD) % MOD;
//     }
//     sum=(sum%MOD+ret%MOD)%MOD;
// }
//
// LL Lucas(LL n, LL m)
//{
//     if(m == 0) return 1;
//     return comb(n % MOD, m % MOD) * Lucas(n / MOD, m / MOD) % MOD;
// }
