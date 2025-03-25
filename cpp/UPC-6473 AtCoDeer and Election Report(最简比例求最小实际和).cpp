#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 10;
LL t, n, a;
int main() {
  while (scanf("%lld", &n) != EOF) {
    LL nt, na;
    scanf("%lld%lld", &t, &a);
    for (int i = 1; i < n; i++) {
      LL tmp = 1;
      scanf("%lld%lld", &nt, &na);
      if (nt < t) {
        tmp = t / nt;
        if (t % nt)
          tmp++;
      }
      if (na < a) {
        LL temp = a / na;
        if (a % na)
          temp++;
        tmp = max(tmp, temp);
      }
      t = nt * tmp;
      a = na * tmp;
      //            printf("=====%lld   %lld     %lld   %lld\n",t,a,tmp);
    }
    printf("%lld\n", t + a);
  }
}
