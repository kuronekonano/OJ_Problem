#include <bits/stdc++.h>
#define LL long long
using namespace std;
int x[2000006], y[2000009];
int px[1008], py[1008];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &px[i], &py[i]);
      px[i] += 1000000;
      py[i] += 1000000;
      if (i != 1) {
        if (px[i] == px[i - 1]) {
          int maxy = max(py[i], py[i - 1]);
          int miny = min(py[i], py[i - 1]);
          y[miny]++;
          y[maxy]--;
        } else {
          int maxx = max(px[i], px[i - 1]);
          int minx = min(px[i], px[i - 1]);
          x[minx]++;
          x[maxx]--;
        }
      }
    }
    if (px[1] == px[n]) {
      int maxy = max(py[1], py[n]);
      int miny = min(py[1], py[n]);
      y[miny]++;
      y[maxy]--;
    } else {
      int maxx = max(px[1], px[n]);
      int minx = min(px[1], px[n]);
      x[minx]++;
      x[maxx]--;
    }
    LL ans = 0, sum = 0;
    for (int i = 0; i <= 2000000; i++) {
      x[i] += x[i - 1];
      y[i] += y[i - 1];
      if (x[i] >= 2)
        ans += x[i] - 2;
      if (y[i] >= 2)
        ans += y[i] - 2;
    }
    printf("%lld\n", ans);
  }
}
