#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
double cal(int a, int b, int c) {
  double p = (a + b + c) / 2.0;
  return (sqrt(p * (p - a) * (p - b) * (p - c)));
}
int main() {
  int n, a[32], i, j, k;
  bool vis[32];
  while (scanf("%d", &n) != EOF) {
    if (!n)
      break;
    memset(vis, false, sizeof(vis));
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    int sum = n, ii = 0, jj = 0, kk = 0;
    double ans = 0, tmp = 0;
    while (sum >= 3) {
      for (i = 0; i < n - 2; i++) {
        if (!vis[i]) {
          for (j = i + 1; j < n - 1; j++) {
            if (!vis[j]) {
              for (k = j + 1; k < n; k++) {
                if (a[i] + a[j] > a[k] && a[j] + a[k] > a[i] &&
                    a[i] + a[k] > a[j] && !vis[k]) {
                  double area = cal(a[i], a[j], a[k]);
                  if (area > tmp) {
                    ii = i, jj = j, kk = k;
                    tmp = area;
                  }
                }
              }
            }
          }
        }
      }
      vis[ii] = true, vis[jj] = true, vis[kk] = true;
      sum -= 3;
      ans += tmp;
      if (tmp == 0)
        break;
      tmp = 0;
    }
    printf("%.2f\n", ans);
  }
}
