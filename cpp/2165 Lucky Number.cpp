#include <stdio.h> ///µÝÍÆ
int main() {
  long long one[40], none[35], sum[40];
  int n;
  one[1] = 1;
  none[1] = 2;
  sum[1] = 3;
  while (scanf("%d", &n) != EOF) {
    for (int i = 2; i <= n; i++) {
      one[i] = none[i - 1];
      none[i] = 2 * (none[i - 1] + one[i - 1]);
      sum[i] = none[i] + one[i];
    }
    printf("%lld\n", sum[n]);
  }
  return 0;
}
