#include <stdio.h>
int main() {
  long long a, b, tmp, t, cas = 0;
  scanf("%lld", &t);
  while (t--) {
    cas++;
    scanf("%lld%lld", &a, &b);
    long long ans = 1, tmp;
    if (a == 0 && b == 0) {
      printf("Case #%lld: 1\n", cas);
      continue;
    }
    if (a == 0 || b == 0) {
      printf("Case #%lld: 2\n", cas);
      continue;
    }
    tmp = a % b;
    ans += a / b;
    while (a % b != 0) {
      tmp = a;
      a = b;
      b = tmp % b;
      ans += a / b;
    }
    printf("Case #%lld: %lld\n", cas, ans);
  }
}
