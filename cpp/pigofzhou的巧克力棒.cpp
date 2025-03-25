#include <stdio.h>
int main() {
  long long t, n, i;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    long long flag = 0;
    while (n > 1) {
      flag = flag + n / 2;
      n /= 2;
    }
    printf("%lld\n", flag);
  }
  return 0;
}
