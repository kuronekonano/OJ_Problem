#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 3e3 + 10;
int main() {
  int n, x, a[55], sum[55];
  LL dp[55][maxn];
  while (scanf("%d%d", &n, &x) != EOF) {
    sum[0] = 0;
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++)             /// 用第i个数更新1~i
      for (int j = i; j >= 1; j--)           /// 长度为1~i个数
        for (int k = sum[i]; k >= a[i]; k--) /// 求和为k
          dp[j][k] += dp[j - 1][k - a[i]];
    LL ans = 0;
    for (int i = 1; i <= n; i++)
      ans += dp[i][i * x];
    printf("%lld\n", ans);
  }
}
