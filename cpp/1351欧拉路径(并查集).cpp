#include <stdio.h>
#include <string.h> ///并查集的方法检测是否为一个连通图，判断最终boss的数量是为同一个，即为一个连通图，否则则不连通
int z[108];
int drg[108];
int find(int x) {
  int r = x, t;
  while (r != z[r]) // 找上级，并压缩路径
  {
    t = r;       /// 压缩路径步骤
    r = z[r];    /// 上溯步骤
    z[t] = z[r]; /// 压缩路径步骤
  }
  return r;
}
void join(int a, int b) // join函数建立各个点之间的从属关系
{
  int fa = find(a), fb = find(b); // 查找双方的上级，如果不同则建立从属关系
  if (fa != fb)                   // 若上级不同
  {
    z[fa] = fb; // 建立从属关系
  }
}
int main() {
  int j, n, m, u, v, i, sum;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (i = 1; i <= n; i++) // 初始化，自己为自己的老大
    {
      z[i] = i;
    }
    memset(drg, 0, sizeof(drg));
    for (i = 1; i <= m; i++) // 输入关系
    {
      scanf("%d%d", &u, &v);
      drg[u]++;   /// 记录第u节点的度数
      drg[v]++;   /// 记录v节点的度数
      join(u, v); /// 将其归并为一个联通的图
    }
    int boss = find(v);
    bool flag = false;
    for (j = 1; j <= n; j++) /// 遍历所有节点
    {
      if (find(j) != boss) /// 如果每个节点的老大为同一个，则确认为连通图
      {
        printf("Graph is not connected!\n");
        flag = true;
        break;
      }
    }
    if (flag)
      continue;
    int path = 0, cir = 0;
    for (i = 1; i <= n; i++) /// 如果确认为连通图，判断所有节点的入度出度
    {
      if (drg[i] % 2 == 0) /// 作为欧拉回路，是所有节点度数都为2
      {
        cir++;
      } else /// 如果是奇数节点度数恰好为2个，则是欧拉通路
      {
        path++;
      }
    }
    if (path == 2)
      printf("have Euler path\n");
    else if (cir == n)
      printf("have Euler Circuit\n");
    else
      printf(
          "have no Euler path\n"); /// 最后判断两计数器的大小，如果都不符合条件则不是任何欧拉路
  }
  return 0;
}
