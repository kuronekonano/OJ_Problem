#include <math.h>
#include <stdio.h>
int main() {
  double area, l, pi = acos(-1); // ��������Ϊ��Բ����סacos(-1)ʱ���ڦ�
  while (scanf("%lf", &l)) {
    if (l == 0)
      break;
    area = (l / pi) * (l / pi) * pi / 2;
    printf("%.2f\n", area);
  }
  return 0;
}
