#include <stdio.h>
int main() {
  int t, i;
  double n;
  scanf("%d", &t);
  while (t--) {
    scanf("%lf", &n);
    int flag;
    double count = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &flag);
      if (flag)
        count++;
    }
    printf("%.2f\n", count / n);
  }
  return 0;
}
