#include <math.h>
#include <stdio.h>
#include <string.h>
int main() {
  int n, i;
  double a[105];
  while (scanf("%d", &n) != EOF) {
    memset(a, 0, sizeof(a));
    double sum = 0;
    for (i = 1; i <= n; i++) {
      scanf("%lf", &a[i]);
      sum += a[i];
    }
    sum = sum / n;
    double num = 0;
    for (i = 1; i <= n; i++) {
      a[i] = (a[i] - sum) * (a[i] - sum);
      num += a[i];
    }
    double ans = sqrt(num / n);
    printf("%.4f\n", ans);
  }
  return 0;
}
