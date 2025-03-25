#include <math.h>
#include <stdio.h>
int main() {
  int x1, y1, x2, y2, x3, m, v, st;
  while (scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &m) != EOF) {
    if (y1 - y2 == 0) // 防止除0
    {
      v = 0;
    } else
      v = fabs(x1 * y1 - x2 * y2) / fabs(y1 - y2); // 计算草生长速度
    st = x1 * y1 - y1 * v;                         // 计算初始草量
    if (m * v + st >=
        x3 *
            m) // 若饱食量乘草的生长速度，加上初始草量，大于x3头牛乘每头饱食量，则可以出栏
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
