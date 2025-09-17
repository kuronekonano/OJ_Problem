#include <bits/stdc++.h>  ///深度优先搜索
using namespace std;
bool vis[ 15 ][ 15 ];
char a[ 20 ][ 20 ];
int  t, n, x[ 100 ], y[ 100 ], walkx[ 5 ] = { 0, 1, 0, -1 }, walky[ 5 ] = { 1, 0, -1, 0 };
int  dfs( int x, int y )  /// 遇到o棋往下搜
{
    vis[ x ][ y ] = true;  /// 标记搜到的点
    int sum       = 0;     /// 注意每次深搜时计数器的定义，要放在函数中，否则不应该增加的出路会连续自增
    for ( int j = 0; j < 4; j++ ) {
        //        printf("~~~~~~~~%d    %d      %d\n",x,y,j);
        if ( x + walkx[ j ] >= 0 && x + walkx[ j ] < 9 && y + walky[ j ] >= 0 && y + walky[ j ] < 9 )  /// 注意棋盘范围不要超出
        {
            if ( a[ x + walkx[ j ] ][ y + walky[ j ] ] == '.' && !vis[ x + walkx[ j ] ][ y + walky[ j ] ] )  /// 遇到空格计数出路
            {
                sum++;
                vis[ x + walkx[ j ] ][ y + walky[ j ] ] = true;  /// 为防止重复计数到空格，标记空格
            }
            if ( a[ x + walkx[ j ] ][ y + walky[ j ] ] == 'o' && !vis[ x + walkx[ j ] ][ y + walky[ j ] ] )  /// 遇到o棋往下dfs
            {
                sum += dfs( x + walkx[ j ], y + walky[ j ] );  /// 求和记录一个连通白块的总出路
            }
        }
    }
    //    printf("--------- %d\n",sum);
    return sum;
}
int main() {
    int cas = 0, i, j;
    scanf( "%d", &t );
    while ( t-- ) {
        cas++;
        memset( vis, false, sizeof( vis ) );
        memset( a, 0, sizeof( a ) );
        int num = 0;
        for ( i = 0; i < 9; i++ ) {
            scanf( "%s", a[ i ] );
            for ( j = 0; j < 9; j++ ) {
                if ( a[ i ][ j ] == 'o' ) {
                    num++;
                    x[ num ] = i;
                    y[ num ] = j;
                }
            }
        }
        int  flag = 0;
        bool ans  = false;
        for ( i = 1; i <= num; i++ )  /// 只遍历o棋子的坐标
        {
            vis[ x[ i ] ][ y[ i ] ] = true;
            flag += dfs( x[ i ], y[ i ] );
            //            printf("======%d\n",flag);
            if ( flag < 2 )  /// 判断出路数量，小于等于1则被杀
            {
                ans = true;
                break;
            }
            flag = 0;  /// 单点搜索，每次搜完一个点，清空标记数组
            memset( vis, false, sizeof( vis ) );
        }
        if ( ans ) {
            printf( "Case #%d: Can kill in one move!!!\n", cas );
        }
        else {
            printf( "Case #%d: Can not kill in one move!!!\n", cas );
        }
    }
}
/*
........o
.........
.........
.........
x.ox.....
xxxoxxxxx
xooooooox
xoo.oooox
xxxooooox

ooooooooo
ooooooooo
ooooooooo
ooooooooo
oooo.xxxx
xxxxxxxxx
xxxxxxxxx
xxxxxxxxx
xxxxxxxxx
*/
