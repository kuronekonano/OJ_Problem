#include<stdio.h>///prim
#include<string.h>
///��ͼ�����ڽӾ���
int vis[150][150];///�ڽӾ������飬�����������ӣ����洢����
int main()
{
    int x,y,i,n,j,dis;
    while(scanf("%d",&n)!=EOF)
    {
        if(!n)return 0;
        for(i=0;i<n*(n-1)/2;i++)
        {
            scanf("%d%d%d",&x,&y,&dis);///x��㣬y�յ㣬w����
            vis[x][y]=dis;
            vis[y][x]=dis;///��Ϊ����ͼ�Ǽ���˾䣬���򲻼ӣ���·��˫��ģ���Ȼ������ͼ
        }
        int minn,mini,sum=0;///�ֱ��¼ minnΪ����ڵ����С���ȣ�minidΪ��С�Ľڵ㣬sumΪ�����ܺ�
        bool seta[150];///����Ƿ��߹�
        int lowcost[150];///����ĳ���ڵ�����Ҫ����С����
        int mst[150];///��¼���׽ڵ㣬�γ����ṹ
        memset(seta,false,sizeof(seta));
        memset(mst,0,sizeof(mst));
        memset(lowcost,0x3f,sizeof(lowcost));///����ÿ���㵽�����Ѿ�����õ������� Ҳ���Ǽ���b����̾��룬memset���ֽڳ�ʼ��0x7f��һ��Լ�������ֵ����
        ///�����ʼ����ԭ�򣺱�ʾ����ȡ
        mst[1]=0;///1�Žڵ�Ϊ���ڵ㣬���Ϊ0��û�и��׽ڵ�
        seta[1]=true;///���1�Žڵ��߹�
        for(i=2;i<=n;i++)///��ʼ��
        {
            mst[i]=1;
            lowcost[i]=vis[1][i];///lowcos�ĳ�ʼ����i��ֵ�����ڴ�1���ӵ�i�ľ���
        }
        for(i=2;i<=n;i++)///ÿ��ѭ�����µ���һ���㣬�ܹ�����n-1����
        {
            minn=0x7fffffff;///��ʼ��������Сֵ
            mini=0;///��ʼ�����ﳤ����С�Ľڵ�
            for(j=1;j<=n;j++)///��һ�α���������һ���ܵ���Ľڵ��о�����̵�
            {
                if(!seta[j]&&lowcost[j]<minn)
                {
                    minn=lowcost[j];
                    mini=j;
                }
            }///��¼����
            if(minn==0x7fffffff)return -1;
            sum+=minn;///���
            seta[mini]=true;///���
            for(j=1;j<=n;j++)///�ڶ��α�������������һ����Ļ����ϣ���������δ�ߵĵ����̾���
            {
                if(!seta[j]&&vis[mini][j]<lowcost[j])
                {
                    lowcost[j]=vis[mini][j];
                    mst[j]=mini;///���¸��׽ڵ�
                }
            }
        }
        printf("%d\n",sum);
    }
}

