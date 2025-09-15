#include <algorithm>
#include <map>
#include <stdio.h>  ///在2e5长的字符串中找到包含JIO三字母相同数量的最长串
#include <string.h>
#define LL long long
using namespace std;
char a[ 200005 ];
int  main() {
    int            n;
    map< LL, int > mp;
    while ( scanf( "%d", &n ) != EOF ) {
        LL jj = 0, ii = 0, oo = 0;  /// 记录每个字母出现次数
        scanf( "%s",
                a + 1 );  /// 注意因为要对字符串位序作差计算距离，因此字符串从1开始输入，到要计算字符串的第i位时，用i减去0，就不会因为位序少1而少计算距离
        int ans = 0;
        mp.clear();
        mp[ 0 ] = 0;
        for ( int i = 1; i <= n; i++ )  /// 对于第i位的出现次数，我们用J-O的数量与J-I的数量应与第j位相等的关系
        {
            jj     = a[ i ] == 'J' ? jj + 1 : jj;
            ii     = a[ i ] == 'I' ? ii + 1 : ii;
            oo     = a[ i ] == 'O' ? oo + 1 : oo;
            LL tmp = 100000 * ( jj - ii ) + ( jj - oo );  /// 哈希记录该差值
            if ( mp.find( tmp ) != mp.end() )
                ans = max( ans,
                            i - mp[ tmp ] );  /// 如果出现过该哈希值(差值)，用当前位-相同差值位，比较出最长距离作为ans
            else
                mp[ tmp ] = i;  /// 若没有出现过该差值，记录此时出现该差值的位序，
        }
        printf( "%d\n", ans );
    }
}
