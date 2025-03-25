#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int t, i, j, n, m, dp[108], a[108];
  scanf("%d", &t);
  while (t--) {
    memset(a, 0, sizeof(a));
    memset(dp, 0, sizeof(dp));
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (i != 1)
        dp[i] = a[i] ^ dp[i - 1];
      else
        dp[i] = a[i];
    }
    scanf("%d", &m);
    while (m--) {
      int x;
      scanf("%d", &x);
      int ans = 0, dis = 0x3f3f3f3f;
      for (i = n; i >= 1; i--) /// 从n->1就能过，从1->n就超时
      {
        for (j = i - 1; j >= 0; j--) {
          int tmp = dp[i] ^ dp[j];
          if (abs(x - tmp) < dis) {
            ans = i - j;
            dis = abs(x - tmp);
          } else if (abs(x - tmp) == dis && (i - j) > ans)
            ans = i - j;
        }
      }
      printf("%d\n", ans);
    }
    printf("\n");
  }
}
