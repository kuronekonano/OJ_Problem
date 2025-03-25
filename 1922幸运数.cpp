#include <stdio.h>
int a[10] = {1,   1,   2,    6,     24,
             120, 720, 5040, 40320, 362880}; /// 0的阶乘特么竟然是1
int main() {
  int i, j;
  for (i = 1; i <= 214700; i++) {
    long sum = 0;
    long x = i;
    while (x) {
      sum = sum + a[x % 10];
      x = x / 10;
    }
    if (sum == i) {
      printf("%d\n", i);
    }
  }
  return 0;
}
