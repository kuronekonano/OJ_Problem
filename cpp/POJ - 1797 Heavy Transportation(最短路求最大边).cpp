#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int dist[1008];
int ma[1008][1008];
bool vis[1008];
int n, m;
void dijkstra(int s) {
  memset(vis, false, sizeof(vis));
  memset(dist, 0, sizeof(dist));
  for (int i = 1; i <= n; i++)
    dist[i] = ma[s][i];
  dist[s] = 0;
  vis[s] = true;
  for (int i = 2; i <= n; i++) {
    int maxn = 0, maxi = 1;
    for (
        int j = 1; j <= n;
        j++) /// 记录和寻找的不再是累加的最短路径，而是dist记录每条路径上经过的最小承重，每次遍历收集到最大承重
    {
      if (!vis[j] && dist[j] > maxn) /// 用最大承重更新路径上可到达的较小承重
      {
        maxn = dist[j];
        maxi = j;
      }
    }
    vis[maxi] = true;
    for (int j = 1; j <= n; j++)
      if (!vis[j] &&
          dist[j] <
              min(maxn,
                  ma[maxi]
                    [j])) /// 注意更新dist的条件，当dist[j]较小时，才能用一个maxn或ma上的较大值来更新
        dist[j] =
            min(maxn,
                ma[maxi][j]); /// 没有这个判断直接赋值会导致dist被更新得越来越小
  }
}
int main() {
  int t, x, y, val, cas = 0;
  scanf("%d", &t);
  while (t--) {
    memset(
        ma, 0,
        sizeof(
            ma)); /// ma中无法到达的点应该被标记为0承重，被标为最大值会导致最大值被直接选用，无法被更新
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &x, &y, &val);
      ma[x][y] = val;
      ma[y][x] = val;
    }
    dijkstra(1);
    printf("Scenario #%d:\n", ++cas);
    printf("%d\n\n", dist[n]); /// 注意额外空行
  }
}
