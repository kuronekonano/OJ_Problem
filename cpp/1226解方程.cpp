#include <math.h>
#include <stdio.h>
int main() {
  int a, b, c, d, t, i, j;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%.1f\n", sqrt((a - c) * (a - c) + (b - d) * (b - d)));
  }
}
