#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;
int main() {
  int i, n, m, a[58], b[56], t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    double sumn = 0, summ = 0, tmp;
    for (i = 1; i < n; i++) {
      scanf("%lf", &tmp);
      sumn += tmp;
    }
    for (i = 1; i <= m; i++) {
      scanf("%lf", &tmp);
      summ += tmp;
    }
    int ans1 = summ / m + 0.5;
    if (ans1 * m <= summ)
      ans1++;
    int ans2 = sumn / (n - 1);
    if (sumn == (n - 1) * ans2)
      ans2--;
    printf("%d %d\n", ans1, ans2);
  }
}
