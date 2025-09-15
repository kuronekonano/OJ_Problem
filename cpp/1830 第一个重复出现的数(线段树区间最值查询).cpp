#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct num {
    int i, num, next;
} a[ 500005 ];
struct node {
    int l, r, maxx;
} tree[ 500005 * 4 ];
bool cmp( num a, num b ) {
    if ( a.num == b.num )
        return a.i < b.i;
    return a.num < b.num;
}
bool cmp2( num a, num b ) {
    return a.i < b.i;
}
void build( int l, int r, int root )  /// 建树
{
    tree[ root ].l    = l;
    tree[ root ].r    = r;
    tree[ root ].maxx = -1;
    if ( l == r ) {
        tree[ root ].maxx = a[ l ].next;
    }
    else {
        int mid = ( l + r ) / 2;
        build( l, mid, root * 2 );
        build( mid + 1, r, root * 2 + 1 );
        tree[ root ].maxx = max( tree[ root * 2 ].maxx, tree[ root * 2 + 1 ].maxx );
    }
}
int query( int l, int r, int root ) {
    if ( l <= tree[ root ].l && tree[ root ].r <= r ) {
        return tree[ root ].maxx;
    }
    else {
        int mid = ( tree[ root ].l + tree[ root ].r ) / 2;
        int res = -1;
        if ( l <= mid ) {
            res = max( query( l, r, root * 2 ), res );
        }
        if ( r >= mid + 1 ) {
            res = max( query( l, r, root * 2 + 1 ), res );
        }
        return res;  /// 返回最大值
    }
}
int main() {
    int n;
    while ( scanf( "%d", &n ) != EOF ) {
        for ( int i = 1; i <= n; i++ ) {
            scanf( "%d", &a[ i ].num );
            a[ i ].i = i;
        }
        sort( a + 1, a + n + 1,
              cmp );  /// 按数的大小排序，得到相同数的位序，然后错位赋值前一个相同元素的位序
        for ( int i = n; i >= 2; i-- ) {
            if ( a[ i ].num == a[ i - 1 ].num )
                a[ i ].next = a[ i - 1 ].i;
            else
                a[ i ].next = -1;
        }
        sort( a + 1, a + 1 + n, cmp2 );  /// 将打乱顺序的数列按恢复成原序列(位序排序)
        build( 1, n, 1 );                /// 将按顺序排列好并赋值了相同数下一位序的数组建立到线段树中
        int q, l, r;
        scanf( "%d", &q );
        while ( q-- ) {
            scanf( "%d%d", &l, &r );  /// 线段树最大值查询
            int ans = query( l, r, 1 );
            if ( ans == -1 || ans < l )
                printf( "jiong\n" );
            else
                printf( "%d\n", a[ ans ].num );
        }
        printf( "\n" );
    }
}
