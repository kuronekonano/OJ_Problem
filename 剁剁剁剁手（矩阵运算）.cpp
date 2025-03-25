#include <stdio.h>
int main() {
  int t, n, m, i, j, a[105][106], b[105][107];
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        scanf("%d", &b[i][j]);
      }
    }
    bool flag = true;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        if (a[i][j] < b[i][j]) {
          flag = false;
          break;
        }
      }
      if (flag == false)
        break;
    }
    if (flag == false)
      printf("NO\n");
    else if (flag == true)
      printf("YES\n");
  }
  return 0;
}
