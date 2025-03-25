#include <algorithm>
#include <stdio.h>
using namespace std;
struct Road /// �����������Ǵ��Ķ�(from)��(to)�Ķ����Լ�����(val)
{
  int x, y, dis;
} road[10000];
bool cmp(Road a, Road b) /// �ṹ������
{
  return a.dis < b.dis; /// �����Ȱ���С��������
}
int finds[150];
int Find(int n) /// ���鼯�Ĳ��Һ���
{
  return finds[n] == n ? n : Find(finds[n]);
}
void join(int x, int y) /// ��Ϊһ��������
{
  finds[Find(x)] = Find(y);
}
int main() {
  int n, i, j;
  while (scanf("%d", &n) != EOF) /// n������m����
  {
    if (!n)
      break;
    int m = n * (n - 1) / 2; /// �����Ǳߵ�����
    for (i = 0; i < m;
         i++) /// ������Ķ����Ķ������ﲻ�������ڽӾ����ˣ�ֱ�Ӹ��߸�����Ϣ
    {
      scanf("%d%d%d", &road[i].x, &road[i].y, &road[i].dis);
    }
    sort(road, road + m, cmp); /// ���߰���С��������
    for (i = 0; i <= n; i++)   /// Ԥ����
    {
      finds[i] = i;
    }
    int sum = 0, flag = 0;
    for (i = 0; i < m; i++) /// �ӳ���С�ı߿�ʼ����
    {
      if (Find(road[i].x) != Find(road[i].y)) /// ��һС�ıߵĿ�ʼ�ͽ�β��˾��ͬ
      { /// ����������ǵ���˾��һ����˵������֮��û����ͨ�����ṹ�ɻ�״������ѡ�������߼���
        flag++;                     /// �Ѿ�����ı߼���
        join(road[i].x, road[i].y); /// ������Ӧ�ڵ��Ϊһ������(��ʾ�Ѿ���ͨ)
        sum += road[i].dis;         /// �ܳ��ȼ���������
      } /// ������һ���̱ߵ����������Ƿ���ͨ��û��ͨ������ͨ���ܺͼ��������ߵĳ���
      if (flag == m - 1)
        break; /// ��ס�����Ǳߵ�������m������������n������
    } /// ��Ϊn�����򲻻ᳬ��n-1���ߣ���˵��ﵽ�������Ŀʱ�Ϳ��������ˣ���ʱ�ܺ;���������̱��ܺ�
    printf("%d\n", sum);
  }
  return 0;
}

/////BY: Torrance_ZHANG
// #include <stdio.h>///kruscal
// #include <iostream>
// #include <string.h>///prim�Ǳ����㣬kruscal�Ǳ�����
// #include <math.h>///�������˲��鼯��˼��
// #include <algorithm>
// #include <stack>
// #include <queue>
// #include <set>
// #include <map>
// using namespace std;
// const int MAX_NUM = 0x7fffffff;
// const int N = 1005; ///������ֵ
// const int M = 10005;///�ߵ����ֵ
// struct Edge   ///��¼�ߵ���Ϣ�Ľṹ��
//{
//     int from,to,val;
// } edge[10010];
// int fa[N];
// void init(int n)///Ԥ����ÿ���ڵ����˾�����Լ�
//{
//     for (int i=0; i<=n; i++) fa[i]=i;
// }
// int Find(int u)
//{
//     return fa[u] == u ? fa[u] : fa[u] = Find(fa[u]);///����˾
// }
// void unin(int u, int v)
//{
//     fa[Find(v)] = Find(u);
// }
// bool cmp(Edge a,Edge b)
//{
//     return a.val<b.val;
// }
// int kruscal(int n,int m)
//{
//     init(n);
//     int sum=0;
//     for(int i=0; i<m; i++)
//     {
//         scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].val);
//     }
//     int cnt=0;
//     sort(edge,edge+m,cmp);
//     for(int i=0; i<m; i++)
//     {
//         if(Find(edge[i].from)!=Find(edge[i].to))
//         {
//             sum+=edge[i].val;
//             cnt++;
//             unin(edge[i].from,edge[i].to);
//         }
//         if(cnt==n-1) break;
//     }
//     return sum;
// }
// int main()
//{
//     int t;
//     while(~scanf("%d",&t)&&t)///t������
//     {
//         int res=kruscal(t,t*(t-1)/2);///t�������Լ�t*(t-1)/2����
//         printf("%d\n",res);
//     }
// }
