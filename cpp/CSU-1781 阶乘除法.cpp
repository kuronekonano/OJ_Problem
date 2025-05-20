#include <stdio.h> ///从较小的数开始阶乘，从1往下，到2往下，到3往下，直到到某个数i往下乘到j时等于n的
int main() {
  int i, j, cas = 1;
  long long n;
  while (scanf("%lld", &n) != EOF) {
    if (n == 1) {
      printf("Case %d: Impossible\n", cas++); /// 1是唯一一个特判
      continue;
    }
    bool flag = false;
    for (i = 1; i <= 35000; i++) {
      long long sum = 1;
      for (j = i; j >= 2; j--) {
        sum *= j;
        if (sum == n) {
          flag = true;
          j--;
          break;
        }
        if (sum > n)
          break;
      }
      if (flag)
        break;
    }
    if (flag) {
      printf("Case %d: %d %d\n", cas++, i, j);
    } else {
      printf(
          "Case %d: %lld %lld\n", cas++, n,
          n - 1); /// 当没有任何一个数符合时，是最糟糕的情况，此时必有n/n-1的阶乘符合n值
    }
  }
  return 0;
}
