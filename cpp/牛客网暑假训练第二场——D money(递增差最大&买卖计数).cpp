#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 10;
int n, t;
int a[maxn];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    int ptr = 1;
    LL ans = 0;
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
      if (a[i - 1] > a[i]) {
        ans += a[i - 1] - a[ptr];
        if (a[i - 1] - a[ptr] > 0)
          cnt += 2;
        ptr = i;
      }
      if (i == n && a[i] > a[ptr])
        ans += a[i] - a[ptr], cnt += 2;
    }
    printf("%lld %d\n", ans, cnt);
  }
}
