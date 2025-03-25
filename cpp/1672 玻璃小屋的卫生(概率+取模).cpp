#include <stdio.h>
int main() {
  int n, sum, tmp, num;
  while (scanf("%d", &n) != EOF) {
    sum = 0;
    for (int i = 0; i < n; i++)
      scanf("%d", &tmp), sum += tmp;
    num = 0;
    for (int i = 1; i <= 5; i++)
      if ((sum + i) % (n + 1) != 1)
        num++;
    printf("%.2f\n", num / 5.0);
  }
}