/////BY: Torrance_ZHANG
//#include <stdio.h>///prim
//#include <iostream>
//#include <string.h>
//#include <math.h>
//#include <algorithm>
//#include <stack>
//#include <queue>
//#include <set>
//#include <map>
//using namespace std;
//const int MAX_NUM = 0x7fffffff;
//const int N = 1005; ///������ֵ
//const int M = 10005;///�ߵ����ֵ
/////��ͼ�����ڽӾ���
//int ma[N][N];///�ڽӾ������飬�����������ӣ����洢����
//void CreateMatrix(int n)
//{
//    memset(ma,0x7f,sizeof(ma));///��ʼ��Ϊ���ֵ(����)��ʾ������
//    int u,v,w;      ///u��㣬v�յ㣬wȨֵ
//    for(int i=0; i<n*(n-1)/2; i++)
//    {
//        scanf("%d%d%d",&u,&v,&w);
//        ma[u][v]=w;
//        ma[v][u]=w; ///��Ϊ����ͼ�Ǽ���˾䣬���򲻼�
//    }///��·��ͨ����������ͼ
//}
//
//int prim(int n)        ///prim�㷨�����1�ſ�ʼ
//{
//    int lowcost[N];  ///lowcost[i]����i�ڵ㵽����A����С����
//    int minn, minid, sum = 0;///minnΪ������С��minidΪ��С�Ľڵ㣬sumΪ�����ܺ�
//    bool vis[N];
//    int mst[N];///��¼���׽ڵ㣬�γ����ṹ
//    memset(vis, false, sizeof(vis));///����������飬vis��Ϊ������飬���еĵ�δ�߹������false
//    memset(mst, 0, sizeof(mst));///��¼���׽ڵ㣬�γ����ṹ
//    memset(lowcost, 0x7f, sizeof(lowcost));///����ÿ���㵽�����Ѿ�����õ������� Ҳ���Ǽ���b����̾��룬memset���ֽڳ�ʼ��0x7f��һ��Լ�������ֵ����
//    ///�����ʼ����ԭ�򣺱�ʾ����ȡ
//    for(int i = 2; i <= n; i ++)///�ӵڶ����㿪ʼ��ʼ��
//    {
//        mst[i] = 1;///��ʼ�������и��׽ڵ㶼��1
//        lowcost[i] = ma[1][i];///lowcos�ĳ�ʼ����i��ֵ�����ڴ�1���ӵ�i�ľ���
//    }
//
//    mst[1] = 0;///1�ĸ��׽ڵ���0
//    vis[1] = true;///��ǵ�һ�����߹�
//
//    for(int i = 2; i <= n; i++)///ÿ��ѭ�����µ���һ����
//    {
//        minn = MAX_NUM;///��ʼ��������СֵΪ���
//        minid = 0;///������Сֵ���ȵ�·����ͨ���ĳ������Ϊminid
//        for(int j = 1; j <= n; j ++)/*����һ�����е�*/
//        {
//            ///���ѭ����1��ʼ�����Ǳ���ʱ����Ϊj=1ʱ��vis[1]�Ǳ�ǹ��ģ�����ֱ��������
//            if(lowcost[j] < minn && !vis[j])///�Ƚϵ����j����ȵ�ǰ��¼�����·����,��δ�����(�߹�)
//            {
//                minn = lowcost[j];///��¼��Сֵ
//                minid = j;///��¼��Сֵ���
//            }
//        }
//        if(minn == MAX_NUM) return -1;///�����Сֵ��δ�����£��߲�ͨ��ֱ�ӷ���-1
//        sum += minn;///��ͼ���������Сֵ
//        vis[minid] = true;///��ȡ����С·��������ĳ��򣬱����Ϊ�߹�
//        for(int j = 1; j <= n; j ++)/*�ٱ���һ�����е�*/
//        {
//            if(!vis[j] && ma[minid][j] < lowcost[j])///��������δ����ǣ��Ҹո�����¼����Сֵ�㵽������һ����
//            {///�ľ���С�����е��ﵽ�Ǹ���ľ���
//                lowcost[j] = ma[minid][j];///���� �µĴﵽ�Ǹ���ľ���(��Сֵ)
//                mst[j] = minid;///��¼���׽ڵ�
//            }
//        }
//    }
//    /*for(int k=1;k<=n;k++){
//        cout<<"lowcost-"<<k<<"===="<<lowcost[k]<<endl;
//    }
//    for(int k=1;k<=n;k++){
//        cout<<"mst-"<<k<<"===="<<mst[k]<<endl;
//    }*/
//    return sum;
//}
//int main()
//{
//    int t;
//    while(~scanf("%d",&t)&&t)///t������
//    {
//        CreateMatrix(t);
//        int res=prim(t);
//        printf("%d\n",res);
//    }
//}
