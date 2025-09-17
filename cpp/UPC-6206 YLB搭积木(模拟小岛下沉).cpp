#include <stdio.h>
#define LL long long
int  n, a[ 100005 ];
bool check() {
    for ( int i = 1; i <= n; i++ )
        if ( a[ i ] )
            return false;
    return true;
}
int main() {
    while ( scanf( "%d", &n ) != EOF ) {
        for ( int i = 1; i <= n; i++ )
            scanf( "%d", &a[ i ] );
        LL ans = 0;
        while ( !check() )  /// 外层循环判断所有大楼高度是否都为0
        {
            int i = 1;        /// 初始化起始遍历位置
            while ( i <= n )  /// 对整个宽度n进行遍历
            {
                if ( a[ i ] )  /// 若在遍历过程中遇到有高度存在
                {
                    int minn = 0x7fffffff;  /// 开始记录该模块最小值和起点
                    int st   = i;           /// 记录起点
                    while ( a[ i ] > 0 ) {
                        if ( a[ i ] < minn )
                            minn = a[ i ];
                        i++;
                    }
                    for ( int j = st; j < i; j++ )
                        if ( a[ j ] )
                            a[ j ] -= minn;  /// 用记录到的最小值降低整个模块的高度
                    ans += minn;             /// 操作步骤数量加高度
                }
                i++;  /// 跳过没有高度的坐标
            }
        }
        printf( "%lld\n", ans );
    }
}
