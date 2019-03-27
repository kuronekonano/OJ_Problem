#include<bits/stdc++.h>
#define LL long long
#define M(a,b) memset(a,b,sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn=108;
const int inf=0x3f3f3f3f;
struct edge
{
    int to,rev;
    LL val;
    edge() {}
    edge(int a,LL b,int c)
    {
        to=a;
        val=b;
        rev=c;
    }
};
int n;
vector<edge>mp[maxn];
int dep[maxn];
inline void add(int from,int to,LL val)
{
    mp[from].pb(edge(to,val,mp[to].size()));
    mp[to].pb(edge(from,0,mp[from].size()-1));
}
bool bfs()
{
    M(dep,-1);
    queue<int>q;
    while(!q.empty())q.pop();
    dep[0]=0;
    q.push(0);
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        if(tmp==n+1)return true;
        for(int i=0;i<mp[tmp].size();i++)
        {
            int &to=mp[tmp][i].to;
            LL flow=mp[tmp][i].val;
            if(dep[to]==-1&&flow)
            {
                dep[to]=dep[tmp]+1;
                q.push(to);

            }
        }
    }
    return false;
}
LL dfs(int s,int t,LL flow)
{
    if(s==t)return flow;
    LL pre=0;
    for(int i=0;i<mp[s].size();i++)
    {
        int &to=mp[s][i].to;
        LL val=mp[s][i].val;
        if(dep[s]+1==dep[to]&&val)
        {
            int tmp=min(flow-pre,val);
            int sub=dfs(to,t,tmp);
            mp[s][i].val-=sub;
            mp[to][mp[s][i].rev].val+=sub;
            pre+=sub;
            if(pre==flow)return pre;
        }
    }
    return pre;
}
LL dinic()
{
    LL ans=0;
    while(bfs())ans+=dfs(0,n+1,inf);
    return ans;
}
int main()
{
    LL val,ans=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)mp[i].clear();
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&val);
        if(val>0)add(i,n+1,val),ans+=val;///正权连汇点
        else add(0,i,-val);///负权连源点
        for(int j=i+i;j<=n;j+=i) add(i,j,inf);///当给一个点连边时，应该向所有该点的倍数连一条容量无限的边，因为是选择这个x其倍数一定被选，因此是该点指向倍数的有向边
    }
    printf("%lld\n",ans-dinic());
}
