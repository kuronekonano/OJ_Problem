#include <algorithm>
#include <queue>
#include <stdio.h>  ///以建立虚拟起点和终点存放点权，求边权最短路
#include <string.h>
#include <vector>
using namespace std;
struct edge {
    int to, val;
    edge( int a = 0, int b = 0 ) : to( a ), val( b ) {}
    bool operator<( const edge& a ) const {
        return val > a.val;
    }
};
vector< edge > v[ 100008 ];
int            dist[ 100008 ];
void           dijkstra()  /// 最短路
{
    memset( dist, 0x3f, sizeof( dist ) );
    priority_queue< edge > q;
    q.push( edge( 0, 0 ) );
    dist[ 0 ] = 0;
    while ( !q.empty() ) {
        edge top = q.top();
        q.pop();
        for ( int i = 0; i < v[ top.to ].size(); i++ ) {
            edge tmp = v[ top.to ][ i ];
            if ( dist[ tmp.to ] > tmp.val + top.val ) {
                dist[ tmp.to ] = tmp.val + top.val;
                q.push( edge( tmp.to, dist[ tmp.to ] ) );
            }
        }
    }
}
int main() {
    int t, n, city;
    scanf( "%d", &t );
    while ( t-- ) {
        scanf( "%d", &n );
        for ( int i = 0; i <= n + 1; i++ )
            v[ i ].clear();  /// 一定要清表！！！！！否则会超时，形成一个多次测试数据拼成的超大图
        for ( int i = 1; i <= n; i++ ) {
            scanf( "%d", &city );  /// 输入城市点权
            v[ 0 ].push_back( edge( i,
                                    city ) );  /// 虚拟起电脑设为0号点，将所有点的取值连接到起始节点，让起始节点选择应该从哪个城市买书(出发)
            v[ i ].push_back( edge( n + 1,
                                    -city ) );  /// 虚拟终点设为n+1号点，终点投入所有点能到达的点中，使最短路中可以在每个点都能选择到达终点！
        }
        int from, too, vv;
        for ( int i = 1; i <= n - 1; i++ ) {
            scanf( "%d%d%d", &from, &too, &vv );
            v[ from ].push_back( edge( too, vv ) );
            v[ too ].push_back( edge( from, vv ) );
        }
        dijkstra();
        printf( "%d\n", -dist[ n + 1 ] );
    }
    return 0;
}
/// 建立虚拟的起点和终点，相当于，所有买书和路费之和最小时赚的钱最多
/// 因此，反过来设，扣的钱为正数，挣的钱为负数，最短路在正数部分使其最少，并且在最后加上一个最小的负值，使正数最小减去很大的值，结果是一个最小的负数，这个负数的相反数即最大挣钱数
/// 注意，只有起始点(买书点)和终点(卖书点)需要计算点权，其他情况全部计算边权，因此，将所有点的点权，取正值(作为买书的花费)，变成一个边权连接虚拟起始节点
/// 所有点的点权，取负值(卖书的利润)，变成一个负边权连接虚拟终点，这样从虚拟起点到达虚拟终点的过程即是从所有点中找到合适点权和最小边权最后减去最大点权的最短路问题
/// 这里一开始选到的起始点权会是买书成本最小的那个城市，但是这并不代表就在那个城市买书，利用最短路算法，它仅仅作为选取其他短边松弛最短路的一个经过，那个最小起始点的dist仍会被更新掉，
/// 从而成为真正起始点的经过点。最终，在所有点权中和边权中，取得最小的权值之和到达终点(必须经过一个负边权，必须在某地卖掉书)，实现最小花费最大收益
