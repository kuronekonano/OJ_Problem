#include <math.h>
#include <stdio.h>
bool zhishu(int x) {
  for (int i = 2; i < x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  int i, j = 0, n;
  long long a[100005];
  for (i = 1; i <= 100005; i++) {
    if (zhishu(i)) {
      a[j++] = i * i;
    }
  }
  int k, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < j; i++) {
      if (a[i] > n) {
        k = i;
        break;
      }
    }
    if (a[k] - n > n - a[k - 1]) {
      printf("%d\n", a[k - 1]);
    } else {
      printf("%d\n", a[k]);
    }
    printf("%d\n", a[k - 1]);
  }
  return 0;
}
