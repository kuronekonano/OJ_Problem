#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int     maxn = 5e4 + 9;
int           n, m, q;
int           val[ maxn ];
vector< int > mp[ maxn ];
// int head[maxn],cnt;
// struct edge
//{
//     int to,next;
// }mp[maxn];
// void add(int from,int to)
//{
//     mp[++cnt].next=head[from];
//     mp[cnt].to=to;
//     head[from]=cnt;
// }
int  fa[ maxn ];
int  deep[ maxn ];
int  top[ maxn ];
int  son[ maxn ];
int  fp[ maxn ];
int  sum[ maxn ];
int  num[ maxn ];
int  pos;
void dfs1( int rt, int pre, int dep ) {
    deep[ rt ] = dep;
    fa[ rt ]   = pre;
    sum[ rt ]  = 1;
    for ( int i = 0; i < mp[ rt ].size(); i++ ) {
        int v = mp[ rt ][ i ];
        if ( v != pre ) {
            dfs1( v, rt, dep + 1 );
            sum[ rt ] += sum[ v ];  /// 子树节点和
            if ( son[ rt ] == 0 || sum[ v ] > sum[ son[ rt ] ] )
                son[ rt ] = v;  /// 重儿子
        }
    }
}
void dfs2( int rt, int boss ) {
    top[ rt ]       = boss;   /// 每条链的顶端节点
    num[ rt ]       = ++pos;  /// 链上连序
    fp[ num[ rt ] ] = rt;
    if ( son[ rt ] == 0 )
        return;
    dfs2( son[ rt ], boss );
    for ( int i = 0; i < mp[ rt ].size(); i++ ) {
        int v = mp[ rt ][ i ];
        if ( v != son[ rt ] && v != fa[ rt ] )
            dfs2( v, v );  /// 新开一条链
    }
}
struct node {
    int l, r, val, lazy;
} tre[ maxn << 2 ];
void pushdown( int rt ) {
    if ( tre[ rt ].lazy ) {
        tre[ rt << 1 ].lazy += tre[ rt ].lazy;
        tre[ rt << 1 | 1 ].lazy += tre[ rt ].lazy;
        tre[ rt << 1 ].val += ( tre[ rt << 1 ].r - tre[ rt << 1 ].l + 1 ) * tre[ rt ].lazy;
        tre[ rt << 1 | 1 ].val += ( tre[ rt << 1 | 1 ].r - tre[ rt << 1 | 1 ].l + 1 ) * tre[ rt ].lazy;
        tre[ rt ].lazy = 0;
    }
    return;
}
void build( int l, int r, int rt ) {
    tre[ rt ].l    = l;
    tre[ rt ].r    = r;
    tre[ rt ].lazy = 0;
    if ( l == r ) {
        tre[ rt ].val = val[ fp[ l ] ];
        return;
    }
    int mid = ( l + r ) >> 1;
    build( l, mid, rt << 1 );
    build( mid + 1, r, rt << 1 | 1 );
    tre[ rt ].val = tre[ rt << 1 ].val + tre[ rt << 1 | 1 ].val;
}
void update( int l, int r, int val, int rt ) {
    if ( tre[ rt ].l >= l && tre[ rt ].r <= r ) {
        tre[ rt ].val += ( tre[ rt ].r - tre[ rt ].l + 1 ) * val;
        tre[ rt ].lazy += val;
        return;
    }
    pushdown( rt );
    int mid = ( tre[ rt ].l + tre[ rt ].r ) >> 1;
    if ( l <= mid )
        update( l, r, val, rt << 1 );
    if ( r > mid )
        update( l, r, val, rt << 1 | 1 );
    tre[ rt ].val = tre[ rt << 1 ].val + tre[ rt << 1 | 1 ].val;
    return;
}
int query( int pos, int rt ) {
    if ( tre[ rt ].l == pos && tre[ rt ].r == pos )
        return tre[ rt ].val;
    pushdown( rt );
    int mid = ( tre[ rt ].l + tre[ rt ].r ) >> 1;
    if ( pos > mid )
        return query( pos, rt << 1 | 1 );
    else if ( pos <= mid )
        return query( pos, rt << 1 );
}

void change( int l, int r, int val )  /// 向上回溯对每条链更新
{
    int f1 = top[ l ], f2 = top[ r ];
    while ( f1 != f2 ) {
        if ( deep[ f1 ] < deep[ f2 ] )  /// 两条链的top深度对比
        {
            swap( f1, f2 );
            swap( l, r );
        }
        update( num[ f1 ], num[ l ], val, 1 );  /// 更新整条链
        l  = fa[ f1 ];                          /// top的fa
        f1 = top[ l ];                          /// 上方链的top
    }
    if ( deep[ l ] > deep[ r ] )
        swap( l, r );  /// 在同一条链上的两个节点
    update( num[ l ], num[ r ], val, 1 );
}
int main() {
    while ( scanf( "%d%d%d", &n, &m, &q ) != EOF ) {
        int from, to;
        pos = 0;
        for ( int i = 0; i <= n; i++ )
            mp[ i ].clear();
        //        memset(head,0,sizeof head);
        memset( son, 0, sizeof son );
        for ( int i = 1; i <= n; i++ )
            scanf( "%d", &val[ i ] );
        for ( int i = 1; i <= m; i++ ) {
            scanf( "%d%d", &from, &to );
            mp[ from ].push_back( to );
            mp[ to ].push_back( from );
            //            add(from,to);
            //            add(to,from);///双向边
        }
        dfs1( 1, 0, 0 );  /// 根节点1开始搜，父节点为0，深度为0
        dfs2( 1, 1 );     /// 根节点开始搜，第一个top节点为根节点
        build( 1, n, 1 );
        //        for(int i=1;i<=n;i++) update(num[i],num[i],val[i],1);
        char op[ 3 ];
        int  l, r, k;
        while ( q-- ) {
            scanf( "%s", op );
            if ( op[ 0 ] == 'Q' ) {
                scanf( "%d", &k );
                printf( "%d\n", query( num[ k ], 1 ) );
            }
            else {
                scanf( "%d%d%d", &l, &r, &k );
                if ( op[ 0 ] == 'D' )
                    k = -k;
                change( l, r, k );
            }
        }
    }
}
/*
14 13 99
1 2 3 4 5 6 7 8 9 10 11 12 13 14
1 2
1 3
1 4
2 5
2 6
6 11
6 12
3 7
4 8
4 9
4 10
9 13
13 14
Q 2
I 5 8 1
*/
