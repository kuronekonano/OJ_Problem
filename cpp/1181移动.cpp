#include <queue>
#include <stdio.h>
#include <string.h>  //深搜
#include <string.h>
using namespace std;
int x1, y1, x2, y2, i;
int vis[ 305 ][ 309 ];                             // 标记数组，最大范围不会超过300×300
int walkx[ 10 ] = { 2, 1, 1, 2, -1, -2, -1, -2 };  // 行走方式的数组，每次步数对应x值移动和y值移动的距离
int walky[ 10 ] = { -1, -2, 2, 1, 2, 1, -2, -1 };
int walk;
struct point  // 为方便每个点为一个坐标，定为一个结构体打包
{
    int x, y;
} a, b;
queue< point > q;  // point型结构体队列，队列中塞进去的是一个个point型结构体
int            main() {
    point s, t;                                                   // 定义初始坐标和终点坐标
    while ( scanf( "%d%d%d%d", &s.x, &s.y, &t.x, &t.y ) != EOF )  // 起始坐标和终点坐标
    {
        while ( !q.empty() )  // 清空队列
        {
            q.pop();
        }
        memset( vis, 0, sizeof( vis ) );  // 清空标记数组
        vis[ s.x ][ s.y ] = 1;            // 定初始位置被标记过
        q.push( s );                      // 初始位置入列

        while ( !q.empty() ) {
            a = q.front();  // 从队首起始
            q.pop();
            for ( i = 0; i < 8; i++ ) {
                b.x = a.x + walkx[ i ];  // 从当前点开始移动x值和y值
                b.y = a.y + walky[ i ];
                if ( b.x >= 0 && b.x <= 300 && b.y >= 0 && b.y <= 300 && !vis[ b.x ][ b.y ] )  // 若当前坐标未超出限制范围
                {
                    vis[ b.x ][ b.y ] = vis[ a.x ][ a.y ] + 1;  // 标记走过的位置，并赋予当前步数
                    q.push( b );                                // 并入列下一个点
                }
            }
            if ( vis[ t.x ][ t.y ] )  // 若最终点被标记则退出循环
            {
                break;
            }
        }
        printf( "%d\n",
                           vis[ t.x ][ t.y ] - 1 );  // 输出最终点的位置-1的步数，因为初始点不算步数，却被标记了1
    }
    return 0;
}
