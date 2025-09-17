#include <queue>
#include <stdio.h>  ///深搜，其实用到了队列我感觉是是广搜
#include <string.h>
using namespace std;
struct location  /// 行走坐标和步数打包结构体
{
    int x, y, step;
} now, nexts;
char maps[ 109 ][ 109 ];            /// 输入n*n阵字符串，相当于地图
bool vis[ 109 ][ 109 ];             /// 标记数组，检查是否走过某个坐标
int  walkx[ 4 ] = { 0, 1, 0, -1 };  /// 行走数组，四个方向迈进
int  walky[ 4 ] = { 1, 0, -1, 0 };
int  i, j, n, q, hx, hy;
int  dfs( int x, int y )  /// 搜索函数
{
    memset( vis, false, sizeof( vis ) );  /// 清空标记数组
    queue< location > s;                  /// 建立结构体location型队列
    now.x         = x;
    now.y         = y;  /// now结构体存放当时使用的坐标和步数
    now.step      = 0;
    vis[ x ][ y ] = true;  /// 小辉所在坐标要标记，不能返回这里
    s.push( now );         /// 讲初始坐标塞入队列
    while ( !s.empty() )   /// 当队列不为空
    {
        now = s.front();                      /// 取出队首
        s.pop();                              /// 把取出的弹出去
        if ( maps[ now.x ][ now.y ] == 'G' )  /// 先检查取出来的这个坐标是否有女孩子
        {
            return now.step;  /// 有的话可以返回步数了，这里题目要求的是最小步数，因为每次执行行走循环，都是只行走一步的，所以，最小步数就是最快找到女孩子的路线，会最先退出搜索循环
        }  /// 同时因为题目所求是最小步数，即使有相同的最小步数也不会影响
        for ( int i = 0; i < 4; i++ )  /// 四步走
        {
            nexts.x    = now.x + walkx[ i ];  /// next结构体存放下一个将要到达的坐标
            nexts.y    = now.y + walky[ i ];
            nexts.step = now.step + 1;                                                                                                                    /// 步数记得加1
            if ( nexts.x < n && nexts.x >= 0 && nexts.y < n && nexts.y >= 0 && maps[ nexts.x ][ nexts.y ] != '#' && vis[ nexts.x ][ nexts.y ] == false )  /// 检查的条件有:
            {                                      /// 坐标不能超出地图，坐标到达的是为走过的路线，坐标不能走建筑物
                vis[ nexts.x ][ nexts.y ] = true;  /// 如果符合条件则标记这个可以走的坐标，代表走过
                s.push( nexts );                   /// 并塞入队列中，表示从这里继续探索往四个方向走下去
            }
        }
    }
    return -1;  /// 如果到了这一步，说明上面所有步骤都走完了，队列空了，每个地方都走过了也没有找到女孩子，只能cry了，返回-1
}
int main() {

    while ( scanf( "%d%d", &n, &q ) != EOF )  /// 输入n*n矩阵，以及q个女孩子
    {
        for ( i = 0; i < n; i++ )  /// 输入部分
        {
            scanf( "%s", maps[ i ] );
            for ( j = 0; j < n; j++ ) {
                if ( maps[ i ][ j ] == '*' )  /// 输入时即可查找*小辉坐标，找到并记录下坐标
                {
                    hx = i;
                    hy = j;
                }
            }
        }
        int gx, gy;    /// 女孩子的坐标
        while ( q-- )  /// 有q个女孩子就标记q次，输入q次
        {
            scanf( "%d%d", &gx, &gy );
            maps[ gx ][ gy ] = 'G';  /// 讲坐标带入map中，直接标记为一个字符，比较好查找
        }
        int flag = dfs( hx, hy );  /// 进入搜索，初始值，开始寻找的坐标就是小辉的坐标
        if ( flag != -1 )          /// 检查返回值
        {
            printf( "%d\n", flag );
        }
        else {
            printf( "cry\n" );
        }
    }
    return 0;
}
