#include <math.h>
#include <stdio.h>
int main() {
  int x1, y1, x2, y2, x3, m, v, st;
  while (scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &m) != EOF) {
    if (y1 - y2 == 0) // ��ֹ��0
    {
      v = 0;
    } else
      v = fabs(x1 * y1 - x2 * y2) / fabs(y1 - y2); // ����������ٶ�
    st = x1 * y1 - y1 * v;                         // �����ʼ����
    if (m * v + st >=
        x3 *
            m) // ����ʳ���˲ݵ������ٶȣ����ϳ�ʼ����������x3ͷţ��ÿͷ��ʳ��������Գ���
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
