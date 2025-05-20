#include <math.h>  ///简单二分，初始边界l=0,r=100
#include <stdio.h> ///题目样例的误差0.00005四舍五入了，这里没要求
double workout(double x) {
  return 8 * pow(x, 4) + 2 * pow(x, 2) + 7 * pow(x, 3) + 3 * x + 6;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    double y;
    scanf("%lf", &y);
    if (y > 8 * pow(100, 4) + 2 * pow(100, 2) + 7 * pow(10, 3) + 3 * 100 + 6 ||
        y < 6) /// 判断y值范围
    {
      printf("No solution!\n");
      continue;
    } else {
      double l = 0, r = 100, mid;
      while (r - l > 1e-7) /// 误差
      {
        mid = (l + r) / 2;
        if (workout(mid) > y) /// 二分循环
        {
          r = mid;
        } else {
          l = mid;
        }
      }
      printf("%.4f\n", mid); /// 控制四位精度
    }
  }
  return 0;
}
