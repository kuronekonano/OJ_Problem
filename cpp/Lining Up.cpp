#include <stdio.h>
struct point  // 定义结构体存储坐标
{
    int x, y;
} poi[ 708 ];  // 有七百组数据
int main() {
    int t, i, n, j, flag;
    while ( scanf( "%d", &n ) != EOF ) {
        if ( n == 0 )
            break;  // 输入0结束输入
        for ( i = 0; i < n; i++ ) {
            scanf( "%d%d", &poi[ i ].x, &poi[ i ].y );
        }
        int big = 0;
        for ( i = 0; i < n; i++ ) {
            for ( int j = i + 1; j < n; j++ ) {
                flag = 0;
                for ( int k = j + 1; k < n; k++ ) {
                    if ( ( poi[ k ].x - poi[ j ].x ) * ( poi[ j ].y - poi[ i ].y )
                         == ( poi[ j ].x - poi[ i ].x ) * ( poi[ k ].y - poi[ j ].y ) )  // 求斜率若三点斜率相同，符合条件，在一条直线，前两点确定斜率，第三点判断是否在一条直线
                        flag++;
                }
                big = big > flag ? big : flag;  // 可能是任意几个点都能成一条直线，现在是找最多点的直线
            }
        }
        printf( "%d\n", big + 2 );  // 开始作为定点的两个点，定二动一
    }
    return 0;
}
