#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 7;
int tre[maxn << 4][2]; /// 字典树和VIS数组都必须开到数据范围的16倍以上
LL vis[maxn << 4];
int t, n, m, tot;
LL tmp, s;
void insert(LL a, int rt) {
  for (int i = 32; i >= 0; i--) {
    int x = (a >> i) & 1;
    if (!tre[rt][x]) {
      tre[rt][x] = ++tot;
      memset(tre[tre[rt][x]], 0, sizeof tre[tre[rt][x]]);
    }
    rt = tre[rt][x];
  }
  vis[rt] = a;
}
LL finds(LL a, int rt) {
  for (int i = 32; i >= 0; i--) {
    int x = (a >> i) & 1;
    if (tre[rt][!x])
      rt = tre[rt][!x];
    else
      rt = tre[rt][x];
  }
  return vis[rt];
}
int main() {
  int cas = 0;
  scanf("%d", &t);
  while (t--) {
    tot = 0;
    int rt = ++tot;
    memset(tre[rt], 0, sizeof tre[rt]);
    memset(vis, 0, sizeof vis);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
      scanf("%lld", &tmp), insert(tmp, rt);
    printf("Case #%d:\n", ++cas);
    while (m--) {
      scanf("%lld", &s);
      LL ans = finds(s, rt);
      printf("%lld\n", ans);
    }
  }
}
