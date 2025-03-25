#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1e5 + 7;
int n;
LL use[30], rev[30], u[20], r[20], t[20];
int main() {
  for (int i = 1; i <= 10; i++)
    scanf("%lld%lld", &use[i], &rev[i]);
  for (int i = 1; i <= 10; i++)
    scanf("%lld%lld%lld", &u[i], &r[i], &t[i]);
  LL ans = 0;
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 10; j++) {
      if (ans >= t[j]) {
        LL wait = (ans - t[j]) / (u[j] + r[j]);
        t[j] += u[j] + wait * (u[j] + r[j]);
        ans = ans > t[j] ? ans : t[j];
        t[j] += r[j];
      }
      ans += use[j];
      t[j] = t[j] > ans ? t[j] : ans;
      if (i != 3 || j != 10)
        ans += rev[j];
    }
  printf("%lld\n", ans);
}
