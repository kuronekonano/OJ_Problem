#include <stdio.h>
int main() {
  int n, i, a, b;
  while (
      scanf("%d%d", &a, &b) !=
      EOF) // 既然用不了pow函数一个一个求次方，就用for循环乘积，每次都取个位，保证不溢出
  {
    n = 1;
    for (i = 1; i <= b; i++) {
      n = n * a;
      n = n % 10;
    }
    printf("%d\n", n);
  }
  return 0;
}
