#include <math.h>
#include <stdio.h> ///�����ȱ������θ����߳�����������(�����ڱ߲��ܸ���)ʹ֮��͸�Χ�ǵ��������С
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    double s1, s2;
    scanf("%lf%lf", &s1, &s2);
    double b = s1 > s2 ? s1 : s2;
    double s = s1 > s2 ? s2 : s1;
    double ans = 0;
    if (b / 2 >= s)
      ans = b * b * sqrt(3) / 2;
    else
      ans = (fabs(s - b / 2) + b) * b * sqrt(3) / 2;
    printf("%.3f\n", ans);
  }
}
