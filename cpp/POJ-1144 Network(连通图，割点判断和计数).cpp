#include <algorithm>
#include <stdio.h>  ///连通图，判断割点，割点计数
#include <string.h>
using namespace std;  ///!!!!邻接矩阵不能判断重边，不能用于割边的求解
bool maps[ 105 ][ 108 ], vis[ 106 ];
int  dfn[ 108 ], low[ 109 ], cnt = 0, n, ans;
void tarjan( int u, int f )  /// 同时记录父亲节点，父亲节点不走
{
    vis[ u ] = true;              /// 标记走过
    low[ u ] = dfn[ u ] = ++cnt;  /// 记录初始访问时间
    int flag = 0, k = 0;          /// flag作为割点标记
    for ( int i = 1; i <= n; i++ ) {
        if ( maps[ u ][ i ] == false || i == f )
            continue;             /// 如果两个点直接没有接通，或该点是其父节点，跳过这个点
        if ( vis[ i ] == false )  /// 若可以连通的第i个点未被访问
        {
            ++k;             /// u正在访问的点，可连接节点计数(子女个数)
            tarjan( i, u );  /// dfs访问
            low[ u ] = min( low[ u ], low[ i ] );
            if ( ( u == 1 && k == 2 ) || ( u != 1 && low[ i ] >= dfn[ u ] ) )  /// 判断是否是割点:如果不是根节点，那么这个节点的子孙将无法会回到u点，则这个节点就是割点
            {  /// 正在遍历的这个子孙节点的low值大于或等于u节点时，说明发生的情况是子孙节点就是子孙，无法回溯回来了(甚至不会回到u的祖先)，不可能构成环的，那他就是这个子孙的割点咯，割掉这个节点，因为回不来，所以分开了
                flag = 1;
            }  /// 根节点已经能连通两个子女时，他就已经是一个割点了，所以当k再增大时，也没有影响了
        }  /// 如果根节点开始访问的几个点能成环，那么最终肯定要返回根节点，于是就回到根节点的那条(反边)不算根节点的子女，所以只有当向外深搜回不来时，那些点才算是子孙
        else  /// 可连接但已经被访问过的点，说明有其他通路可以连接这个点
        {
            low[ u ] = min( low[ u ], dfn[ i ] );  /// 更新low数组的访问时间
        }
    }
    ans += flag;
}

int main() {
    int i, j, u, v;
    while ( scanf( "%d", &n ) && n ) {
        memset( vis, false, sizeof( vis ) );
        memset( maps, false, sizeof( maps ) );
        memset( low, 0, sizeof( low ) );
        memset( dfn, 0, sizeof( dfn ) );
        ans = cnt = 0;
        while ( scanf( "%d", &u ) && u ) {
            while ( getchar() != '\n' ) {
                scanf( "%d", &v );
                maps[ u ][ v ] = maps[ v ][ u ] = true;  /// 邻接矩阵用于形成图结构
            }
        }
        tarjan( 1, i );
        //        for(i=1;i<=n;i++)
        //        {
        //            printf("%d%c",dfn[i],i==n?'\n':' ');
        //        }
        //        for(i=1;i<=n;i++)
        //        {
        //            printf("%d%c",low[i],i==n?'\n':' ');
        //        }
        printf( "%d\n", ans );
    }
}
/*low[u]记录从u或其子孙出发能到达的所有点的最
小出生时间，这里的子孙是指这颗深搜子树上，u的
子孙。low[u]最大值low[u]=dfn[u],回退时更新low[u]*/
/// 当出现环时，反边，回溯的边不算 子孙
/// low数组是一边访问一边更新的，在回溯的过程中更新，在遇到反边时更新
/*    6
    /   \
   5-1-2-3-4
      \   /
        7     */
/// 上图是无割点的一种情况，当非根节点的子孙无法回溯到他的祖先时，那他就是割点，这个图是可以回溯到祖先的，所以不存在割点
