#include <stdio.h> ///暴力枚举
int main() {
  int a[21], i, j, n, k, M = 0;
  long long max;
  while (scanf("%d", &n) != EOF) {
    M++;
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    max = 0;
    long long
        sum; /// 从第一个阶乘到最后一个，因为是求连续的乘积最大，因此可以这样连续的相乘
    for (
        i = 0; i < n;
        i++) /// 如1到5，从1到2到3到4到5中选取max，再从2到5，选取最大值，这样每一段连续的数字都选取乘积最大值，最终就是连续乘积最大值
    {
      sum = a[i];
      if (sum >
          max) /// 此处为防止单独为1个数的情况，比较当前首位数字（a[0]）的乘积于max初始化的乘积0,
      {
        max = sum;
      }
      for (j = i + 1; j < n; j++) {
        sum = sum * a[j];
        if (sum > max) {
          max = sum;
        }
      }
    }
    printf("Case #%d: The maximum product is %lld.\n\n", M, max);
  }
  return 0;
}
