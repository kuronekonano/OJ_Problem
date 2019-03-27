#include<bits/stdc++.h>
#define LL long long
#define M(a,b) memset(a,b,sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn=5e4+7;
struct edge
{
    int from,to;
    LL val;
    edge(){}
    edge(int a,int b,LL c)
    {
        from=a,to=b,val=c;
    }
    bool operator <(const edge &a)const
    {
        return val<a.val;
    }
}mp[maxn*10];
int n,m,l,z[maxn];
int finds(int x)
{
    return z[x]==x?x:z[x]=finds(z[x]);
}
void join(int x,int y)
{
    z[finds(x)]=y;
}
int main()
{
    scanf("%d%d%d",&n,&m,&l);
    for(int i=1;i<=n;i++)z[i]=i;
    LL sum=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%lld",&mp[i].from,&mp[i].to,&mp[i].val);
        sum+=i<=l?mp[i].val:0;
    }
    sort(mp+1,mp+1+m);
    int cnt=0;
    LL dist=0;
    for(int i=1;i<=m;i++)
    {
        if(finds(mp[i].from)!=finds(mp[i].to))
        {
            join(mp[i].from,mp[i].to);
            dist+=mp[i].val;
            cnt++;
        }
    }
    printf("%s\n",cnt==n-1&&dist<=sum?"possible":"impossible");
}
