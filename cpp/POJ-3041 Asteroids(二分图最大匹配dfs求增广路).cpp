#include <stdio.h>  ///二分图最大匹配   最小点覆盖数=最大匹配数
#include <string.h> ///将行和列转化成点，每个点转化为连接两边的线，构成一个二分图，要求最小射击次数，即覆盖所有的边(被抽象成边的点)，用最小的点(被抽象成点的行列)覆盖来实现
int match[505];     ///
bool edge[505][505],
    vis[505]; /// edge存图，表示在第i行j列是否有点存在，vis标记是否询问过某个点
int n, k;
bool KM(int x) /// DFS求增广路
{
  for (int i = 1; i <= n; i++) /// 遍历能与该点配对的点
  {
    if (!vis[i] && edge[x][i]) {
      vis[i] = true; /// 标记访问点
      if (match[i] == 0 || KM(match[i])) {
        match[i] = x; /// 更新配对关系
        return true;
      }
    }
  }
  return false; /// 若遍历了所有点
}
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    int x, y;
    memset(edge, false, sizeof(edge));
    memset(match, 0, sizeof(match));
    for (int i = 0; i < k; i++) {
      scanf("%d%d", &x, &y);
      edge[x][y] =
          true; /// 这里行和列是不同的，第一行配对第三列和第三行配对第一列是两个点，因此是无向图
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      memset(vis, false, sizeof(vis));
      if (KM(i))
        sum++; /// 增广路计数结果即是最大匹配数量
    }
    printf("%d\n", sum);
  }
}
