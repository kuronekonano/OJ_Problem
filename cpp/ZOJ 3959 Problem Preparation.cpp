#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int t, i, n, a[108];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    if (n < 10 || n > 13) {
      printf("No\n");
      continue;
    }
    sort(a, a + n);
    if (a[0] != 1 || a[1] != 1) {
      printf("No\n");
      continue;
    }
    bool flag = true;
    for (i = 2; i < n - 1; i++) {
      if (a[i] - a[i - 1] > 2) {
        flag = false;
        printf("No\n");
        break;
      }
    }
    if (flag) {
      printf("Yes\n");
    }
  }
  return 0;
}
