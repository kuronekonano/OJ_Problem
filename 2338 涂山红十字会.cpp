#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
struct doc {
  int si, di;
} a[1002];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int ans = 0;
    for (int i = 0; i < n; i++)
      scanf("%d%d", &a[i].si, &a[i].di);
    for (int i = 0; i < n; i++) {
      if (a[i].si > ans)
        ans = a[i].si;
      else {
        int j = 0;
        while (a[i].si + j * a[i].di < ans + 1)
          j++;
        ans = a[i].si + j * a[i].di;
      }
    }
    printf("%d\n", ans);
  }
}
