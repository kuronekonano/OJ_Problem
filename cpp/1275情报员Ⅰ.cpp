#include <math.h>
#include <stdio.h>
int main() {
  double x1, y1, x2, y2, v, dis, time;
  while (scanf("%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &v) != EOF) {
    dis = sqrt((x1 + x2) * (x1 + x2) + (y1 + y2) * (y1 + y2));
    time = dis / v;
    printf("%.2f\n", time);
  }
  return 0;
}
