#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    LL a[4], d;
    scanf("%lld%lld%lld%lld", &a[0], &a[1], &a[2], &d);
    sort(a, a + 3);
    LL maxn = a[0] * a[0] + a[1] * a[1] + (a[2] + d) * (a[2] + d) + 7 * a[0];
    LL minn = a[1] - a[0];
    if (d > minn) {
      a[0] += minn;
      d -= minn;
      minn = a[2] - a[1];
      if (d / 2 >= minn) {
        a[0] += minn;
        a[1] += minn;
        d -= 2 * minn;
        a[0] += d / 3;
        a[1] += d / 3;
        a[2] += d / 3;
        a[2] += d % 3;
      } else {
        a[0] += d / 2;
        a[1] += d / 2;
        d %= 2;
        a[0] += d;
      }
    } else
      a[0] += d;
    LL ans = a[0] * a[0] + a[1] * a[1] + a[2] * a[2] +
             7 * min(a[0], min(a[1], a[2]));
    //        printf("%lld %lld %lld\n",a[0],a[1],a[2]);
    //        printf("------%lld   %lld\n",ans,maxn);
    printf("%lld\n", max(ans, maxn));
  }
}
