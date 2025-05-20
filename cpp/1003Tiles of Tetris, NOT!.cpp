#include <stdio.h>
long long gcd(long long x, long long y) {
  if (y == 0) {
    return x;
  } else {
    return gcd(y, x % y);
  }
}
int main() {
  long long a, b;
  while (scanf("%lld%lld", &a, &b) != EOF) {
    if (a == 0 && b == 0) {
      return 0;
    }
    long long k = gcd(a, b);         /// 最大公约数
    printf("%lld\n", a * b / k / k); /// 最小公倍数除最大公约数
  }
  return 0;
}
