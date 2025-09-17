#include <stdio.h>
const long long Maxn = 1000000007;  /// 模大数，懒得打的时候就这样定义了
int             main() {
    long long t, a, n;
    scanf( "%lld", &t );  /// 注意这里输入的数就很大了
    while ( t-- )         /// 快速幂模板
    {
        scanf( "%lld%lld", &a, &n );
        long long ans = 1;  /// 用于存储结果
        while ( n != 0 )    /// 只要幂次不为0就继续乘
        {
            if ( n % 2 != 0 )  /// 遇到奇数幂次
            {
                ans = ( ( ans % Maxn ) * ( a % Maxn ) ) % Maxn;  /// 拿其中一个a单独出来乘
            }
            a = ( ( a % Maxn ) * ( a % Maxn ) ) % Maxn;  /// 然后剩下的幂次就是偶数的了,把偶数幂次乘到一起，这样就形成一个数量较少，值较大的大型乘数
            n /= 2;                                      /// 每次合并幂次，幂次是原来的一半
        }
        printf( "%lld\n", ans );
    }
}
