#include <stdio.h>
int main() {
  int i, n;
  scanf("%d", &n);
  for (i = 0; i <= n; i++) {
    if ((i % 7 == 0) && (i / 1000 == 7)) {
      printf("%d\n", i);
    } else if ((i % 7 == 0) && (i / 10 % 10 == 7)) {
      printf("%d\n", i);
    } else if ((i % 7 == 0) && (i % 10 == 7)) {
      printf("%d\n", i);
    } else if ((i % 7 == 0) && (i / 100 % 10 == 7)) {
      printf("%d\n", i);
    }
  }
  return 0;
}
