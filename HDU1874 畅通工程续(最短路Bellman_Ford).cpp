#include<stdio.h>///Bellman_Ford
#include<algorithm>
#include<string.h>
#define Maxn 2300
#define maxn 230
using namespace std;
int n,m,num;
struct Edge
{
    int from,to,val;
    Edge(int a=0,int b=0,int c=0):from(a),to(b),val(c) {}///从某点到某点的有向边的价值
} edge[Maxn];///边的个数存有向边，因此要比最大无向边数量*2多
int dist[maxn];
bool Bellman_Ford(int start)
{
    memset(dist,0x3f,sizeof(dist));
    dist[start]=0;
    for(int i=1; i<n; i++)///除起始点外剩下n-1次数更新
    {
        for(int j=0; j<num; j++)///有num条边
        {
            if(dist[edge[j].to]>dist[edge[j].from]+edge[j].val)
                dist[edge[j].to]=dist[edge[j].from]+edge[j].val;///更新最短路
        }
    }
    for(int i=0; i<num; i++)if(dist[edge[i].to]>dist[edge[i].from]+edge[i].val)return false;///判断负环
    return true;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int from,to,val;
        num=0;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&from,&to,&val);
            edge[num++]=Edge(from,to,val);///加边(无向边)
            edge[num++]=Edge(to,from,val);
        }
        int start,ends;
        scanf("%d%d",&start,&ends);
        Bellman_Ford(start);
        printf("%d\n",dist[ends]==0x3f3f3f3f?-1:dist[ends]);///判断是否可以到达某个点
    }
}
