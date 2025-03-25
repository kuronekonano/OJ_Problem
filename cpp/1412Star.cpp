#include <stdio.h>
int main() {
  int n, i;
  while (scanf("%d", &n) != EOF) // 第一个图形只有一个
  {
    int sum = 1; // 第二个图型外围增加了12个
    for (i = 2; i <= n; i++) {
      sum = sum + (i - 1) * 12;
    }
    printf("%d\n", sum);
  }
  return 0;
}
