#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int mp[3000][3000];
int n,s,t;
int dijkstra(int s,int t)
{
    int dist[100];
    bool vis[105];
    memset(vis,false,sizeof(vis));
    vis[s]=true;
    for(int i=1;i<=n;i++) dist[i]=mp[s][i];
    dist[s]=0;
    for(int i=1;i<n;i++)
    {
        int minn=0x7fffffff,mini;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&dist[j]<minn) mini=j,minn=dist[j];
        vis[mini]=true;
        for(int j=1;j<=n;j++)
            if(dist[j]>dist[mini]+mp[mini][j])
                dist[j]=dist[mini]+mp[mini][j];
    }
    return dist[t];
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(mp,0x3f,sizeof(mp));
        scanf("%d%d",&s,&t);
        int x,y,val;
        while(scanf("%d",&x)!=EOF)
        {
            if(x==0)break;
            scanf("%d%d",&y,&val);
            mp[x][y]=mp[y][x]=val;
        }
        printf("%d\n",dijkstra(s,t));
    }
}
