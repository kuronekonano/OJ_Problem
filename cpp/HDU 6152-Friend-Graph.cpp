#include <stdio.h>
#include <string.h>
bool a[3005][3005];
int main() {
  int t, i, j, k, n;
  scanf("%d", &t);
  while (t--) {
    memset(a, false, sizeof(a));
    scanf("%d", &n);
    for (i = 1; i <= n - 1; i++) {
      for (j = i + 1; j <= n; j++)
        scanf("%d", &a[i][j]);
    }
    if (n > 6)
      printf("Bad Team!\n");
    else {
      bool flag = false;
      for (i = 1; i <= n - 2; i++) {
        for (j = i + 1; j <= n - 1; j++) {
          for (k = j + 1; k <= n; k++) {
            if (a[i][j] == a[j][k] && a[i][k] == a[i][j]) {
              flag = true;
              break;
            }
          }
          if (flag)
            break;
        }
        if (flag)
          break;
      }
      printf("%s\n", flag ? "Bad Team!" : "Great Team!");
    }
  }
}
