#include <stdio.h>
int gcd(int a, int b) {
  int c;
  while (b != 0) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}
int main() {
  int a[11], b[11], i, j, t, n, cas = 0;
  scanf("%d", &t);
  while (t--) {
    cas++;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    for (i = 1; i <= n; i++)
      scanf("%d", &b[i]);
    int m = a[n], z = b[n];
    for (i = n - 1; i >= 1; i--) {
      int tmp = m;
      m = a[i] * m + z;
      z = b[i] * tmp;
    }
    int c = gcd(m, z);
    m /= c;
    z /= c;
    printf("Case #%d: %d %d\n", cas, z, m);
  }
}
