#include <math.h>  ///造成这种情况是因为c=1了，增长速率差异，导致a b值与c相等
#include <stdio.h> ///二分基础    题目有缺陷，当a=9,b=4,c=1时，函数在单调递增的情况下，也有解，必须考虑，约在-0.39处，函数值取0
int a, b, c;
double unknow(double ans) /// a+b的值应等于c
{
  return pow(a, ans) + pow(b, ans) - pow(c, ans);
}
int main() {
  double l, r;
  while (scanf("%d%d%d%lf%lf", &a, &b, &c, &l, &r) != EOF) {
    if (unknow(l) < 0 ||
        (unknow(l) > 0 && unknow(r) > 0)) /// 只考虑了单调递减（缺陷）
    {
      printf("No Answer!\n"); /// 所以不能直接判断当单调递减就NO ANSWER
    } else {
      double mid;
      while (r - l > 1e-7) {
        mid = (l + r) / 2;
        if (unknow(mid) > 0) /// 整个算法都特么按照单调递减的情况写的
        {
          l = mid;
        } else {
          r = mid;
        }
      }
      printf("%f\n", mid);
    }
  }
  return 0;
}
