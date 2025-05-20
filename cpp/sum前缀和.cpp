#include <stdio.h>
#include <string.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int i, m, n, a, sum = 0;
    bool vis[5005], flag = false;
    memset(vis, false, sizeof(vis));
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) /// 输入
    {
      scanf("%d", &a);
      sum = sum + a; /// 求和
      sum = sum % m; /// 求模
      if (vis[sum]) /// 如果当前求模的结果，在之后还出现了，说明模一样，那么说明存在倍数关系
      {
        flag = true; /// 存在倍数关系标记
      }
      vis[sum] = true; /// 不能直接break，是一边输入一遍找的
    }
    printf(flag || vis[0] ? "YES\n" : "NO\n");
  }
  return 0;
}
