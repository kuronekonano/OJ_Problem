// #include<bits/stdc++.h>
// using namespace std;
// const int maxn=3e5+10;
// int n;
// struct node
//{
//     int ll,rr;
//     node(){}
//     node(int a,int b)
//     {
//         ll=a;
//         rr=b;
//     }
//     bool operator <(const node &a)const
//     {
//         if(ll==a.ll)return rr>a.rr;
//         return ll<a.ll;
//     }
// } a[maxn];
// int x,r;
// stack<int>s;
// int main()
//{
//     while(scanf("%d",&n)!=EOF)
//     {
//         int ans=0;
//         for(int i=0; i<n; i++) scanf("%d%d",&x,&r),a[i]=node(x-r,x+r);
//         sort(a,a+n);
//         while(!s.empty())s.pop();
//         for(int i=0; i<n-1; i++)
//         {
//             if(a[i+1].ll==a[i].ll)
//             {
//                 s.push(i);
//                 continue;
//             }
//             if(a[i].rr!=a[i+1].ll&&!s.empty()) s.pop();
//             if(!s.empty())
//                 if(a[i+1].rr==a[s.top()].rr)
//                     ans++,s.pop();
//         }
//         printf("%d\n",n+1+ans);
//     }
// }

/*
hack
5
10 10
3 6
8 2
2 1
4 1

4
0 8
-4 4
-2 2
4 4
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int       maxn = 3e5 + 10;
const int       mod  = 1e9 + 7;
map< int, int > ma;
struct node {
    int x, R;
    int l, r;
} a[ maxn ];
int cnt;

bool cmp( node a, node b ) {
    if ( a.R == b.R ) {
        return a.x < b.x;
    }
    return a.R < b.R;
}

struct node1 {
    int l, r, b;
    int mark;
    int mid() {
        return ( l + r ) >> 1;
    }
} tree[ maxn * 8 ];

void push_up( int rt ) {
    tree[ rt ].b = min( tree[ rt << 1 ].b, tree[ rt << 1 | 1 ].b );
}

void push_down( int rt ) {
    if ( tree[ rt ].mark ) {
        tree[ rt << 1 ].mark += tree[ rt ].mark;
        tree[ rt << 1 | 1 ].mark += tree[ rt ].mark;
        tree[ rt << 1 ].b += tree[ rt ].mark;
        tree[ rt << 1 | 1 ].b += tree[ rt ].mark;
        tree[ rt ].mark = 0;
    }
}

void build( int rt, int l, int r ) {
    tree[ rt ].l    = l;
    tree[ rt ].r    = r;
    tree[ rt ].mark = 0;
    if ( l == r ) {
        tree[ rt ].b = 0;
        return;
    }
    ll mid = tree[ rt ].mid();
    build( rt << 1, l, mid );
    build( rt << 1 | 1, mid + 1, r );
    push_up( rt );
}

void updata( int rt, int l, int r, int val ) {
    if ( l <= tree[ rt ].l && r >= tree[ rt ].r ) {
        tree[ rt ].mark += val;
        tree[ rt ].b += val;
        return;
    }
    push_down( rt );
    int mid = tree[ rt ].mid();
    if ( l <= mid )
        updata( rt << 1, l, r, val );
    if ( r > mid )
        updata( rt << 1 | 1, l, r, val );
    push_up( rt );
}

int query( int rt, int l, int r ) {
    int ans = 0x3f3f3f3f;
    if ( l <= tree[ rt ].l && r >= tree[ rt ].r ) {
        return tree[ rt ].b;
    }
    push_down( rt );
    int mid = tree[ rt ].mid();
    if ( l <= mid )
        ans = min( ans, query( rt << 1, l, r ) );
    if ( r > mid )
        ans = min( query( rt << 1 | 1, l, r ), ans );
    return ans;
}

int pos[ maxn * 2 ];

int main() {
    int n;
    scanf( "%d", &n );
    cnt = 0;
    ma.clear();
    memset( pos, 0, sizeof pos );
    for ( int i = 0; i < n; i++ ) {
        scanf( "%d%d", &a[ i ].x, &a[ i ].R );
        a[ i ].l     = a[ i ].x - a[ i ].R;
        a[ i ].r     = a[ i ].x + a[ i ].R;
        pos[ cnt++ ] = a[ i ].l;
        pos[ cnt++ ] = a[ i ].r;
    }

    sort( pos, pos + cnt );
    int k          = 2;
    ma[ pos[ 0 ] ] = 1;
    for ( int i = 1; i < cnt; i++ ) {
        if ( pos[ i ] == pos[ i - 1 ] ) {
            continue;
        }
        else {
            ma[ pos[ i ] ] = k++;
        }
    }
    for ( int i = 0; i < n; i++ ) {
        a[ i ].l = ma[ a[ i ].l ];
        a[ i ].r = ma[ a[ i ].r ];
    }

    sort( a, a + n, cmp );
    build( 1, 1, k - 1 );
    ll ans = n + 1;
    ll num = 0;
    for ( int i = 0; i < n; i++ ) {
        int x = query( 1, a[ i ].l, a[ i ].r - 1 );
        if ( x ) {
            num++;
        }
        updata( 1, a[ i ].l, a[ i ].r - 1, 1 );
    }
    printf( "%lld\n", ans + num );
}
