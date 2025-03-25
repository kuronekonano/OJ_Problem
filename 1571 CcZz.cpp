#include <stdio.h>
int main() {
  int i, j, k, n, a[108][105];
  while (scanf("%d", &n) != EOF) {
    int num = a[1][1] = 1;
    for (i = 2; i <= n; i++) {
      if (i % 2 == 0) {
        j = 1, k = i;
        while (k >= 1) {
          a[j++][k--] = ++num;
        }
      } else {
        j = i, k = 1;
        while (j >= 1) {
          a[j--][k++] = ++num;
        }
      }
    }
    for (i = 2; i <= n; i++) {
      if (n % 2 == 0) {
        if (i % 2 != 0) {
          j = i, k = n;
          while (k >= i) {
            a[j++][k--] = ++num;
          }
        } else {
          j = n, k = i;
          while (j >= i) {
            a[j--][k++] = ++num;
          }
        }
      } else {
        if (i % 2 == 0) {
          j = i, k = n;
          while (k >= i) {
            a[j++][k--] = ++num;
          }
        } else {
          j = n, k = i;
          while (j >= i) {
            a[j--][k++] = ++num;
          }
        }
      }
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++)
        printf("%6d", a[i][j]);
      printf("\n");
    }
    printf("\n");
  }
}
