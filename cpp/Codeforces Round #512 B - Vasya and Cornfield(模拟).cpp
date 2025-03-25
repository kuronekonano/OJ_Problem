#include <bits/stdc++.h> ///模拟斜向矩形画图100*100暴力
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1e5 + 7;
int n, d, t;
bool vis[108][108];
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 0; i < d; i++)
    for (int j = 0; j < d - i; j++)
      vis[i][j] = true;
  for (int i = n; i > n - d; i--)
    for (int j = n; j > n - d + (n - i); j--)
      vis[i][j] = true;
  for (int i = 0; i <= n - d; i++)
    for (int j = n; j > d + i; j--)
      vis[i][j] = true;
  for (int i = d + 1; i <= n; i++)
    for (int j = 0; j < i - d; j++)
      vis[i][j] = true;
  //    for(int i=0;i<=n;i++)
  //        for(int j=0;j<=n;j++)printf("%d%c",vis[i][j],j==n?'\n':' ');
  scanf("%d", &t);
  int x, y;
  while (t--) {
    scanf("%d%d", &x, &y);
    printf("%s\n", vis[x][y] ? "NO" : "YES");
  }
}
