#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 100005;
int t, n, m;
double x, x2, y2, u1, u2, v1, v2, y;
double cal(double x, double y, double x2, double y2) {
  return sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
}
int main() {
  int cas = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%lf%lf%lf%lf", &x, &y, &x2, &y2);
    scanf("%lf%lf%lf%lf", &u1, &v1, &u2, &v2);
    double a = (u1 - u2) * (u1 - u2) + (v1 - v2) * (v1 - v2);
    double b = 2 * (x - x2) * (u1 - u2) + 2 * (y - y2) * (v1 - v2);
    double c = (x - x2) * (x - x2) + (y - y2) * (y - y2);
    //        printf("=====%f  %f\n",a,b);
    if (a == 0) {
      printf("Case %d: %.6f\n", ++cas, cal(x, y, x2, y2));
      continue;
    }
    double tmp = -b / (2 * a);
    if (tmp < 0)
      printf("Case %d: %.6f\n", ++cas, cal(x, y, x2, y2));
    else
      printf("Case %d: %.6f\n", ++cas, sqrt(a * tmp * tmp + b * tmp + c));
  }
}
/*
5
1 1 2 2
1 1 2 2

1 1 2 2
1 1 -1 -1

1 1 2 2
0 1 0 -1

1 1 1 1
1 1 2 2

0 0 0 1
0 1 1 0
*/
