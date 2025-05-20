#include <algorithm>
#include <stack>
#include <stdio.h>
#include <string.h> ///有向无环图DAG   求缩点
using namespace std;
int n, low[108], dfn[108], cnt, out, in, num,
    id[108]; /// low数组用于存储最小出生时间，id存储节点属于哪个强连通图
bool maps[108][108],
    vis[108]; /// maps用于邻接矩阵构造连通图，vis用于标记节点是否在栈中
stack<int> q;
void tarjan(int u) /// tarjan算法
{
  int i;
  low[u] = dfn[u] = ++cnt;
  q.push(u);     /// 入栈
  vis[u] = true; /// 标记u节点在栈中
  for (i = 1; i <= n; i++) {
    if (!maps[u][i])
      continue;
    if (!dfn[i]) {
      tarjan(i);
      low[u] = min(low[u], low[i]);
    } else if (vis[i]) /// 注意这里是在栈中的点才用于更新u几点low值
    {
      low[u] = min(low[u], dfn[i]);
    }
  }
  if (low[u] == dfn[u]) /// 判断强连通图的条件，当low值等于dfu值时，说明此时为
                        /// 深搜子树的根节点
  {
    num++;             /// 强联通图个数计数
    while (!q.empty()) /// 此时栈中存储的是强联通图的所有节点
    {
      int tmp = q.top();
      q.pop(); /// 出栈时应该取消节点的标记
      id[tmp] = num;
      vis[tmp] = 0; /// 取消标记
      if (tmp ==
          u) /// 直到寻找到栈顶中的点tmp等于正在遍历的点u时，这个强联通图的所有点寻找完毕
      {
        break;
      }
    }
  }
}
int main() {
  int i, inum[108], outnum[108], j;
  while (scanf("%d", &n) != EOF) {
    memset(vis, false, sizeof(vis));
    memset(maps, false, sizeof(maps));
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    memset(inum, 0, sizeof(inum));
    memset(outnum, 0, sizeof(outnum));
    memset(id, 0, sizeof(id));
    while (!q.empty())
      q.pop();
    cnt = out = in = num = 0;
    for (i = 1; i <= n; i++) {
      int u;
      while (scanf("%d", &u) && u) {
        maps[i][u] = true;
      }
    }
    for (i = 1; i <= n; i++) /// 求缩点，也就是强联通分量个数
    {
      if (!dfn[i]) {
        tarjan(i); /// 这里要遍历所有点，因为这个图不一定是所有点的都连通的
      }
    } /// 深搜完后，就已经找到了所有强联通分量了
    //        for (i=1; i<=n; ++i)
    //            printf("%3d",id[i]);
    //        puts("");
    for (i = 1; i <= n; i++) /// 这里对每个点的连接进行遍历
    {
      for (j = 1; j <= n; j++) {
        if (maps[i][j] &&
            id[i] != id[j]) /// 如果两点有连接，并且i点与j点不属于一个强联通分量
        {
          inum[id[j]]++;   /// j点作为入度，相当于i所在的强联通分量 有方向的
                           /// 走向j所在强联通分量
          outnum[id[i]]++; /// i是出度
        }
      } /// 这里进行所有的强联通分量的入度和出度计数，第i个强联通分量的入度在inum数组中,出度位于outnum数组中
    }
    for (i = 1; i <= num;
         i++) /// 最后统计一下，所有强联通分量的0入度和0出度的个数
    {
      if (!inum[i])
        in++;
      if (!outnum[i])
        out++;
    }
    if (num ==
        1) /// 如果整个图只有一个强联通分量，那么就只有一个出度为0和一个入度为0的点
    {
      printf("1\n0\n"); /// 要特判，只用发一个软件即可，并且不用加边
    } else {
      printf(
          "%d\n%d\n", in,
          max(in,
              out)); /// 否则就是，发放软件数量是0入度的点的数量(根节点)，需要加的边数，则是将0入度的连接0出度的，谁大结果就是几条边
    }
  }
  return 0;
}
