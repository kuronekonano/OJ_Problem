#include <stdio.h> ///prim
#include <string.h>
/// 建图――邻接矩阵
int vis[150][150]; /// 邻接矩阵数组，将两城镇连接，并存储距离
int main() {
  int x, y, i, n, j, dis;
  while (scanf("%d", &n) != EOF) {
    if (!n)
      return 0;
    for (i = 0; i < n * (n - 1) / 2; i++) {
      scanf("%d%d%d", &x, &y, &dis); /// x起点，y终点，w距离
      vis[x][y] = dis;
      vis[y][x] =
          dis; /// 当为无向图是加入此句，否则不加，公路是双向的，当然是无向图
    }
    int minn, mini,
        sum = 0; /// 分别记录
                 /// minn为到达节点的最小长度，minid为最小的节点，sum为长度总和
    bool seta[150];   /// 标记是否走过
    int lowcost[150]; /// 到达某个节点所需要的最小距离
    int mst[150];     /// 记录父亲节点，形成树结构
    memset(seta, false, sizeof(seta));
    memset(mst, 0, sizeof(mst));
    memset(
        lowcost, 0x3f,
        sizeof(
            lowcost)); /// 储存每个点到现在已经构造好的生成树
                       /// 也就是集合b的最短距离，memset按字节初始化0x7f是一个约等于最大值的数
    /// 将其初始化的原因：表示不可取
    mst[1] = 0;              /// 1号节点为根节点，入度为0，没有父亲节点
    seta[1] = true;          /// 标记1号节点走过
    for (i = 2; i <= n; i++) /// 初始化
    {
      mst[i] = 1;
      lowcost[i] = vis[1][i]; /// lowcos的初始化第i个值，等于从1连接到i的距离
    }
    for (i = 2; i <= n; i++) /// 每次循环就新到达一个点，总共遍历n-1个点
    {
      minn = 0x7fffffff;       /// 初始化长度最小值
      mini = 0;                /// 初始化到达长度最小的节点
      for (j = 1; j <= n; j++) /// 第一次遍历，查找一个能到达的节点中距离最短的
      {
        if (!seta[j] && lowcost[j] < minn) {
          minn = lowcost[j];
          mini = j;
        }
      } /// 记录下来
      if (minn == 0x7fffffff)
        return -1;
      sum += minn;       /// 求和
      seta[mini] = true; /// 标记
      for (
          j = 1; j <= n;
          j++) /// 第二次遍历，在走了上一个点的基础上，更新所有未走的点的最短距离
      {
        if (!seta[j] && vis[mini][j] < lowcost[j]) {
          lowcost[j] = vis[mini][j];
          mst[j] = mini; /// 更新父亲节点
        }
      }
    }
    printf("%d\n", sum);
  }
}

/////BY: Torrance_ZHANG
// #include <stdio.h>///prim
// #include <iostream>
// #include <string.h>
// #include <math.h>
// #include <algorithm>
// #include <stack>
// #include <queue>
// #include <set>
// #include <map>
// using namespace std;
// const int MAX_NUM = 0x7fffffff;
// const int N = 1005; ///点的最大值
// const int M = 10005;///边的最大值
/////建图――邻接矩阵
// int ma[N][N];///邻接矩阵数组，将两城镇连接，并存储距离
// void CreateMatrix(int n)
//{
//     memset(ma,0x7f,sizeof(ma));///初始化为最大值(距离)表示不能走
//     int u,v,w;      ///u起点，v终点，w权值
//     for(int i=0; i<n*(n-1)/2; i++)
//     {
//         scanf("%d%d%d",&u,&v,&w);
//         ma[u][v]=w;
//         ma[v][u]=w; ///当为无向图是加入此句，否则不加
//     }///公路相通所以是无向图
// }
//
// int prim(int n)        ///prim算法，点从1号开始
//{
//     int lowcost[N];  ///lowcost[i]代表i节点到集合A的最小距离
//     int minn, minid, sum =
//     0;///minn为长度最小，minid为最小的节点，sum为长度总和 bool vis[N]; int
//     mst[N];///记录父亲节点，形成树结构 memset(vis, false,
//     sizeof(vis));///清空三个数组，vis作为标记数组，所有的点未走过，标记false
//     memset(mst, 0, sizeof(mst));///记录父亲节点，形成树结构
//     memset(lowcost, 0x7f,
//     sizeof(lowcost));///储存每个点到现在已经构造好的生成树
//     也就是集合b的最短距离，memset按字节初始化0x7f是一个约等于最大值的数
//     ///将其初始化的原因：表示不可取
//     for(int i = 2; i <= n; i ++)///从第二个点开始初始化
//     {
//         mst[i] = 1;///初始化，所有父亲节点都是1
//         lowcost[i] = ma[1][i];///lowcos的初始化第i个值，等于从1连接到i的距离
//     }
//
//     mst[1] = 0;///1的父亲节点是0
//     vis[1] = true;///标记第一个点走过
//
//     for(int i = 2; i <= n; i++)///每次循环就新到达一个点
//     {
//         minn = MAX_NUM;///初始化长度最小值为最大
//         minid = 0;///走向最小值长度的路径所通往的城镇序号为minid
//         for(int j = 1; j <= n; j ++)/*遍历一遍所有点*/
//         {
//             ///这个循环从1开始，但是遍历时，因为j=1时，vis[1]是标记过的，所以直接跳过了
//             if(lowcost[j] < minn &&
//             !vis[j])///比较到达第j个点比当前记录的最短路径短,且未被标记(走过)
//             {
//                 minn = lowcost[j];///记录最小值
//                 minid = j;///记录最小值序号
//             }
//         }
//         if(minn == MAX_NUM) return
//         -1;///如果最小值从未被更新，走不通，直接返回-1 sum +=
//         minn;///求和加上所求最小值 vis[minid] =
//         true;///所取的最小路径所到达的城镇，被标记为走过 for(int j = 1; j <=
//         n; j ++)/*再遍历一遍所有点*/
//         {
//             if(!vis[j] && ma[minid][j] <
//             lowcost[j])///如果这个点未被标记，且刚刚所收录的最小值点到到达下一个点
//             {///的距离小于所有到达到那个点的距离
//                 lowcost[j] = ma[minid][j];///更新
//                 新的达到那个点的距离(较小值) mst[j] = minid;///记录父亲节点
//             }
//         }
//     }
//     /*for(int k=1;k<=n;k++){
//         cout<<"lowcost-"<<k<<"===="<<lowcost[k]<<endl;
//     }
//     for(int k=1;k<=n;k++){
//         cout<<"mst-"<<k<<"===="<<mst[k]<<endl;
//     }*/
//     return sum;
// }
// int main()
//{
//     int t;
//     while(~scanf("%d",&t)&&t)///t个城镇
//     {
//         CreateMatrix(t);
//         int res=prim(t);
//         printf("%d\n",res);
//     }
// }
