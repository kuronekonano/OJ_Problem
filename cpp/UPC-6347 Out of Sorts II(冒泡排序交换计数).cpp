#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct node {
  int val, pos;
} a[maxn];
int n;
bool cmp(node a, node b) {
  if (a.val == b.val)
    return a.pos < b.pos;
  return a.val < b.val;
}
int main() {
  bool vis[maxn];
  while (scanf("%d", &n) != EOF) {
    int tmp = 0, ans = 1;
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i].val), a[i].pos = i;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
      if (a[i].pos > i)
        tmp++;
      if (vis[i])
        tmp--;
      vis[a[i].pos] = true;
      ans = ans > tmp ? ans : tmp;
    }
    printf("%d\n", ans);
  }
}
