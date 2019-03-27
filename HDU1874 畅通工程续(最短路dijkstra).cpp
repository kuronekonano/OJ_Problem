#include<stdio.h>///���ȶ����Ż�dijkstra
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
const int N=208;
const int MAX=0x7fffffff;
int dist[N];///��¼����ÿ���ڵ�����·
int n,m,flag;
struct Edge
{
    int to,val;///��ı���Լ�����˵���Ҫ��Ȩֵ
    Edge(int a=0,int b=0):to(a),val(b) {} ///�ṹ�幹�캯��
    bool operator <(const Edge &a)const///���������
    {
        if(val==a.val)return to<a.to;
        return val>a.val;
    }
};
vector<Edge>v[N];///(�ṹ������)��̬�������ڽӾ���
void dijkstra(int s)
{
    bool vis[N];
    memset(dist,0x3f,sizeof(dist));///һ��ʼ�������нڵ��·�̶���inf
    memset(vis,false,sizeof vis);
    flag=dist[0];///�����ж��޷���������(-1)
    dist[s]=0;///�����������·Ϊ0
    priority_queue<Edge>q;///���ȶ����Ż�
    q.push(Edge(s,0));///����ʼ�ڵ���������
    while(!q.empty())
    {
        Edge top=q.top();
        q.pop();
        if(vis[top.to])continue;
        vis[top.to]=true;
        for(int i=0; i<v[top.to].size(); i++) ///�������дӵ�ǰ�������������нڵ�
        {
            Edge tmp=v[top.to][i];
            if(dist[tmp.to]>top.val+tmp.val)///�õ�ǰ�ڵ��ɳ�Ŀ�Ľڵ�����·
            {
                dist[tmp.to]=top.val+tmp.val;
                q.push(Edge(tmp.to,dist[tmp.to]));///ÿ��Ͷ������еĽṹ�嶼��ֱ�ӹ���ģ�������ԭ�Ⱦʹ��ڵ�
            }                                     ///Ͷ��һ�����Ե���ĵ㣬Ȩֵȡ��ǰ����ڵ����֪���·
        }
    }
}
int main()
{
    int i,j,k,x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0; i<=N; i++)v[i].clear(); ///�������
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&x,&y,&k);///����ṹ����洢����ĳ�����Ȩֵ������˭����������Ȩֵ���ɶ�̬�����±�洢
            v[x].push_back(Edge(y,k));///����ͼ
            v[y].push_back(Edge(x,k));
        }///�൱��һ���㵽����һ�����Ȩֵ������һ����Ľṹ�����洢������̬����洢�����Լ��ܵ��ĵĵ�ṹ�壬�ṹ���ڵ�ȨֵҲ���Ƕ�̬�����±굽��ṹ���ڱ�ŵ�Ȩֵ
        int s,t;
        scanf("%d%d",&s,&t);
        dijkstra(s);
        printf("%d\n",dist[t]==flag?-1:dist[t]);
    }
}

#include<stdio.h>///���·����dijkstra
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
    for(i=0; i<n; i++)///���е㵽�����ľ���
    {
        dist[i]=maps[s][i];
    }
    dist[s]=0;///�����㳤��Ϊ0
    vis[s]=true;///����߹�
    for(i=1; i<n; i++)///����n-1��
    {
        int minn=0x7fffffff,mini;
        for(j=0; j<n; j++)///������Ҫ�������еĵ㣬��Ϊ��һ���ǵ�0������Ϊ���
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
        memset(maps,0x3f,sizeof(maps));///��ʼ����·��Ϊ���޴�(���ɵ���)
        for(i=0; i<m; i++)///m��·
        {
            scanf("%d%d%d",&x,&y,&k);
            if(k<maps[x][y])
                maps[x][y] = maps[y][x] = k;///һֱ����Ϊ��С·��
//            maps[y][x]=maps[x][y]=k;///����ͼ
        }
        int s,t;
        scanf("%d%d",&s,&t);///����յ�
        dijkstra(s,t);
        printf("%d\n",dist[t]==flag?-1:dist[t]);
    }
    return 0;
}
