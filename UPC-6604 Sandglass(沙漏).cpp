#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 10;
LL x, n, q, r[maxn], add[maxn];
int main() {
  scanf("%d%d", &x, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &r[i]);
    if (i == 0)
      add[i] = -r[i];
    else
      add[i] = (i & 1) ? r[i] - r[i - 1] : r[i - 1] - r[i];
  }
  LL ti, a, k = 0;
  scanf("%d", &q);
  int up = x, down = 0, real = 0;
  while (q--) {
    scanf("%lld%lld", &ti, &a);
    while (r[k] <= ti && k < n) {
      real += add[k];
      if (up + add[k] < 0)
        up = 0;
      else if (up + add[k] > x)
        up = x;
      else
        up += add[k];

      if (down + add[k] < 0)
        down = 0;
      else if (down + add[k] > x)
        down = x;
      else
        down += add[k];
      k++;
      //            printf("=====%d\n",a);
    }
    LL flag = (k & 1) ? 1 : -1;
    LL tmp = (ti - r[k - 1]) * flag;
    a += real;
    if (a < down)
      a = down;
    if (a > up)
      a = up;
    a += tmp;
    if (a < 0)
      a = 0;
    if (a > x)
      a = x;
    printf("%lld\n", a);
  }
}
