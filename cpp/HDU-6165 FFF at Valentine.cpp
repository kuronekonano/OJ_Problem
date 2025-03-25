#include <stdio.h>
#include <string.h>
using namespace std;
bool vis[1008][1005];
int x[6002], y[6002];
int main() {
  int t, i, j, n, m;
  scanf("%d", &t);
  while (t--) {
    memset(vis, false, sizeof(vis));
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
      scanf("%d%d", &x[i], &y[i]);
      vis[y[i]][x[i]] = true;
      for (j = 1; j <= n; j++) {
        if (vis[x[i]][j])
          vis[y[i]][j] = true;
        if (vis[j][y[i]])
          vis[j][x[i]] = true;
      }
    }
    for (i = 1; i <= m; i++)
      for (j = 1; j <= n; j++) {
        if (vis[x[i]][j])
          vis[y[i]][j] = true;
        if (vis[j][y[i]])
          vis[j][x[i]] = true;
      }
    //        for(i=1; i<=n; i++)
    //            for(j=1; j<=n; j++)
    //                printf("%d%c",vis[i][j],j==n?'\n':' ');
    bool ans = true;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        if (i == j)
          continue;
        if (!vis[i][j] && !vis[j][i]) {
          ans = false;
          break;
        }
      }
      if (!ans)
        break;
    }
    printf("%s\n",
           ans ? "I love you my love and our love save us!" : "Light my fire!");
  }
}
