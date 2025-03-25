#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 2e5 + 7;
struct node {
  LL l, r, dis;
} a[maxn], b[maxn];
LL n, h;
LL sum[maxn], fly[maxn];
int main() {
  scanf("%lld%lld", &n, &h);
  sum[0] = sum[1] = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", &a[i].l, &a[i].r);
    a[i].dis = a[i].r - a[i].l;
    if (i != 0) {
      b[i].l = a[i - 1].r;
      b[i].r = a[i].l;
      b[i].dis = b[i].r - b[i].l;
      sum[i] = sum[i - 1] + b[i].dis;
    }
    fly[i] = i == 0 ? a[i].dis : fly[i - 1] + a[i].dis;
  }
  LL ans = 0;
  for (int i = 0; i < n; i++) {
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (sum[mid] - sum[i] >= h)
        r = mid - 1;
      else
        l = mid + 1;
    }
    if (sum[l] - sum[i] >= h)
      l--;
    LL dist = fly[l] - fly[i] + a[i].dis + sum[l] - sum[i];
    dist += h - (sum[l] - sum[i]);
    ans = max(ans, dist);
  }
  printf("%lld\n", ans);
}
