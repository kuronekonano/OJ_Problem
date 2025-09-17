#include <queue>
#include <stdio.h>  ///广搜路径记录
#include <string.h>
using namespace std;
bool vis[ 600 ];   /// 标记数组
int  path[ 600 ];  /// 路径记录数组，每个新坐标的数组下标记录着上一次停留的坐标
int  main() {
    int          start, stop, i;
    queue< int > q;
    while ( scanf( "%d%d", &start, &stop ) != EOF ) {
        memset( vis, false, sizeof( vis ) );
        memset( path, -1, sizeof( path ) );
        while ( !q.empty() ) {
            q.pop();
        }
        q.push( start );
        vis[ start ] = true;
        while ( !q.empty() )  /// 第一部分，广搜找到最短路径，并记录路径
        {
            int walk = q.front();
            q.pop();
            if ( walk == stop ) {
                break;
            }
            for ( i = 1; i <= 3; i++ )  /// 分顺序的三步，必须，1向后，2向前，3跳跃
            {
                int will;
                if ( i == 1 ) {
                    will = walk - 1;
                }
                if ( i == 2 ) {
                    will = walk + 1;
                }
                if ( i == 3 )  /// 先判断怎么走
                {
                    will = walk * 2;
                }
                if ( will >= 0 && will <= 500 && !vis[ will ] )  /// 再判断这样走符不符合条件
                {
                    vis[ will ]  = true;
                    path[ will ] = walk;  /// 符合条件就记录下一个坐标到路径数组中,这里相当于链表的存储方式，数组标号表示坐标，数组中存储的数字表示到达标号之前的位置
                    q.push( will );
                }
            }
        }
        int backto = stop;              /// 第二部分，从目的地，利用路径记录数组，回溯到起点，并根据路径数组中存储的坐标点之间的关系【这里先初始化回溯指针backto为结束位置】
        int flag   = 0;                 /// 判断每一步的动作是向前，向后，还是跳跃
        int road[ 600 ];                /// 第三个数组，记录每一步的路径动作，分别用123表示三种动作
        while ( path[ backto ] != -1 )  /// 循环条件是找的每一步都存储有上一步的路径，直到找到的起点是没有存储路径的-1
        {
            if ( path[ backto ] == backto + 1 )  /// 当前坐标与存储坐标的关系为+1时，说明当前坐标是存储坐标后退得到的
            {
                road[ flag++ ] = 1;               /// 标记此步骤为1（后退）
                backto         = path[ backto ];  /// 记住要回溯
            }
            else if ( path[ backto ] == backto - 1 )  /// 说明当前坐标是存储坐标向前一步得到的
            {
                road[ flag++ ] = 2;
                backto         = path[ backto ];
            }
            else  /// 不能用三个if，判断条件会重复，剩下的情况只有跳跃了，若用三个if，则通过了上一步的后退，仍会可能符合条跳跃的条件关系
            {
                road[ flag++ ] = 3;
                backto         = path[ backto ];
            }
        }
        for ( i = flag - 1; i >= 0; i-- )  /// 第三部分，根据动作数组存储的路径，倒着输出每个动作，因为动作记录时是从终点到起点的
        {
            if ( road[ i ] == 1 )  /// 根据动作数组存储的动作代号来判断输出动作
            {
                printf( "step back\n" );
            }
            if ( road[ i ] == 2 ) {
                printf( "step forward\n" );
            }
            if ( road[ i ] == 3 ) {
                printf( "jump\n" );
            }
        }
        printf( "\n" );
    }
    return 0;
}
