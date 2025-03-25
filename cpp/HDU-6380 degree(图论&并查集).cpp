#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 2e5 + 10;
int t, n, m, k;
int cnt[maxn], z[maxn];
int finds(int x) { return z[x] == x ? x : z[x] = finds(z[x]); }
void join(int a, int b) {
  int fa = finds(a), fb = finds(b);
  if (fa != fb)
    z[fa] = fb;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    LL a, b, ans = 0;
    memset(cnt, 0, sizeof cnt);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
      scanf("%I64d%I64d", &a, &b);
      cnt[a]++;
      cnt[b]++;
      join(a, b);
    }
    if (k >= m) {
      printf("%d\n", n - 1);
      continue;
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
      if (cnt[i] > mx)
        mx = cnt[i];
      if (z[i] == i)
        ans++;
    }
    if (k >= m - mx) {
      printf("%I64d\n", n - 1);
      continue;
    } else
      ans += mx + k - 1;
    printf("%I64d\n", ans);
  }
}
