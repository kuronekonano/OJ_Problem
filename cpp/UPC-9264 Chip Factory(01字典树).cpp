#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1e3 + 7;
int tre[maxn << 5][2];
int cnt[maxn << 5];
int tot;
void insert(LL a, int rt, int add) {
  for (int i = 31; i >= 0; i--) {
    int x = (a >> i) & 1;
    if (!tre[rt][x]) {
      tre[rt][x] = ++tot;
      M(tre[tre[rt][x]], 0);
    }
    rt = tre[rt][x];
    cnt[rt] += add;
  }
}
LL finds(LL a, int rt) {
  LL ans = 0;
  for (int i = 31; i >= 0; i--) {
    ans <<= 1;
    int x = (a >> i) & 1;
    if (tre[rt][!x] && cnt[tre[rt][!x]])
      rt = tre[rt][!x], ans |= 1;
    else
      rt = tre[rt][x];
  }
  return ans;
}
int t, n;
LL a[1080];
int main() {
  scanf("%d", &t);
  while (t--) {
    LL ans = 0;
    tot = 0;
    int rt = ++tot;
    M(tre[rt], 0);
    M(cnt, 0);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      insert(a[i], rt, 1);
    }
    for (int i = 1; i < n; i++) {
      insert(a[i], rt, -1);
      for (int j = i + 1; j <= n; j++) {
        insert(a[j], rt, -1);
        ans = max(ans, finds(a[i] + a[j], rt));
        insert(a[j], rt, 1);
      }
      insert(a[i], rt, 1);
    }
    printf("%lld\n", ans);
  }
}
