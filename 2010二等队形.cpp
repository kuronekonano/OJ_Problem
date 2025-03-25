#include <stdio.h> ///变形最长递减子序列。dp
#include <string.h>
int main() {
  int a[1005], dp[1008], n, i, j;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    memset(dp, 0, sizeof(dp)); /// 记得清空
    dp[0] = 1;
    int flag;
    for (i = 1; i < n; i++) {
      flag = dp[i];
      for (j = 0; j < i; j++) {
        if (a[i] < a[j] &&
            flag < dp[j]) /// 最后错误，这里不小心把dp数组打成了a数组
        {
          flag = dp[j];
        }
      }
      dp[j] = flag + 1;
    }
    int maxn = dp[0];
    for (i = 0; i < n; i++) /// 以后用for找最大值吧。毕竟只用遍历一轮
    {
      if (dp[i] > maxn) {
        maxn = dp[i];
      }
    }
    printf("%d\n", n - maxn); /// 最后拿总个数减去最长序列长度即是被删除最小个数
  }
  return 0;
}
