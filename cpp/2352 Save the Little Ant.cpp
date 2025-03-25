#include <stdio.h>
int main() {
  int a[100005], n;
  while (scanf("%d", &n) != EOF) {
    long long Max = 0, maxi = 0,
              ans = 0; /// 坑点，地平线是0，所以负数都是坑，不管边缘是谁
    for (int i = 0; i < n; i++) /// 最坏情况是2e5*1e5，要用long long
    {
      scanf("%d", &a[i]);
      if (a[i] < 0)
        ans += -a[i],
            a[i] =
                0; /// 找到一个序列中最大值的位置，然后左右向这个最大值的位置扫
      if (a[i] >
          Max) /// 每次更新左右扫进去的最大值，如果大于最大值，更新最大值，否则减去，算坑，这样就把其中一个边界都作为最大值，另一个左右的边界是会更新变化的最大值
      {
        Max = a[i];
        maxi = i;
      }
    } /// 整个序列的最大值不在计算范围内，因为他作为了边界
    int maxx = 0;
    for (int i = 0; i < maxi; i++)
      if (a[i] > maxx)
        maxx = a[i];
      else
        ans += maxx - a[i];
    maxx = 0;
    for (int i = n - 1; i > maxi; i--)
      if (a[i] > maxx)
        maxx = a[i];
      else
        ans += maxx - a[i];
    printf("%lld\n", ans);
  }
}
