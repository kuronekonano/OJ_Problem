#include <stdio.h>
#define pi 3.1415926
int main() {
  double h, v;
  while (scanf("%lf", &h) != EOF) {
    v = h * h * h * pi /
        6; // �����ü��޷�������֪�뾶r���������Բ������ϸ����ʱʣ�����Ϊ����������뾶Ϊh/2�������������ʽ��������h^3/6*pi
    printf("%.2f\n", v);
  }
}
