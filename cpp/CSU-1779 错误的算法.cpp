#include <algorithm> ///两种算法的最大值，减去交点的值再比较
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  int i, j, n, m, maxn, vis[508][508], cas = 1;
  while (scanf("%d%d", &n, &m) != EOF) {
    maxn = 0;
    int ii, jj;
    for (i = 1; i <= n; i++) /// 输入&行最大
    {
      vis[i][0] = 0;
      for (j = 1; j <= m; j++) {
        scanf("%d", &vis[i][j]);
        vis[i][0] += vis[i][j];
      }
      if (vis[i][0] > maxn) {
        maxn = vis[i][0];
        ii = i;
      }
    }
    int maxl = 0;
    for (j = 1; j <= m; j++) /// 列最大
    {
      vis[0][j] = 0;
      for (i = 1; i <= n; i++) {
        vis[0][j] += vis[i][j];
      }
      if (vis[0][j] > maxl) {
        maxl = vis[0][j];
        jj = j;
      }
    }
    maxn = maxn + maxl - vis[ii][jj];
    int maxx = 0;
    for (i = 1; i <= n; i++) /// 正确算法
    {
      for (j = 1; j <= m; j++) {
        vis[i][j] = vis[i][0] + vis[0][j] - vis[i][j];
        if (vis[i][j] > maxx)
          maxx = vis[i][j];
      }
    }
    //        printf("%d %d\n",maxn,maxx);
    if (maxn == maxx) {
      printf("Case %d: Weak\n", cas++);
    } else {
      printf("Case %d: Strong\n", cas++);
    }
  }
  return 0;
}
