#include <stdio.h>
int main() {
  int n, sum;
  while (scanf("%d", &n) != EOF) {
    sum = 0;
    for (int i = 1; i <= n / 2; i++)
      sum += (n - i) * i;
    printf("%d\n", (n & 1) ? sum * 2 + n : sum * 2 + n - (n / 2) * (n / 2));
  }
}
