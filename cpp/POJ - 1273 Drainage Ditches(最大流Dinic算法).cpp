#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 208;
const int inf  = 0x3f3f3f3f;
struct edge  /// vector链式前向星
{
    int to, val, rev;
    edge() {}
    edge( int a, int b, int c ) {
        to  = a;
        val = b;
        rev = c;
    }
};
int            n, m, dep[ maxn ];
vector< edge > mp[ maxn ];
void           add( int from, int to, int val )  /// 加边
{
    mp[ from ].push_back( edge( to, val, mp[ to ].size() ) );
    mp[ to ].push_back( edge( from, 0, mp[ from ].size() - 1 ) );
}
int bfs() {
    memset( dep, -1, sizeof dep );
    queue< int > q;
    while ( !q.empty() )
        q.pop();
    dep[ 1 ] = 0;
    q.push( 1 );
    while ( !q.empty() ) {
        int tmp = q.front();
        q.pop();
        if ( tmp == n )
            return 1;
        for ( int i = 0; i < mp[ tmp ].size(); i++ ) {
            int &to = mp[ tmp ][ i ].to, flow = mp[ tmp ][ i ].val;
            if ( dep[ to ] == -1 && flow ) {
                dep[ to ] = dep[ tmp ] + 1;
                q.push( to );
            }
        }
    }
    return 0;
}
int dfs( int s, int t, int flow ) {
    if ( s == t )
        return flow;
    int pre = 0;
    for ( int i = 0; i < mp[ s ].size(); i++ ) {
        int &to = mp[ s ][ i ].to, val = mp[ s ][ i ].val;
        if ( dep[ s ] + 1 == dep[ to ] && val > 0 ) {
            int tmp = min( flow - pre, val );
            int sub = dfs( to, t, tmp );
            mp[ s ][ i ].val -= sub;
            mp[ to ][ mp[ s ][ i ].rev ].val += sub;
            pre += sub;
            if ( pre == flow )
                return pre;
        }
    }
    return pre;
}
int dinic() {
    int ans = 0;
    while ( bfs() )
        ans += dfs( 1, n, inf );
    return ans;
}
int main() {
    int from, to, val;
    while ( scanf( "%d%d", &m, &n ) != EOF ) {
        for ( int i = 0; i <= n; i++ )
            mp[ i ].clear();
        for ( int i = 0; i < m; i++ ) {
            scanf( "%d%d%d", &from, &to, &val );
            add( from, to, val );
        }
        printf( "%d\n", dinic() );
    }
}
/**
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn=208;
const int inf=0x3f3f3f3f;
struct edge///链式前向星
{
    int next,to,val;
}mp[maxn*maxn];
int head[maxn],dep[maxn],cnt;
int n,m;
void add(int from,int to,int val)///加边
{
    mp[cnt].to=to,mp[cnt].val=val;
    mp[cnt].next=head[from],head[from]=cnt++;
    mp[cnt].to=from,mp[cnt].val=0;
    mp[cnt].next=head[to],head[to]=cnt++;
}
int bfs()
{
    memset(dep,-1,sizeof dep);
    queue<int>q;
    while(!q.empty())q.pop();
    dep[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        if(tmp==n) return 1;
        for(int i=head[tmp];i!=-1;i=mp[i].next)
        {
            int &to=mp[i].to,flow=mp[i].val;
            if(dep[to]==-1&&flow)
            {
                dep[to]=dep[tmp]+1;
                q.push(to);
            }
        }
    }
    return 0;
}
int dfs(int s,int t,int flow)
{
    if(s==t)return flow;
    int pre=0;
    for(int i=head[s];i!=-1;i=mp[i].next)
    {
        int &to=mp[i].to,val=mp[i].val;
        if(dep[s]+1==dep[to]&&val>0)
        {
            int tmp=min(flow-pre,val);
            int sub=dfs(to,t,tmp);
            mp[i].val-=sub;
            mp[i^1].val+=sub;
            pre+=sub;
            if(pre==flow)return pre;
        }
    }
    return pre;
}
int dinic()
{
    int ans=0;
    while(bfs())ans+=dfs(1,n,inf);
    return ans;
}
int main()
{
    int from,to,val;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        cnt=0;
        memset(head,-1,sizeof head);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&from,&to,&val);
            add(from,to,val);
        }
        printf("%d\n",dinic());
    }
}
**/
