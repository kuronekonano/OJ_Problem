#include <math.h>
#include <stdio.h>
struct point {
  long long x, y;
} a, b, c;
int main() {
  while (scanf("%lld%lld%lld%lld%lld%lld", &a.x, &a.y, &b.x, &b.y, &c.x,
               &c.y) != EOF) {
    if ((b.x - a.x) * (c.y - b.y) != (b.y - a.y) * (c.x - b.x)) {
      long long dis1 = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
      long long dis2 = (b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y);
      if (dis1 == dis2)
        printf("Yes\n");
      else
        printf("No\n");
    } else
      printf("No\n");
  }
}
