#include <stdio.h> ///遍历每一个堆，被遍历过的堆默认是分好的，也就是在不变动数组中存储的数的情况下，对后面的堆做操作
int main()         /// 使当前堆实现平均分后，利用后面堆 的变动来反应情况。
{
  long long
      cas = 0,
      t, i, n, k,
      a[100008]; /// 基本思想就是，当前堆多了，就分给后面的堆来发放出去，因为只能对相邻堆最操作，所以这就是最优操作
  scanf(
      "%lld",
      &t); /// 当前堆少了，后面的堆分一部分给当前堆，后面的堆减去分出来的，不会出现剪成负数堆的情况。
  while (t--) /// 因为这属于前后堆合并后仍小于标准堆的情况
  {
    cas++;
    long long sum = 0;
    scanf("%lld%lld", &n, &k);
    for (i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      sum += a[i];
    }
    if (sum % k != 0) /// 不够均分时，直接输出-1
    {
      printf("Case #%lld: -1\n", cas);
      continue;
    }
    long long avg = sum / k; /// 计算标准堆
    long long ans = 0;
    for (i = 1; i <= n; i++) {
      if (a[i] < avg) {
        if (a[i] + a[i + 1] <= avg) {
          a[i + 1] += a[i];
          ans++;
        } else {
          a[i + 1] -= avg - a[i];
          ans += 2;
        }
      } else {
        long long num =
            a[i] /
            avg; /// 如果当前堆多于标准堆，计算当前堆可以分出几个标准堆，操作数为可分堆数-1
        long long mod =
            a[i] %
            avg; /// 如果有余下的不满足一个标准堆的余数，将其合并到后面的一堆中。
        if (mod != 0) /// 这个操作相当于当前堆小于标准堆时的合并操作.操作数+2
        {
          a[i + 1] += mod;
          ans += 2;
        }
        ans += num - 1;
      }
    }
    printf("Case #%lld: %lld\n", cas, ans);
  }
}
