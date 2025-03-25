#include <algorithm>
#include <stdio.h> ///最短路模板
#include <string.h>
using namespace std;
int maps[1008][1009];
int dist[1008];
bool vis[1008];
int t, n;
void dijkstra(int s, int n) {
  int i, j;
  memset(dist, 0x3f,
         sizeof(dist)); /// 永远记住，memset初始化最大值，是0x3f不是0x7f
  memset(vis, false, sizeof(vis));
  for (i = 1; i <= n; i++) {
    dist[i] = maps[s][i];
  }
  dist[s] = 0;
  vis[s] = true;
  for (i = 2; i <= n; i++) {
    int minn = 0x7fffffff, mini;
    for (j = 1; j <= n; j++) {
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
}
int main() {
  while (scanf("%d%d", &t, &n) != EOF) {
    int i, j, dis;
    memset(maps, 0x3f, sizeof(maps));
    while (t--) {
      scanf("%d%d%d", &i, &j, &dis);
      if (maps[i][j] > dis)
        maps[i][j] = maps[j][i] = dis;
    }
    dijkstra(1, n);
    printf("%d\n", dist[n]);
  }
  return 0;
}
