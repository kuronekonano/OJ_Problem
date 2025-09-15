#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
double ma[ 208 ][ 208 ];
double dist[ 208 ];
bool   vis[ 208 ];
int    n, cas = 0;
void   dijkstra() {
    for ( int i = 0; i <= 200; i++ )
        dist[ i ] = 1e10;
    memset( vis, false, sizeof( vis ) );  /// 利用最短路，使选择的路径都是较小的
    for ( int i = 1; i < n; i++ )
        dist[ i ] = ma[ 0 ][ i ];
    dist[ 0 ] = 0;
    vis[ 0 ]  = true;
    for ( int i = 1; i < n; i++ ) {
        double minn = 1e10;
        int    mini;
        for ( int j = 0; j < n; j++ )  /// 每次标记(行走的)路段都是找到到达余下点中最短的
        {
            if ( !vis[ j ] && dist[ j ] < minn ) {
                minn = dist[ j ];
                mini = j;
            }
        }
        vis[ mini ] = true;            /// 找到了最短路段后，更新寻找到达剩余点最短距离
        for ( int j = 0; j < n; j++ )  /// 注意，这里dist记录的是到达某个点的最短路径上最长路段的大小，到达每个点后这个最大距离将被记录并继承下去，如果经过了这个点有了一个最大路段
        {
            /// 那么这个最大路段值也将成为下一个点的最大路段值，因为到达下一个点经过了当前这条路
            dist[ j ] = min( dist[ j ],
                               max( dist[ mini ],
                                    ma[ mini ][ j ] ) );  /// 从dist[j]到达自己的最大路中选择比较小的，可以这样想，既然已经到达了dist，那么这段距离就是最小的，其他距离较大的点不会影响从0点到达1点的长度
        }  /// 剩下两个候选值，是上一个点的最大距离，以及从上一个点到达自己的最大距离的更新，如果上一个点到达自己的距离更大，那么这个最大距离不从之前继承，而被更新。且这个最大距离特别大时，不会影响提前到达的j点的最小距离，也就是不会绕远路
        //        for(int i=0;i<n;i++)printf("%d ----->%f\n",i,dist[i]);
        //        printf("======\n");
    }
}
int main()  /// 题目要求，从点0出发，输出到达点1经过的路段中的最大值，从0到1的长度不做要求，但从0到1中所有路段的最大值比未走的路段都小
{
    while ( scanf( "%d", &n ) != EOF ) {
        if ( !n )
            return 0;
        memset( ma, 0, sizeof( ma ) );
        int x[ 208 ], y[ 208 ];
        for ( int i = 0; i < n; i++ )
            scanf( "%d%d", &x[ i ], &y[ i ] );
        for ( int i = n - 1; i >= 0; i-- )
            for ( int j = i - 1; j >= 0; j-- )
                ma[ i ][ j ] = ma[ j ][ i ] = sqrt( ( x[ i ] - x[ j ] ) * ( x[ i ] - x[ j ] ) + ( y[ i ] - y[ j ] ) * ( y[ i ] - y[ j ] ) );
        dijkstra();
        printf( "Scenario #%d\n", ++cas );
        printf( "Frog Distance = %.3f\n\n", dist[ 1 ] );
    }
}
