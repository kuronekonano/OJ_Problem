#include <stdio.h>
#include <string.h>
bool ma[108][108], vis[105], dvis[105], nvis[105];
int n, m, edge = 0, node = 0, inout[105];
void dfs(int i) {
  node++; /// 如果可以往下搜，记录这个被搜的节点，它属于连通图的一部分
  vis[i] = dvis[i] = true;
  for (int j = 1; j <= n; j++)
    if (ma[i][j] && !vis[j])
      dfs(j);
}
void nfs(int i) {
  node++;
  nvis[i] = true;
  for (int j = 1; j <= n; j++)
    if (ma[i][j] && !nvis[j])
      nfs(j);
}
int main() {
  int t, cas = 0;
  scanf("%d", &t);
  while (t--) {
    memset(vis, false, sizeof(vis));
    memset(ma, false, sizeof(ma));
    memset(inout, 0, sizeof(inout));
    int x, y;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &x, &y);
      ma[x][y] = ma[y][x] = true;
      inout[x]++;
      inout[y]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        node = 0;
        edge = 0;
        memset(dvis, false, sizeof(dvis));
        dfs(i);                      /// 找一个连通图的所有节点，并标记
        for (int j = 1; j <= n; j++) /// 在标记的节点中进行节点数量计数
          if (dvis[j])
            for (int k = 1; k <= n; k++)
              if (ma[j][k])
                edge++; /// 对所有被标记的点，作为这个连通图的一部分，记录这些点连成的边的数量
        edge /= 2;
        if (node & 1)
          continue;
        if (edge ==
            (node / 2) * (node / 2 - 1) +
                1) /// 多边形有n个点，那么就有((n/2-1)*n)/2条边的完全图，这里将node个点分成两份，因此共有node/2*(node/2-1)条边，加上两个哑铃相连的一条边
        {
          int out[2] = {0, 0},
              num = 0; /// 两个点的位置要初始化，否则后果不堪设想！！
          for (int j = 1; j <= n; j++) {
            if (dvis[j] && inout[j] == node / 2) /// 属于当前遍历的小连通图中
            {
              out[num++] = j;
            }
          }
          ma[out[0]][out[1]] = ma[out[1]][out[0]] = false;
          node = 0;
          memset(nvis, false, sizeof(nvis));
          nfs(out[0]);
          if (node == inout[out[0]])
            ans++;
        }
      }
    }
    printf("Case #%d: %d\n", ++cas, ans);
  }
}
