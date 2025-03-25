#include <stdio.h>
#include <string.h>
int main() {
  long long a[50][50], i, j;
  int n;
  while (scanf("%d", &n) != EOF) {
    memset(a, 0, sizeof(a));
    for (i = 0; i < n; i++) {
      a[0][i] = 1;
      a[i][0] = 1;
    }
    for (i = 1; i < n; i++) {
      for (j = 1; j < n; j++) {
        a[i][j] = a[i - 1][j] + a[i][j - 1];
        if (i == j && i != n - 1) {
          a[i][j] = 0;
        }
      }
    }
    printf("%lld\n", a[n - 1][n - 1]);
  }
  return 0;
}
