#include <stdio.h> ///二分图最大匹配
#include <string.h>
int match[505];
bool edge[505][505],
    vis[505]; /// edge存图，表示在i是否能装下j盒子，vis标记是否询问过某个点
int n, k;
bool KM(int x) /// DFS求增广路(求每个盒子所能对应的匹配，能被谁装进去)
{
  for (int i = 1; i <= n; i++) /// 遍历能装下x编号的盒子
  {
    if (!vis[i] && edge[x][i]) {
      vis[i] = true; /// 标记访问点
      if (match[i] == 0 || KM(match[i])) {
        match[i] = x; /// 更新配对关系
        return true;
      }
    }
  }
  return false; /// 若遍历了所有点仍未找到盒子装下，这个盒子裸露在外
}
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    int x, y;
    memset(edge, false, sizeof(edge));
    memset(match, 0, sizeof(match));
    for (int i = 0; i < k; i++) {
      scanf("%d%d", &x, &y);
      edge[x][y] =
          true; /// 这里x盒子能被y盒子装下，不表示y盒子能被x盒子装下，也就是有向图
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      memset(vis, false, sizeof(vis));
      KM(i);
    }
    for (int i = 1; i <= n; i++)
      if (match[i] == 0)
        sum++; /// 最后计数没有被装下，没有配对的盒子个数
    printf("%d\n", sum);
  }
}
