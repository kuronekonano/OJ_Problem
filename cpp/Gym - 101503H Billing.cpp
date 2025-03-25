#include <algorithm>
#include <iostream>
#include <stdio.h> ///花费与通话时间梯度计算
#include <string>
#define ll long long /// 注意会有k2*p2出现1e6*1e6的情况超int
using namespace std;
int main() {
  ll n, k1, k2, p1, p2, p3;
  while (scanf("%lld%lld%lld%lld%lld%lld", &n, &k1, &k2, &p1, &p2, &p3) !=
         EOF) {
    ll ans = 0;
    if (n >= p1) {
      n -= p1;
      ans = k1;
      if (n == 0) {
        printf("%lld\n", k1);
        continue;
      }
    } else {
      printf("%lld\n", ans);
      continue;
    }
    if (n > k2 * p2) {
      ans += k2;
      n -= k2 * p2;
    } else if (n <= k2 * p2) {
      ans += n / p2;
      if (n % p2)
        ans++;
      printf("%lld\n", ans);
      continue;
    }
    if (n > p3) {
      ans += n / p3;
      if (n % p3)
        ans++;
      printf("%lld\n", ans);
    } else {
      printf("%lld\n", ans + 1);
    }
  }
}
