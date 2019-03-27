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
    Edge(int a=0,int b=0,int c=0):from(a),to(b),val(c) {}///��ĳ�㵽ĳ�������ߵļ�ֵ
} edge[Maxn];///�ߵĸ���������ߣ����Ҫ��������������*2��
int dist[maxn];
bool Bellman_Ford(int start)
{
    memset(dist,0x3f,sizeof(dist));
    dist[start]=0;
    for(int i=1; i<n; i++)///����ʼ����ʣ��n-1��������
    {
        for(int j=0; j<num; j++)///��num����
        {
            if(dist[edge[j].to]>dist[edge[j].from]+edge[j].val)
                dist[edge[j].to]=dist[edge[j].from]+edge[j].val;///�������·
        }
    }
    for(int i=0; i<num; i++)if(dist[edge[i].to]>dist[edge[i].from]+edge[i].val)return false;///�жϸ���
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
            edge[num++]=Edge(from,to,val);///�ӱ�(�����)
            edge[num++]=Edge(to,from,val);
        }
        int start,ends;
        scanf("%d%d",&start,&ends);
        Bellman_Ford(start);
        printf("%d\n",dist[ends]==0x3f3f3f3f?-1:dist[ends]);///�ж��Ƿ���Ե���ĳ����
    }
}
