#include <math.h>
#include <stdio.h>
int main() {
  int t, i, n, b;
  double tmp;
  char a[4];
  scanf("%d", &t);
  while (t--) {
    scanf("%d %s", &n, a);
    double sum = 0;
    if (a[0] == 'b')
      b = 2;
    if (a[0] == 'd')
      b = 10;
    if (a[0] == 'n') {
      for (i = 1; i <= n; i++) {
        scanf("%lf", &tmp);
        if (tmp == 0)
          continue;
        sum += (tmp / 100) * (log(tmp / 100));
      }

    } else {
      for (i = 1; i <= n; i++) {
        scanf("%lf", &tmp);
        if (tmp == 0)
          continue;
        sum += (tmp / 100) * (log(tmp / 100) / log(b));
      }
    }
    printf("%.12f\n", -sum);
  }
}
