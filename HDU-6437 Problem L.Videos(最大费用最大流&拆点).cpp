#include<bits/stdc++.h>///最大费用最大流，将边权变成相反数即可
#define LL long long
#define M(a,b) memset(a,b,sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn=1e5+7;
const int INF=0x3f3f3f3f;
struct edge
{
    int to,next,cap,flow,cost;
    edge() {}
    edge(int a,int b,int c,int d,int f)
    {
        to=a;
        cap=b;
        flow=c;
        cost=d;
        next=f;
    }
} mp[maxn<<1];
int pre[maxn],dis[maxn];
bool vis[maxn];
int head[maxn];
int n,m,k,w,cnt,N;
void init(int n)
{
    N=n;
    cnt=0;
    M(head,-1);
}
void addedge(int from,int to,int cap,int cost)
{
    mp[cnt]=edge(to,cap,0,cost,head[from]);
    head[from]=cnt++;
    mp[cnt]=edge(from,0,0,-cost,head[to]);
    head[to]=cnt++;
}
bool spfa(int s,int t)
{
    queue<int>q;
    for(int i = 0; i <=N; i++)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u]; i != -1; i = mp[i].next)
        {
            int v = mp[i].to;
            if(mp[i].cap > mp[i].flow && dis[v] > dis[u] + mp[i].cost )
            {
                dis[v] = dis[u] + mp[i].cost;
                pre[v] = i;
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t] == -1)return false;
    else return true;
}
int minCostMaxflow(int s,int t,int &cost)
{
    int flow = 0;
    cost = 0;
    while(spfa(s,t))
    {
        int Min = INF;
        for(int i = pre[t]; i != -1; i = pre[mp[i^1].to])
        {
            if(Min > mp[i].cap - mp[i].flow)
                Min = mp[i].cap - mp[i].flow;
        }
        for(int i = pre[t]; i != -1; i = pre[mp[i^1].to])
        {
            mp[i].flow += Min;
            mp[i^1].flow -= Min;
            cost += mp[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&m,&k,&w);
        init(m<<1+4);
        int from[maxn],to[maxn],val,flag[maxn];
        int st=0,ed=(m<<1)+1,S=(m<<1)+2,T=(m<<1)+3;///因此每个视频被拆成两个节点，因此总结点数达到了m*2，再加上超级源点和超级汇点
        addedge(st,S,k,0);
        addedge(T,ed,k,0);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d%d",&from[i],&to[i],&val,&flag[i]);
            addedge(S,i,1,0);
            addedge(i,i+m,1,-val);///因为有时间的限制，因此将一个视频拆成开始时间和结束时间
            addedge(i+m,T,1,0);
            for(int j=1; j<i; j++)///在输入的同时比较其他视频的开始时间，将结束时间小于开始时间的建一条有向边，容量为1，一个人只能看一个视频
                if(to[i]<=from[j])///再判断是否是同种视频，是同种则边权为负，否则为0
                    addedge(i+m,j,1,flag[i]==flag[j]?w:0);
                else if(to[j]<=from[i])
                    addedge(j+m,i,1,flag[i]==flag[j]?w:0);
        }
        int ans=0;
        minCostMaxflow(st,ed,ans);
        printf("%d\n",-ans);
    }
}
