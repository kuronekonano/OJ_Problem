#include <stdio.h>
int main() {
  int t, n, a[1005];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    double sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      sum = sum + a[i];
    }
    double avg = sum / (double)n;
    int flag = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] > avg) {
        flag++;
      }
    }
    printf("%.3lf%%\n", (double)flag / (double)n * (double)100);
  }
  return 0;
}
