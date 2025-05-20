#include <stdio.h>
int main() {
  int a, b, c, d, n;
  while (scanf("%d", &n) != EOF) {
    for (a = 6; a <= n; a++) {
      for (b = 2; b <= a; b++) {
        for (c = b; c <= a; c++) {
          int x = a;     /// 二分法查找d值
          int y = c;     /// 因为 b======c=====d========a,存在这样的大小关系
          while (x >= y) /// 因此d作为大于c小于a的范围内值，在这个范围内不断二分
          { /// 这个循环是二分执行的条件，当范围x和y重合或交叉，说明不存在这个值
            int mid = (x + y) / 2; /// 二分
            if (a * a * a >
                b * b * b + c * c * c +
                    mid * mid *
                        mid) /// 若找到的值相乘小于a的立方，则范围右移，增大d值
            {
              y = mid + 1;
            } else if (a * a * a < b * b * b + c * c * c +
                                       mid * mid * mid) /// 否则左移，减小d值
            {
              x = mid - 1;
            } else {
              printf(
                  "%d^3 = %d^3 + %d^3 + %d^3\n", a, b, c,
                  mid); /// 当等于就可以输出了，那么此时符合的值因为只有以一个
              break;    /// 必须直接停掉二分循环
            }
          }
        }
      }
    }
  }
  return 0;
}
