#include <algorithm>
#include <stdio.h> ///最长递增子序列
#include <string.h>
using namespace std;
int main() {
  int dp[1008], a[1008], i, j, n;
  while (scanf("%d", &n) != EOF) {
    memset(dp, 0, sizeof(dp));
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    int maxn = 1;
    int flag;
    dp[0] = 1;
    for (i = 1; i < n; i++) {
      flag = dp[i];
      for (j = 0; j < n; j++) {
        if (a[i] > a[j] && flag < dp[j]) {
          flag = dp[j];
        }
      }
      dp[i] = flag + 1;
      maxn = max(maxn, dp[i]);
    }
    //        for(i=0; i<=n; i++)
    //        {
    //            printf("%d\n",dp[i]);
    //        }
    printf("%d\n", maxn);
  }
  return 0;
}
