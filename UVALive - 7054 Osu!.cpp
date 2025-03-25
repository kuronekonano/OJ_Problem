#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;
int main() {
  long long t, i, time, x, y, x1, y1, n, time1;
  scanf("%lld", &t);
  while (t--) {
    double minn = 0;
    scanf("%lld", &n);
    scanf("%lld%lld%lld", &time, &x, &y);
    for (i = 1; i <= n - 1; i++) {
      scanf("%lld%lld%lld", &time1, &x1, &y1);
      double speed =
          sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)) / (time1 - time);
      minn = speed > minn ? speed : minn;
      x = x1, y = y1, time = time1;
    }
    printf("%.10f\n", minn);
  }
}
