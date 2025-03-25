#include <bits/stdc++.h>
#define M(a, b) memset(a, b, sizeof(a))
#define pb(x) push_back(x)
using namespace std;
typedef long long LL;
const int maxn = 50000 + 5;
const LL mod = 1000000007;
bool g[30][30];
int color[30];
bool flag;
int n, m;
bool dfs(int cnt, int colo) {
  if (flag)
    return true;
  if (cnt == n) {
    for (int i = 0; !flag && i < n; ++i)
      for (int j = 0; j < i; j++)
        if (color[i] == color[j] && g[cnt][i])
          return false;
    return true;
  }
  for (int i = 0; !flag && i < n; ++i)
    if (color[i] == colo && g[cnt][i])
      return false;
  for (int i = 1; i <= 3; i++) {
    color[cnt + 1] = i;
    if (dfs(cnt + 1, i))
      return true;
    color[cnt + 1] = 0;
  }
  return false;
}
int main() {

  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    M(g, 0);
    M(color, 0);
    for (int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u][v] = g[v][u] = true;
    }
    flag = false;
    for (int i = 1; !flag && i <= 3; i++)
      color[0] = i, flag = dfs(0, i), color[0] = 0;
    puts(flag ? "Y" : "N");
  }
  return 0;
}
/*
9
4
6
1 2
2 3
0 1
0 2
0 3
1 3

6
11
2 3
0 3
0 5
0 2
2 5
5 3
5 1
1 2
2 4
1 4
1 3
*/
