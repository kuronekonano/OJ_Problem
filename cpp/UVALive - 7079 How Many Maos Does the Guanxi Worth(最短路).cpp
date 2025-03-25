#include <algorithm>
#include <stdio.h> ///最短路
#include <string.h>
using namespace std;
int dist[208];
int maps[208][209];
bool vis[208];
int n, m, flag;
void dijkstra(int s, int t, int die) {
  int i, j;
  memset(vis, false, sizeof(vis));
  memset(dist, 0x3f, sizeof(dist));
  flag = dist[1];
  vis[die] = true;
  for (i = 1; i <= n; i++) /// 所有点到达起点的距离
  {
    dist[i] = maps[s][i];
  }
  dist[s] = 0;             /// 标记起点长度为0
  vis[s] = true;           /// 标记走过
  for (i = 2; i <= n; i++) /// 遍历n-1次
  {
    int minn = 0x7fffffff, mini;
    for (j = 1; j <= n;
         j++) /// 这里是要遍历所有的点，因为不一定是第0个点作为起点
    {
      if (!vis[j] && dist[j] < minn) {
        minn = dist[j];
        mini = j;
      }
    }
    vis[mini] = true;
    for (j = 1; j <= n; j++) {
      dist[j] = min(dist[j], dist[mini] + maps[mini][j]);
    }
  }
  //    for(i=0;i<n;i++)
  //    {
  //        printf("%d\n",dist[i]);
  //    }
}
int main() {
  int i, j, k, x, y, len[60];
  while (scanf("%d%d", &n, &m) != EOF) {
    if (n == 0 && m == 0)
      return 0;
    memset(maps, 0x3f, sizeof(maps)); /// 初始所有路段为无限大(不可到达)
    for (i = 0; i < m; i++)           /// m条路
    {
      scanf("%d%d%d", &x, &y, &k);
      if (k < maps[x][y])
        maps[x][y] = maps[y][x] = k; /// 一直更新为最小路径
    }
    for (i = 2; i <= n - 1; i++) {
      dijkstra(1, n, i);
      len[i] = dist[n];
      //            printf("===%d\n",dist[n]);
    }
    sort(len + 2, len + n);
    if (len[n - 1] == flag) {
      printf("Inf\n");
    } else
      printf("%d\n", len[n - 1]);
  }
  return 0;
}
