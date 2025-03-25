#include <stdio.h>
int main() {
  int n;
  double s, t, u, v, w, l;
  scanf("%d", &n);
  while (n--) {
    scanf("%lf%lf%lf%lf", &u, &v, &w, &l);
    t = l / (u + v);
    s = w * t;
    printf("%.3f\n", s);
  }
  return 0;
}
