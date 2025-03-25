#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, i, a[100005];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int sum = 0;
    for (i = 0; i < n; i++) {
      if (a[i] <= sum + 1) {
        sum += a[i];
      } else
        break;
    }
    printf("%d\n", sum);
  }
  return 0;
}
