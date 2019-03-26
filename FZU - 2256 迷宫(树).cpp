#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;
const int maxn=1e5+10;
struct edge
{
    int val,to;
    edge() {}
    edge(int a,int b)
    {
        val=a;
        to=b;
    }
};
int n,path[maxn],num;
int di[maxn],dist[maxn];
vector<edge>mp[maxn];
void dfs(int now)
{
    path[num++]=now;
    for(int i=0; i<num; i++)
        dist[now]=min(dist[now],dist[path[i]]+di[path[i]]);
    for(int i=0; i<mp[now].size(); i++)
    {
        edge to=mp[now][i];
        dist[to.to]=dist[now]+to.val;
        dfs(to.to);
    }
    num--;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int val,fa;
        for(int i=0; i<=n; i++)mp[i].clear();
        for(int i=1; i<=n; i++)scanf("%d",&di[i]);
        for(int i=2; i<=n; i++)
        {
            scanf("%d%d",&fa,&val);
            mp[fa].push_back(edge(val,i));
        }
        dist[1]=0;
        num=0;
        dfs(1);
        for(int i=1; i<=n; i++) printf("%d ",dist[i]);
        printf("\n");
    }
}
