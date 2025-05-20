#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  int t, i, j;
  char a[10005];
  scanf("%d", &t);
  while (t--) {
    scanf("%s", a);
    int dp[10008];
    memset(dp, 0, sizeof(dp));
    int flag;     /// 临时最大值存放，找出当前遍历的字符之前的所有字符的最长长度
    int maxn = 1; /// 最长长度记录，也就是ans
    dp[0] = 1;    /// 第1个字符长度为1
    int n = strlen(a);
    for (i = 1; i < n; i++) {
      flag = dp[i];
      for (j = 0; j < i; j++) {
        if (a[i] > a[j] && dp[j] > flag) {
          flag = dp[j];
        }
      }
      dp[i] = flag + 1;
      maxn = max(maxn, dp[i]);
    }
    printf("%d\n", maxn);
  }
}
