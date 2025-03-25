#include <math.h>
#include <stdio.h>
#include <string.h>
int main() {
  long long l, r, t, i;
  int a[100], b[100];
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld", &l, &r);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int numa = 0, numb = 0;
    while (l > 0) {
      a[++numa] = l % 2;
      l /= 2;
    }
    while (r > 0) {
      b[++numb] = r % 2;
      r /= 2;
    }
    long long stop = 0, ans = 0;
    for (i = numb; i >= 1; i--) {
      if (a[i] != b[i]) {
        stop = i;
        break;
      }
    }
    for (i = 1; i <= stop; i++) {
      long long sum = pow(2, i - 1);
      ans += sum;
    }
    for (i = stop + 1; i <= numb; i++) {
      long long sum = pow(2, i - 1);
      ans += sum * b[i];
    }
    printf("%lld\n", ans);
  }
}
