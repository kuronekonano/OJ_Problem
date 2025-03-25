#include <stdio.h>
int main() {
  double x1, x2, x3, x4, y1, y2, y3, y4;
  int t; /// 细节决定成败！即使是输入次数错定成了浮点型，输入还是按十进制输入，也是会出事的
  scanf("%d", &t);
  while (t--) /// 有几种情况，其中特殊的是平行于x轴和平行于y轴
  {
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    double k1 = (y2 - y1) / (x2 - x1); /// 很奇怪这里可能除0却没有RE
    double k2 = (y4 - y3) / (x4 - x3);
    double b1 = y1 - k1 * x1;
    double b2 = y3 - k2 * x3;
    if (k1 ==
        k2) /// 其中，平行于x轴是y值相同，相减为零，分母为零，斜率为0，b值直接是y1和y3，无伤大雅
    {
      if (b1 == b2) /// 若平行k值会直接都为零相等
      {
        printf("LINE\n");
      } else {
        printf("NONE\n"); /// 若不共线，则直接取b值，也就是y1和y3比较
      }
    } else if (x1 == x2 && x3 == x4) /// 避免除分母为0
    {
      if (x1 == x3) /// 平行于y轴有三种情况，两条线同时平行，或一条平行
      {
        printf("LINE\n"); /// 若两条同时平行，则直接比较两直线是否共线
      } else {
        printf("NONE\n");
      }
    } else if (
        x1 ==
        x2) /// 但是当平行于y轴时，因为x值相同，会出现分母为0的情况，因此分开考虑，计算公式中k与b都无法计算
    {
      printf(
          "POINT %.2f %.2f\n", x1,
          k2 * x1 +
              b2); /// 若只有一条平行y轴，那么肯定是相交的，焦点直接取另一条直线的方程，带入x值即可！
    } else if (x3 == x4) {
      printf("POINT %.2f %.2f\n", x3, k1 * x3 + b1);
    } else /// 最后一种情况是相交的情况，由公式推导可得焦点   k1*x+b1=k2*x+b2
           /// ---> (k1-k2)*x=b2-b1 ---> x=(b2-b1)/(k1-k2)
    {
      double x =
          (b1 - b2) / (k2 - k1); /// 或反过来将式子左右调换一下  b1-b2=(k2-k1)*x
      printf("POINT %.2f %.2f\n", x, k1 * x + b1);
    }
  }
  return 0;
}
