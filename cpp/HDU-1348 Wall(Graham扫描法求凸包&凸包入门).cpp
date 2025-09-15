#include <bits/stdc++.h>
#define LL long long
#define M( a, b ) memset( a, b, sizeof a )
#define pb( x ) push_back( x )
using namespace std;
const int    maxn = 1e3 + 7;
const double PI   = acos( -1.0 );
struct node  /// 坐标
{
    double x, y;
} p[ maxn ], P[ maxn ];
int    n, tot;
double ans, r;
double X( node A, node B, node C )  /// 叉积
{
    return ( B.x - A.x ) * ( C.y - A.y ) - ( C.x - A.x ) * ( B.y - A.y );
}
double dis( node A, node B )  /// 两点距离
{
    return sqrt( ( A.x - B.x ) * ( A.x - B.x ) + ( A.y - B.y ) * ( A.y - B.y ) );
}
bool cmp( node A, node B )  /// 极角排序
{
    double pp = X( p[ 0 ], A, B );
    if ( pp > 0 )
        return true;
    if ( pp < 0 )
        return false;
    return dis( p[ 0 ], A ) < dis( p[ 0 ], B );  /// 极角相同，与0点距离近的排前面
}
int main() {
    int  t;
    bool flag = false;
    scanf( "%d", &t );
    while ( t-- ) {
        if ( !flag )
            flag = true;
        else
            printf( "\n" );
        scanf( "%d%lf", &n, &r );
        ans = 2 * PI * r;  /// 圆周长
        for ( int i = 0; i < n; i++ )
            scanf( "%lf%lf", &p[ i ].x, &p[ i ].y );  /// 输入n个坐标
        if ( n == 1 )
            printf( "%.0f\n", ans );  /// 凸包上只有一个点，直接输出圆周长
        else if ( n == 2 )
            printf( "%.0f\n", ans + dis( p[ 0 ], p[ 1 ] ) );  /// 凸包上有两个点，两点距离加圆周长
        else {
            for ( int i = 0; i < n; i++ )  /// 遍历n个节点找到0号节点
            {
                if ( p[ 0 ].y < p[ 0 ].y )
                    swap( p[ i ], p[ 0 ] );  /// 找到比当前0号节点y坐标小的，交换
                else if ( p[ 0 ].y == p[ 0 ].y && p[ i ].x < p[ 0 ].x )
                    swap( p[ i ], p[ 0 ] );  /// 找到与当前0号节点y坐标相同但x坐标更小的,交换
            }
            sort( p + 1, p + n, cmp );     /// 根据p[0]排序，因此不把p[0]放到排序数组中
            P[ 0 ] = p[ 0 ];               /// P代表凸包上的点
            P[ 1 ] = p[ 1 ];               /// 凸包上第一个点，即P[0]的相邻点
            tot    = 1;                    /// 凸包上有两个点，p[0]不算，已经选好的p[1]算一个点
            for ( int i = 2; i < n; i++ )  /// 继续选后面的点
            {                              /// 叉积判断已选点和新点组成向量的位置关系，若向量在右边，那么选新点
                while ( tot > 0 && X( P[ tot - 1 ], P[ tot ], p[ i ] ) <= 0 )
                    tot--;  /// while模拟栈筛选凸包上的节点
                tot++;
                P[ tot ] = p[ i ];
            }  /// 凸包求完
            for ( int i = 0; i < tot; i++ )
                ans += dis( P[ i ], P[ i + 1 ] );  /// 周长求和
            ans += dis( P[ 0 ], P[ tot ] );        /// 求最后一个节点和0号节点的封闭距离
            printf( "%.0f\n", ans );
        }
    }
}
