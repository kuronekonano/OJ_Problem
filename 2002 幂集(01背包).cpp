#include <stdio.h> ///和1541的 集合划分 是一样的，把数字当一个物品，然后01背包
#include <string.h>
int main() {
  int a[39], i, j, x, n,
      dp[9005]; /// 有30个数，每个数不超过300，dp的单位是数值大小，因此最大值是9000
  while (scanf("%d%d", &n, &x) != EOF) {
    int sum = 0; /// 这里所求的子集数量，其实就是所有元素能加和得到方法数
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      sum += a[i]; /// 求的最大dp值
    }
    memset(dp, 0, sizeof(dp)); /// 记得清空
    dp[0] =
        1; /// 当求和为0时，只有空集是这样的，所以只有1个子集(输入的元素大于0)
    for (i = 0; i < n; i++) {
      for (j = sum; j >= a[i]; j--) {
        dp[j] = dp[j] + dp[j - a[i]];
      }
    }
    printf("%d\n", dp[x]); /// 只需要当总和为x时的方法数
  }
  return 0;
}
