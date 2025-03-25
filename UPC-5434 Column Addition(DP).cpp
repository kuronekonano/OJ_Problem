#include <bits/stdc++.h>
using namespace std;
const int maxn = 1050;
char a[maxn], b[maxn], c[maxn];
int aa[maxn], bb[maxn], cc[maxn], ax[maxn], dp[maxn], n;
int main() {
  while (scanf("%d", &n) && n) {
    memset(dp, 0, sizeof(dp));
    memset(ax, 0, sizeof(ax));
    scanf("%s %s %s", a, b, c);
    for (int i = 0; i < n; i++) {
      aa[i] = a[i] - '0';
      bb[i] = b[i] - '0';
      cc[i] = c[i] - '0';
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      if ((ax[i] + aa[i] + bb[i]) % 10 == cc[i]) {
        if ((ax[i] + aa[i] + bb[i]) / 10 == 0) {
          dp[i] = 1;
          ans = max(ans, dp[i]); /// 必须更新当前预处理出来的dp长度作为ans
        } else
          dp[i] = 1, ax[i] = 1;
      }
      for (int j = n - 1; j > i; j--) {
        if (aa[i] + bb[i] + ax[j] == cc[i] && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          ans = max(ans, dp[i]);
        }
        if (aa[i] + bb[i] + ax[j] - 10 == cc[i] && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          ax[i] = 1;
        }
      }
    }
    //        for(int i=0;i<n;i++)printf("--%d\n",dp[i]);
    printf("%d\n", n - ans);
  }
}
