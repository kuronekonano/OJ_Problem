#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 18 + 3;
char      str[ maxn ];  /// 最后错误笑死人，字符型写成了int型，样例竟然能过
int       num[ maxn ];
int       DFS( int x ) {
    int ans = 0;
    if ( x == -1 )
        if ( num[ 1 ] == 1 )
            return 1;
        else
            return 0;
    int s = 1 << x;
    for ( int i = 0; i < 3; i++ ) {
        int cnt = 0;
        for ( int j = 0; j < s; j++ ) {
            int tmp = j + s;
            if ( i == 0 )
                num[ tmp ] = num[ tmp << 1 ] ^ num[ tmp << 1 | 1 ];
            else if ( i == 1 )
                num[ tmp ] = num[ tmp << 1 ] | num[ tmp << 1 | 1 ];
            else
                num[ tmp ] = num[ tmp << 1 ] & num[ tmp << 1 | 1 ];
            if ( !num[ tmp ] )
                cnt++;
        }
        if ( cnt == s )
            continue;  /// 如果不存在1了，那么这个操作顺序不会得到1，就没有深搜下去的必要了，是一个小剪枝
        else
            ans += DFS( x - 1 );
    }
    return ans;
}
int main() {
    int n;
    scanf( "%d", &n );
    scanf( "%s", str );
    int s = 1 << n;  /// 对2^n个数进行n个操作，有异或 与 或三种运算
    for ( int i = 0; i < s; i++ )
        num[ i + s ] = str[ i ] - '0';  /// 那么一开始把这些字符输入到2^n之外的下标处
    int ans = DFS( n - 1 );             /// 深搜暴力结果，n表示剩余运算次数
    printf( "%d\n", ans );
}
