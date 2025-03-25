#include <algorithm>
#include <stdio.h>
using namespace std;
struct Road /// 包括这条边是从哪儿(from)到(to)哪儿，以及长度(val)
{
  int x, y, dis;
} road[10000];
bool cmp(Road a, Road b) /// 结构体排序
{
  return a.dis < b.dis; /// 给长度按从小到大排序
}
int finds[150];
int Find(int n) /// 并查集的查找函数
{
  return finds[n] == n ? n : Find(finds[n]);
}
void join(int x, int y) /// 合为一个集合中
{
  finds[Find(x)] = Find(y);
}
int main() {
  int n, i, j;
  while (scanf("%d", &n) != EOF) /// n个城镇，m条边
  {
    if (!n)
      break;
    int m = n * (n - 1) / 2; /// 这里是边的数量
    for (i = 0; i < m;
         i++) /// 输入从哪儿到哪儿，这里不是利用邻接矩阵了，直接给边赋予信息
    {
      scanf("%d%d%d", &road[i].x, &road[i].y, &road[i].dis);
    }
    sort(road, road + m, cmp); /// 给边按从小到大排序
    for (i = 0; i <= n; i++)   /// 预处理
    {
      finds[i] = i;
    }
    int sum = 0, flag = 0;
    for (i = 0; i < m; i++) /// 从长度小的边开始遍历
    {
      if (Find(road[i].x) != Find(road[i].y)) /// 第一小的边的开始和结尾上司不同
      { /// 这里如果他们的上司不一样，说明他们之间没有连通，不会构成环状，可以选择这条边加上
        flag++;                     /// 已经加入的边计数
        join(road[i].x, road[i].y); /// 并把相应节点合为一个集合(表示已经连通)
        sum += road[i].dis;         /// 总长度加上这条边
      } /// 再找下一个短边的两个城镇是否连通，没连通则将其连通，总和加上那条边的长度
      if (flag == m - 1)
        break; /// 记住这里是边的数量，m的数量，不是n的数量
    } /// 因为n个城镇不会超过n-1条边，因此当达到这个边数目时就可以跳出了，此时总和就是所有最短边总和
    printf("%d\n", sum);
  }
  return 0;
}

/////BY: Torrance_ZHANG
// #include <stdio.h>///kruscal
// #include <iostream>
// #include <string.h>///prim是遍历点，kruscal是遍历边
// #include <math.h>///并利用了并查集的思想
// #include <algorithm>
// #include <stack>
// #include <queue>
// #include <set>
// #include <map>
// using namespace std;
// const int MAX_NUM = 0x7fffffff;
// const int N = 1005; ///点的最大值
// const int M = 10005;///边的最大值
// struct Edge   ///记录边的信息的结构体
//{
//     int from,to,val;
// } edge[10010];
// int fa[N];
// void init(int n)///预处理，每个节点的上司都是自己
//{
//     for (int i=0; i<=n; i++) fa[i]=i;
// }
// int Find(int u)
//{
//     return fa[u] == u ? fa[u] : fa[u] = Find(fa[u]);///找上司
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
//     while(~scanf("%d",&t)&&t)///t个城镇
//     {
//         int res=kruscal(t,t*(t-1)/2);///t个城镇，以及t*(t-1)/2条边
//         printf("%d\n",res);
//     }
// }
