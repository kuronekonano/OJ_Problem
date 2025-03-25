#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int t, i, f, h, w, a[508];
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &f, &h, &w);
    for (i = 0; i < f; i++)
      scanf("%d", &a[i]);
    sort(a, a + f);
    int mixx = 0x3f3f3f3f, tmp = 0;
    for (i = 0; i < f; i++) {
      if ((a[i] - tmp) * h < mixx)
        mixx = (a[i] - tmp) * h;
      tmp = a[i];
    }
    if ((w - tmp) * h < mixx)
      mixx = (w - tmp) * h;
    printf("%d\n", mixx);
  }
}
