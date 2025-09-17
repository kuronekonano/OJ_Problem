#include <algorithm>  ///使乘法越小越好，因此全部分配1位*1位，但是有可能，乘数会达到2位，即使除了最后的除数还是会很大，甚至比加数还大
#include <stdio.h>    ///使前面尽可能多的位数做加数，于是就形成了n位数+1位数的加法分配
#include <string.h>   ///因为后面的乘和除是被减去的，因此要尽可能小，那么作为除法，要尽量除大的数才会小。
using namespace std;  /// 那么，尽量使减去的数为0，因此两数相乘结果必须小于除数，因为两数相乘最大是81，因此除数可能是一个2位数甚至3位数才能消去这个乘法结果
int main()            /// 只有3种情况，一种分给乘除3位，乘除各一位。
{                     /// 当乘法过大时，从加法位集体向后挪一位给除法位，再计算取最大值，这种情况分给乘除4位，乘法各一位，除法2位
    int t, i,
        cas = 0;  /// 最后一种，当两位乘法乘积仍大于后两位除法时，继续从加数中集体后挪一位给除法，最后除3位肯定是小于1的，分给乘除5位，乘法各一位，除法分3位
    scanf( "%d",
           &t );  /// 如果是第一种情况，5位数必出结果，如果是第二种情况，6位数二选一取最大出结果，超过6位，在第一第二种中最大值再与第三种情况取max，得到结果
    while ( t-- ) {
        cas++;
        char str[ 25 ];
        int  a[ 25 ];
        scanf( "%s", str );
        int l = strlen( str );
        for ( i = 0; i < l; i++ )
            a[ i ] = str[ i ] - '0';
        long long numa = 0, numb = 0;
        for ( i = 0; i < l - 4; i++ )
            numa = numa * 10 + a[ i ];
        numa += a[ l - 4 ];
        for ( i = 1; i < l - 3; i++ )
            numb = numb * 10 + a[ i ];
        numb += a[ 0 ];
        long long sum = max( numa, numb );
        if ( l == 5 ) {
            printf( "Case #%d: %lld\n", cas, sum - ( a[ l - 3 ] * a[ l - 2 ] / a[ l - 1 ] ) );
            continue;
        }
        numa = 0, numb = 0;
        for ( i = 0; i < l - 5; i++ )
            numa = numa * 10 + a[ i ];
        numa += a[ l - 5 ];
        for ( i = 1; i < l - 4; i++ )
            numb = numb * 10 + a[ i ];
        numb += a[ 0 ];
        long long sum2 = max( numa, numb );
        sum            = max( sum - ( a[ l - 3 ] * a[ l - 2 ] / a[ l - 1 ] ), sum2 - ( a[ l - 4 ] * a[ l - 3 ] ) / ( a[ l - 2 ] * 10 + a[ l - 1 ] ) );
        if ( l == 6 ) {
            printf( "Case #%d: %lld\n", cas, sum );
            continue;
        }
        numa = 0, numb = 0;
        for ( i = 0; i < l - 6; i++ )
            numa = numa * 10 + a[ i ];
        numa += a[ l - 6 ];
        for ( i = 1; i < l - 5; i++ )
            numb = numb * 10 + a[ i ];
        numb += a[ 0 ];
        sum2 = max( numa, numb );
        sum  = max( sum, sum2 - ( a[ l - 5 ] * a[ l - 4 ] ) / ( a[ l - 3 ] * 100 + a[ l - 2 ] * 10 + a[ l - 1 ] ) );
        printf( "Case #%d: %lld\n", cas, sum );
    }
}
