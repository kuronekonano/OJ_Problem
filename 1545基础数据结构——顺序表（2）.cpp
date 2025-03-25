#include <stdio.h>
int main() {
  int a[1005], i, j, n;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (i > 0) {
        for (j = i - 1; j >= 0; j--) {
          if (a[i] == a[j]) {
            i--;
            n--;
          }
        }
      }
    }
    printf("%d\n", n);
    for (i = 0; i < n; i++) {
      if (i > 0) {
        printf(" %d", a[i]);
      } else {
        printf("%d", a[i]);
      }
    }
    printf("\n");
  }
  return 0;
}
