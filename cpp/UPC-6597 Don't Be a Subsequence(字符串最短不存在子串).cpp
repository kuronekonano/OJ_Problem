#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int inf  = 0x3f3f3f3f;
char      a[ maxn ];
struct str {
    int len[ 26 ], nxt[ 26 ];
} word[ maxn ];
int pos[ 26 ];  /// 离当前位置最近的26个字母的位置
int minlen[ maxn ];
int main() {
    scanf( "%s", a + 1 );
    memset( pos, 0, sizeof pos );
    int len = strlen( a + 1 );
    for ( int i = len; i >= 0; i-- )  /// 倒叙遍历字符串，以查询离每个位置最近的下一个字母
    {
        minlen[ i ] = inf;              /// 当前位置往后可查询的不存在子串的最小长度
        for ( int j = 0; j < 26; j++ )  /// 对于第i位，其下一个26个字母中每个字母的位置是谁
        {
            word[ i ].nxt[ j ] = 0;  /// 如下一个字母a的位置
            if ( pos[ j ] )          /// 若该位置之后存在该字母
            {
                word[ i ].nxt[ j ] = pos[ j ];                /// 给出下一个该字母的位置
                word[ i ].len[ j ] = minlen[ pos[ j ] ] + 1;  /// 给当前位置最短不存在子串的长度赋予上一个位置+1的长度，因为该位置存在字母j，如果查找该位最小字典序那么长度就要相应增加
                if ( i == 0 )
                    word[ i ].len[ j ]--;  /// 如果是第一个位置，长度不用加一
            }
            else
                word[ i ].len[ j ] = i == 0 ? 0 : 1;  /// 如果不存在某个字母，那说明到此结束，不存在子串长度截止
            minlen[ i ] = min( minlen[ i ], word[ i ].len[ j ] );
        }
        if ( i != 0 )
            pos[ a[ i ] - 'a' ] = i;  /// 如果不是第一个字符，更新当前出现字母的最新位置
    }
    for ( int k = 0, mini, minn;; k = word[ k ].nxt[ mini ], printf( "%c",
                                                                     mini + 'a' ) )  /// 输出部分，每次利用之前处理的当前位置的下一个字母和最短长度输出相应字符
    {                                                                                /// 指针后移
        mini = 0, minn = inf;
        for ( int i = 0; i < 26; i++ )  /// 每次查找下一个输出的字符，保证整体输出长度最小
        {
            if ( !word[ k ].nxt[ i ] )  /// 若之后不存在某个字母了，那就输出结束了
            {
                printf( "%c\n", i + 'a' );
                return 0;
            }
            if ( word[ k ].len[ i ] < minn )
                minn = word[ k ].len[ i ], mini = i;  /// 记录最小输出长度的字母
        }
    }
    return 0;
}
