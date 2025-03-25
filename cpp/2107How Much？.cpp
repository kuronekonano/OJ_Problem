#include <stdio.h>
int main() {
  int t, n, num;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &num);
    scanf("%d", &n);
    int sum = 0, flag, price;
    for (int i = 1; i <= n; i++) {
      scanf("%d %d", &flag, &price);
      sum = sum + flag * price;
    }
    printf("%d\n", sum + num);
  }
  return 0;
}
