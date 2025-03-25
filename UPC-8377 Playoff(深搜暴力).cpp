#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 20;
int n, k, ans, n2;
int won[maxn], def[maxn];
int mp[maxn][maxn];
void dfs(int x, int y) {
  for (int i = 1; i <= n; i++)
    if (won[i] > n2 || def[i] > n2)
      return;
  if (x > n) {
    //        for(int i=1; i<=n; i++)
    //            for(int j=1; j<=n; j++)
    //                printf("%d%c",mp[i][j],j==n?'\n':' ');
    //        printf("==============================\n");
    for (int i = 1; i <= n; i++)
      if (won[i] != n2 || def[i] != n2)
        return;
    ans++;
    return;
  }
  if (x == y)
    return;
  if (mp[x][y] == 0) {
    won[x]++;
    def[y]++;
    mp[x][y] = 1;
    mp[y][x] = -1;
    dfs(y == x - 1 ? x + 1 : x, y == x - 1 ? 1 : y + 1);
    mp[x][y] = mp[y][x] = 0;
    won[x]--;
    def[y]--;

    def[x]++;
    won[y]++;
    mp[x][y] = -1;
    mp[y][x] = 1;
    dfs(y == x - 1 ? x + 1 : x, y == x - 1 ? 1 : y + 1);
    mp[x][y] = mp[y][x] = 0;
    def[x]--;
    won[y]--;
  } else
    dfs(y == x - 1 ? x + 1 : x, y == x - 1 ? 1 : y + 1);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    if (!n)
      return 0;
    else
      scanf("%d", &k);
    n2 = n >> 1;
    M(won, 0);
    M(def, 0);
    M(mp, 0);
    ans = 0;
    bool flag = false;
    int x, y;
    while (k--) {
      scanf("%d%d", &x, &y);
      if (!mp[x][y]) {
        mp[x][y] = 1;
        mp[y][x] = -1;
        won[x]++;
        def[y]++;
      }
      if (won[x] > n2 || def[y] > n2)
        flag = true;
    }
    if (!flag) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (i == j)
            continue;
          if (won[x] == n2)
            for (int i = 1; i <= n; i++)
              if (mp[x][i] == 0 && x != i) {
                mp[x][i] = -1;
                mp[i][x] = 1;
                won[i]++;
                def[x]++;
              }
          if (def[y] == n2)
            for (int i = 1; i <= n; i++)
              if (mp[y][i] == 0 && y != i) {
                mp[y][i] = 1;
                mp[i][y] = -1;
                def[i]++;
                won[y]++;
              }
        }
      }
      dfs(2, 1);
    }
    printf("%d\n", ans);
  }
}
