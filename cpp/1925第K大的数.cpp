#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  int k, m, n, i, j, a[100005];
  while (scanf("%d%d", &n, &m) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (j = 1; j <= m; j++) {
      scanf("%d", &k);
      for (i = 0; i < n; i++) {
        if (a[i] >= k) {
          printf("%d\n", a[i]);
          break;
        }
      }
      if (i == n) {
        printf("-1\n");
      }
    }
  }
  return 0;
}
