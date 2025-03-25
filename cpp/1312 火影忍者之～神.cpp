#include <stdio.h>
#include <string.h>
int main() {
  char a[108][102];
  int n, i, j, num, maxn, maxi;
  while (scanf("%d", &n) != EOF) {
    num = 0;
    maxn = 0;
    for (i = 0; i < n; i++) {
      scanf("%s", &a[i]);
      int y = 0, h = 0, len = strlen(a[i]);
      for (j = 0; j < len; j++) {
        if (a[i][j] == 'y')
          y++;
        if (a[i][j] == 'h')
          h++;
      }
      if (y < 2 * h) {
        num = y / 2;
      } else if (y >= 2 * h) {
        num = h;
      }
      if (num > maxn) {
        maxn = num;
        maxi = i;
      }
    }
    printf("%s\n", a[maxi]);
  }
  return 0;
}
