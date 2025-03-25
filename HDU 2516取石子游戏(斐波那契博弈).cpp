#include <stdio.h> ///ì³²¨ÄÇÆõ²©ÞÄ
int main() {
  long long a[220], n, t, i;
  while (scanf("%I64d", &n) && n) {
    if (n <= 1) {
      printf("First win\n");
      continue;
    }
    if (n > 1 && n <= 3) {
      printf("Second win\n");
      continue;
    }
    a[1] = 2;
    a[2] = 3;
    bool flag = true;
    for (i = 3; a[i - 1] <= n; i++) {
      a[i] = a[i - 1] + a[i - 2];
      if (n == a[i]) {
        printf("Second win\n");
        flag = false;
        break;
      }
      if (a[i] > n)
        break;
    }
    if (flag)
      printf("First win\n");
  }
  return 0;
}
