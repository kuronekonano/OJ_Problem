#include<bits/stdc++.h>
#define LL long long
#define M(a,b) memset(a,b,sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn=3e5+7;
const int mod=998244353;
int n,t,mxdep=0;
LL k;
int fa[23][maxn],dep[maxn];
LL sum[maxn][55];
vector<int>g[maxn];
LL qp(LL a,LL b)
{
    if(a==0)return 0;
    LL ans=1;
    while(b)
    {
        if(b&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;

}
void init()
{
    for(int i=0; i<20; i++)
        for(int j=1; j<=n; j++)
        {
            if(fa[i][j]==-1)continue;
            fa[i+1][j]=fa[i][fa[i][j]];
        }

    for(LL i=1; i<=50; i++)///预处理所有深度幂次为1~50的值的前缀和
        for(LL j=0; j<=mxdep; j++)
            if(j==0)sum[j][i]=0;
            else sum[j][i]=(sum[j-1][i]+qp(j,i))%mod;
}
void dfs(int u)///深搜计算深度
{
    if(g[u].size()==0)return;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        dep[v]=dep[u]+1;
        if(dep[v]>mxdep)mxdep=dep[v];
        dfs(v);
    }
}
int lca(int u,int v)///倍增找最近公共祖先
{
    if(dep[u]>dep[v]) swap(u,v);
    for(int i=20; i>=0; i--)
        if((dep[v]-dep[u])&(1<<i))
            v=fa[i][v];
    if(u==v)return u;
    for(int i=20; i>=0; i--)
        if(fa[i][u]!=fa[i][v])
        {
            u=fa[i][u];
            v=fa[i][v];
        }
    return fa[0][u];
}
int main()
{
    mxdep=0;
    scanf("%d",&n);
    for(int i=0; i<=n; i++) g[i].clear();
    M(fa,-1);
    M(dep,-1);
    int u,v;
    for(int i=1; i<n; i++)
    {
        scanf("%d%d",&u,&v);
        fa[0][v]=u;
        g[u].pb(v);
    }
    int rt;
    for(int i=1; i<=n; i++)
        if(fa[0][i]==-1)
        {
            rt=i;
            break;
        }
    dep[rt]=0;
    dfs(rt);
    init();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%lld",&u,&v,&k);
        int tmp=lca(u,v);///拿路径两端点的深度与LCA的深度求和
        LL  ans=(sum[dep[u]][k]+sum[dep[v]][k])%mod;///利用前缀和快速求出两深度上经过的所有深度幂次和
        ans=(ans-sum[dep[tmp]][k]+mod)%mod;///减去两次公共祖先的前缀和，加上一次公共祖先的幂次
        ans=(ans-sum[dep[tmp]][k]+mod)%mod;
        ans=(ans+qp(dep[tmp],k))%mod;
        printf("%lld\n",ans);
    }
}
/*
5
1 2
1 3
2 4
2 5
2
1 4 5
5 4 45
*/
