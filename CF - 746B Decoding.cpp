#include <stdio.h>
int main() {
  char a[2008], b[2008];
  int i, j, n;
  while (scanf("%d", &n) != EOF) {
    scanf("%s", a);
    if (n % 2 != 0) {
      b[n / 2] = a[0];
      for (i = 1, j = 1; i < n; i++, j++) {
        b[n / 2 - j] = a[i++];
        b[n / 2 + j] = a[i];
      }
      b[n] = '\0';
      printf("%s\n", b);
    } else {
      n--;
      b[n / 2] = a[0];
      for (i = 1, j = 1; i <= n - 1; i++, j++) {
        b[n / 2 + j] = a[i++];
        b[n / 2 - j] = a[i];
      }
      b[n / 2 + j] = a[i];
      b[n + 1] = '\0';
      printf("%s\n", b);
    }
  }
}
