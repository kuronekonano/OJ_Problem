#include <stdio.h>  ///大数取模
#include <string.h>
char a[ 109 ];
int  num[ 109 ], pri[ 1000008 ];
bool vis[ 1000008 ];
int  tp = 0;
int  poww( int a, int b )  /// 快速幂(因为用math的pow会有奇怪的精度损失)
{
    int tmp = a, ans = 1;
    while ( b != 0 ) {
        if ( b & 1 )
            ans *= tmp;
        tmp *= tmp;
        b /= 2;
    }
    return ans;
}
void inti()  /// 素数表
{
    memset( vis, true, sizeof( vis ) );
    for ( int i = 2; i <= 1000003; i++ ) {
        if ( vis[ i ] ) {
            pri[ tp++ ] = i;
            for ( int j = i + i; j <= 1000003; j += i ) {
                vis[ j ] = false;
            }
        }
    }
}
int main() {
    inti();
    int low;
    while ( scanf( "%s %d", a, &low ) != EOF ) {
        memset( num, 0, sizeof( num ) );
        if ( a[ 0 ] == '0' && strlen( a ) == 1 && low == 0 )
            break;
        int n = strlen( a ), sum = 0, flag = 0, ww = 0;
        for ( int i = n - 1; i >= 0; i-- )  /// 大数以千进制拆分
        {
            sum += ( a[ i ] - '0' ) * poww( 10, flag );  /// 从个位开始每3位为一个数
            flag++;
            if ( flag == 3 ) {
                num[ ww++ ] = sum;
                flag        = 0;
                sum         = 0;
            }
        }
        if ( sum != 0 )
            num[ ww++ ] = sum;
        bool ans = false;
        for ( int i = 0; i < tp; i++ ) {
            if ( pri[ i ] >= low )
                break;  /// 若当前遍历素数大于low值说明在low值以内找不到一个素数使其整除，那么最小整除素数不在low值之下
            flag = 0;
            for ( int j = ww - 1; j >= 0; j-- )  /// 由同余模来模拟竖式求模(大数取模)
            {
                flag = ( flag * 1000 + num[ j ] ) % pri[ i ];
            }
            if ( flag == 0 )  /// 当找到一个素数可以整除，说明这个素数小于最低限度low值，上方已经判断，直接标记BAD并记录素数
            {
                n   = pri[ i ];
                ans = true;
                break;
            }
        }
        if ( ans )
            printf( "BAD %d\n", n );
        else
            printf( "GOOD\n" );
    }
}
