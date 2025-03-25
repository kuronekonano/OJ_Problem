#include <algorithm>
#include <stdio.h> ///ÊÖ»ú³äµç
using namespace std;
int main() {
  int t, a[108], i;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    i = n - 1;
    int flag = 0;
    while (m >= (100 - a[i]) && i >= 0) {
      m = m - 100 + a[i];
      flag++;
      i--;
    }
    printf("%d\n", flag);
  }
  return 0;
}
