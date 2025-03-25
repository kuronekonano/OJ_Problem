#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1e5 + 7;
int n, m, a[maxn], sum, pos[maxn];
struct node {
  int l, r, id;
  bool operator<(const node &a) const {
    return pos[l] == pos[a.l] ? r < a.r : pos[l] < pos[a.l];
  }
} q[maxn];
int cnt[maxn], ans[maxn];
void add(int x) {
  if (a[x] > n)
    return;
  if (cnt[a[x]] == a[x])
    sum--;
  cnt[a[x]]++;
  if (cnt[a[x]] == a[x])
    sum++;
}
void del(int x) {
  if (a[x] > n)
    return;
  if (cnt[a[x]] == a[x])
    sum--;
  cnt[a[x]]--;
  if (cnt[a[x]] == a[x])
    sum++;
}
int main() {
  sum = 0;
  scanf("%d%d", &n, &m);
  int sz = sqrt(n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), pos[i] = i / sz;
  for (int i = 1; i <= m; i++)
    scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
  sort(q + 1, q + m + 1);
  M(cnt, 0);
  int L = 1, R = 0;
  for (int i = 1; i <= m; i++) {
    while (L < q[i].l)
      del(L++);
    while (L > q[i].l)
      add(--L);
    while (R < q[i].r)
      add(++R);
    while (R > q[i].r)
      del(R--);
    ans[q[i].id] = sum;
  }
  for (int i = 1; i <= m; i++)
    printf("%d\n", ans[i]);
}
