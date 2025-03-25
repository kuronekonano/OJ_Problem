#include <stdio.h>
#define MOD 100003
long long poww(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1)
      ans = ((ans % MOD) * (a % MOD)) % MOD;
    a = ((a % MOD) * (a % MOD)) % MOD;
    b >>= 1;
  }
  return ans;
}
int main() {
  long long n, m;
  while (scanf("%lld%lld", &m, &n) != EOF) {
    long long sum = poww(m, n);
    long long ans = sum - ((poww(m - 1, n - 1) * m) % MOD);
    printf("%lld\n", ans < 0 ? ans + MOD : ans);
  }
}
