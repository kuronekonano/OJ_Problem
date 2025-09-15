#include <algorithm>  ///插入函数的头文件
#include <stdio.h>
using namespace std;
int main() {
    int n, a[ 105 ], i;
    while ( scanf( "%d", &n ) != EOF ) {
        for ( i = 0; i < n; i++ ) {
            scanf( "%d", &a[ i ] );
        }
        sort( a, a + n );  /// upper和lower只能在有序数列中使用
        int t;
        scanf( "%d",
               &t );   /// 注意插入函数的使用方法，第一个是数组名（首地址），然后是在数组中的某个范围插入a+n,最后是要插入的数
        while ( t-- )  /// 警告！！！原函数返回的是一个地址，必须减掉数组首地址a，才是一个表示位置的值！！！
        {
            int flag;
            scanf( "%d", &flag );                            /// 输入的这个数是任意数，不是数列中的数
            int inside = upper_bound( a, a + n, flag ) - a;  /// 将这个数插入到排序好的序列中
            if ( inside >= n )                               /// 如果插入的位置是数组的最后一位，那么说明没有比他更大的了
            {
                printf( "Orz\n" );
            }
            else {
                printf( "%d\n",
                        a[ inside ] );  /// 这里直接输出数组插入的那个位置就好，因为那个位置就是比他大的最小的数
            }
        }
    }
    return 0;
}
