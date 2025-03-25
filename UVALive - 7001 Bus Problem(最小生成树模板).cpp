#include <stdio.h> ///最小生成树模板题
#include <string.h>
#define pppp printf("----------\n");
int ma[1005][1005], dist[1005], m, n;
bool vis[1002];
int prim() {
  memset(vis, false, sizeof(vis));
  memset(dist, 0x3f, sizeof(dist));
  vis[0] = true;
  int minn, mini, sum = 0;
  for (int i = 1; i < n; i++)
    dist[i] = ma[0][i]; /// 更新从0节点到达每个节点的距离
  for (int i = 1; i < n; i++) {
    int minn = 0x7fffffff; /// 每次从未标记节点中选择最小值加入到最小生成树中
    int mini = -1;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && dist[j] < minn) {
        minn = dist[j];
        mini = j;
      }
    }
    sum += minn; /// 最小生成树总长求和
    vis[mini] = true;
    for (int j = 0; j < n; j++)
      if (!vis[j] && ma[mini][j] < dist[j])
        dist[j] = ma[mini][j]; /// 利用新加入的节点更新剩下所有节点的到达距离
  }
  return sum;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, y, val, total = 0;
    memset(ma, 0x3f, sizeof(ma)); /// 地图未连通部分全部设成长度无限大，表示不通
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &x, &y, &val);
      ma[x][y] = val;
      ma[y][x] = val;
      total += val;
    }
    int ans = total - prim();
    printf("%d\n", ans);
  }
}
