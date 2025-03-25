#include <stdio.h>
int main() {
  int a, b, c, d, e;
  while (scanf("%d%d%d%d%d", &a, &b, &c, &d, &e) != EOF) {
    if ((a + b + c + d + e) % 5 == 0) {
      if ((a + b + c + d + e) / 5 == 0) /// ×¢Òâ¿´Ìâ£¬b>0
      {
        printf("-1\n");
      } else {
        printf("%d\n", (a + b + c + d + e) / 5);
      }
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
