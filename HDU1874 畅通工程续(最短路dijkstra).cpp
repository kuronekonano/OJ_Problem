#include<stdio.h>///优先队列优化dijkstra
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
const int N=208;
const int MAX=0x7fffffff;
int dist[N];///记录到达每个节点的最短路
int n,m,flag;
struct Edge
{
    int to,val;///点的标号以及到达此点需要的权值
    Edge(int a=0,int b=0):to(a),val(b) {} ///结构体构造函数
    bool operator <(const Edge &a)const///重载运算符
    {
        if(val==a.val)return to<a.to;
        return val>a.val;
    }
};
vector<Edge>v[N];///(结构体类型)动态数组做邻接矩阵
void dijkstra(int s)
{
    bool vis[N];
    memset(dist,0x3f,sizeof(dist));///一开始到达所有节点的路程都是inf
    memset(vis,false,sizeof vis);
    flag=dist[0];///用于判断无法到达的情况(-1)
    dist[s]=0;///到达起点的最短路为0
    priority_queue<Edge>q;///优先队列优化
    q.push(Edge(s,0));///将起始节点放入队列中
    while(!q.empty())
    {
        Edge top=q.top();
        q.pop();
        if(vis[top.to])continue;
        vis[top.to]=true;
        for(int i=0; i<v[top.to].size(); i++) ///遍历所有从当前点出发到达的所有节点
        {
            Edge tmp=v[top.to][i];
            if(dist[tmp.to]>top.val+tmp.val)///用当前节点松弛目的节点的最短路
            {
                dist[tmp.to]=top.val+tmp.val;
                q.push(Edge(tmp.to,dist[tmp.to]));///每次投入队列中的结构体都是直接构造的，并不是原先就存在的
            }                                     ///投入一个可以到达的点，权值取当前到达节点的已知最短路
        }
    }
}
int main()
{
    int i,j,k,x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0; i<=N; i++)v[i].clear(); ///清空数组
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&x,&y,&k);///这里结构体仅存储到达某个点的权值，至于谁到达这个点的权值，由动态数组下标存储
            v[x].push_back(Edge(y,k));///无向图
            v[y].push_back(Edge(x,k));
        }///相当于一个点到达另一个点的权值，由另一个点的结构体来存储，而动态数组存储所有自己能到的的点结构体，结构体内的权值也就是动态数组下标到达结构体内标号的权值
        int s,t;
        scanf("%d%d",&s,&t);
        dijkstra(s);
        printf("%d\n",dist[t]==flag?-1:dist[t]);
    }
}

#include<stdio.h>///最短路朴素dijkstra
#include<string.h>
#include<algorithm>
using namespace std;
int dist[208];
int maps[208][209];
bool vis[208];
int n,m,flag;
void dijkstra(int s,int t)
{
    int i,j;
    memset(vis,false,sizeof(vis));
    memset(dist,0x3f,sizeof(dist));
    flag=dist[0];
    for(i=0; i<n; i++)///所有点到达起点的距离
    {
        dist[i]=maps[s][i];
    }
    dist[s]=0;///标记起点长度为0
    vis[s]=true;///标记走过
    for(i=1; i<n; i++)///遍历n-1次
    {
        int minn=0x7fffffff,mini;
        for(j=0; j<n; j++)///这里是要遍历所有的点，因为不一定是第0个点作为起点
        {
            if(!vis[j]&&dist[j]<minn)
            {
                minn=dist[j];
                mini=j;
            }
        }
        vis[mini]=true;
        for(j=0; j<n; j++)
        {
            dist[j]=min(dist[j],dist[mini]+maps[mini][j]);
        }
    }
//    for(i=0;i<n;i++)
//    {
//        printf("%d\n",dist[i]);
//    }
}
int main()
{
    int i,j,k,x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(maps,0x3f,sizeof(maps));///初始所有路段为无限大(不可到达)
        for(i=0; i<m; i++)///m条路
        {
            scanf("%d%d%d",&x,&y,&k);
            if(k<maps[x][y])
                maps[x][y] = maps[y][x] = k;///一直更新为最小路径
//            maps[y][x]=maps[x][y]=k;///无向图
        }
        int s,t;
        scanf("%d%d",&s,&t);///起点终点
        dijkstra(s,t);
        printf("%d\n",dist[t]==flag?-1:dist[t]);
    }
    return 0;
}
