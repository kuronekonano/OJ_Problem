#include<stdio.h>///���������·�㷨 �жϸ���
#include<queue>
#include<vector>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,v;///n�ֻ��ң�m������վ����ʼ�õ�����v�Ż��ң���s��ֵ��v�Ż���
double s;
struct money
{
    int from,to;
    double r,c;
    money(int a=0,int b=0,double c=0,double d=0):from(a),to(b),r(c),c(d){}
}dao[300];
double dist[108];
int from,to,num=0;
bool Bellman_Ford(int start)
{
    memset(dist,0,sizeof(dist));///����Ϊ�·
    dist[start]=s;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<num;j++)
        {
            if(dist[dao[j].to]<(dist[dao[j].from]-dao[j].c)*dao[j].r)
            {
                dist[dao[j].to]=(dist[dao[j].from]-dao[j].c)*dao[j].r;
            }
        }
    }
    for(int i=0; i<num; i++)///�жϸ���
    {
        if(dist[dao[i].to]<(dist[dao[i].from]-dao[i].c)*dao[i].r)return true;
    }
    return false;
}
int main()
{
    while(scanf("%d%d%d%lf",&n,&m,&v,&s)!=EOF)
    {
        double rab,cab,rba,cba;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%lf%lf%lf%lf",&from,&to,&rab,&cab,&rba,&cba);
            dao[num++]=money(from,to,rab,cab);///����ߣ�ÿ��������Ϊһ���ڵ㣬ÿ������վ��Ϊ���������
            dao[num++]=money(to,from,rba,cba);///Ȩֵֻ�ñ��������Ѻͻ��ʼ��ɼ���val
        }
        if(Bellman_Ford(v))printf("YES\n");
        else printf("NO\n");
    }
}
