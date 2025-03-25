// #include<stdio.h>///LCA最近公共祖先查询，朴素算法
// #include<string.h>
// int fa[10008];
// int deep(int x)///计算x节点深度
//{
//     int cnt=0;
//     while(x)
//     {
//         cnt++;
//         x=fa[x];
//     }
//     return cnt;
// }
// int main()
//{
//     int t,n;
//     scanf("%d",&t);
//     while(t--)
//     {
//         memset(fa,0,sizeof(fa));///该数组记录每个节点的父亲，根节点父亲为0
//         int s,f;
//         scanf("%d",&n);
//         for(int i=0;i<n-1;i++)
//         {
//             scanf("%d%d",&f,&s);
//             fa[s]=f;
//         }
//         int a,b;
//         scanf("%d%d",&a,&b);
//         int aa=deep(a),bb=deep(b);
//         if(aa<bb)///查询的深度若两个节点深度不同，将较深的节点先上移
//         {
//             int tt=bb-aa;
//             while(tt--)
//                 b=fa[b];
//         }
//         else if(aa>bb)
//         {
//             int tt=aa-bb;
//             while(tt--)
//                 a=fa[a];
//         }
//         while(a!=b)///两个节点深度相同时同时向上寻找父亲，直到父亲相同
//             a=fa[a],b=fa[b];
//         printf("%d\n",a);
//     }
// }
/// LCA倍增法
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define M(a, b) memset(a, b, sizeof(a))
#define pb push_back
int n;
int fa[15][10005], dep[10005];
vector<int> g[10005];
void dfs(int u) /// 深搜深度
{
  if (g[u].size() == 0) /// 没有儿子的叶子结点直接返回
    return;
  for (int i = 0; i < g[u].size(); ++i) /// 遍历该结点所有儿子
  {
    int v = g[u][i];
    dep[v] = dep[u] + 1; /// 儿子结点v的深度等于父亲的深度+1
    dfs(v);              /// 继续查找儿子的儿子的深度
  }
}
void init() /// 预处理倍增数组
{
  for (int i = 0; i < 13; ++i)   /// 某个结点向上2的13次幂的祖先记录
    for (int j = 1; j <= n; ++j) /// 遍历所有结点
    {
      if (fa[i][j] == -1)
        continue; /// 根节点跳过
      fa[i + 1][j] = fa
          [i]
          [fa[i]
             [j]]; /// 倍增，2的i+1次幂的结点j的父亲，等于2的i次幂的结点j的父亲的父亲
    }
}
int lca(int u, int v) {
  if (dep[u] > dep[v])
    swap(u, v);                 /// 规定v的深度是大于u深度的结点
  for (int i = 13; i >= 0; --i) /// 若两结点深度不同
    if ((dep[v] - dep[u]) &
        (1 << i)) /// 根据深度之差的二进制，判断第i位是0还是1，是1则向上跳
      v = fa[i][v];

  if (u ==
      v) /// 统一深度之后若两结点相同，则直接返回该结点名，表示其中那个深度低的是公共祖先
    return u;

  for (int i = 13; i >= 0; --i) /// 两结点同时上跳回溯
    if (fa[i][u] != fa[i][v]) {
      u = fa[i][u];
      v = fa[i][v];
    }
  return fa[0][u];
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      g[i].clear();
    M(fa, -1);
    M(dep, 0);
    for (int i = 1; i < n; ++i) /// 建树
    {
      int u, v;
      scanf("%d%d", &u, &v);
      fa[0][v] = u; /// 记录每个节点v的直接父亲u
      g[u].pb(v);   /// 在u的直系儿子中增加结点v
    }
    int rt;
    for (int i = 1; i <= n; ++i) /// 找根节点
      if (fa[0][i] == -1) {
        rt = i;
        break;
      }
    dep[rt] = 1; /// 根结点上深度定为1
    dfs(rt);     /// 深搜所有结点
    init();
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", lca(u, v));
  }
  return 0;
}
