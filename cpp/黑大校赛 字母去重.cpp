#include <stdio.h>
#include <string.h>
int main() {
  char str[1008][1008];
  bool vis[280];
  int t, n, i, j, cas = 1;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%s", str[i]);
    }
    memset(vis, false, sizeof(vis));
    printf("Case #%d: ", cas++);
    for (i = 0; i < n; i++) {
      int len = strlen(str[i]);
      for (j = 0; j < len; j++) {
        if (!vis[str[i][j] - 'A']) {
          vis[str[i][j] - 'A'] = true;
          printf("%c", str[i][j]);
        }
      }
      printf("%c", i == n - 1 ? '\n' : ' ');
      memset(vis, false, sizeof(vis));
    }
  }
  return 0;
}
