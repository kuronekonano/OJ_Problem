#include <stdio.h>
int main() {
  long long n, kuro[55], i;
  while (scanf("%lld", &n) != EOF) {
    kuro[1] = 1; // 和上台阶问题一样，一个方格只能有一种摆法
    kuro[2] = 2; // 而两个方格可以横摆竖摆两种摆法，以此类推，1和2累加摆法
    for (i = 3; i <= n; i++) {
      kuro[i] = kuro[i - 1] + kuro[i - 2];
    }
    printf("%lld\n", kuro[n]);
  }
  return 0;
}
