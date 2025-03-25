#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int a[5], b[5], i, t, cas = 0;
  scanf("%d", &t);
  while (t--) {
    cas++;
    for (i = 0; i < 4; i++)
      scanf("%d", &a[i]);
    swap(a[3], a[2]);
    for (i = 0; i < 4; i++)
      scanf("%d", &b[i]);
    swap(b[2], b[3]);
    bool flag = false;
    for (i = 0; i < 4; i++) {
      if (a[0] == b[i]) {
        int tmp = i, j = 0;
        while (a[j] == b[tmp] && j <= 4) {
          tmp = (tmp + 1) % 4;
          j++;
        }
        if (j == 4) {
          flag = true;
          break;
        }
      }
    }
    printf("Case #%d: %s\n", cas, !flag ? "IMPOSSIBLE" : "POSSIBLE");
  }
}
