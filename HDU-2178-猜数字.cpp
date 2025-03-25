#include <stdio.h>
int main() {
  int t, a[36], i, n;
  a[1] = 1;
  for (i = 2; i <= 30; i++) {
    a[i] = a[i - 1] * 2 + 1;
  }
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", a[n]);
  }
}
