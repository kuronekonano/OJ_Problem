#include <stdio.h>
int main() {
  int a, b, c, d, n;
  while (scanf("%d", &n) != EOF) {
    for (a = 6; a <= n; a++) {
      for (b = 2; b <= a; b++) {
        for (c = b; c <= a; c++) {
          int x = a;     /// ���ַ�����dֵ
          int y = c;     /// ��Ϊ b======c=====d========a,���������Ĵ�С��ϵ
          while (x >= y) /// ���d��Ϊ����cС��a�ķ�Χ��ֵ���������Χ�ڲ��϶���
          { /// ���ѭ���Ƕ���ִ�е�����������Χx��y�غϻ򽻲棬˵�����������ֵ
            int mid = (x + y) / 2; /// ����
            if (a * a * a >
                b * b * b + c * c * c +
                    mid * mid *
                        mid) /// ���ҵ���ֵ���С��a����������Χ���ƣ�����dֵ
            {
              y = mid + 1;
            } else if (a * a * a < b * b * b + c * c * c +
                                       mid * mid * mid) /// �������ƣ���Сdֵ
            {
              x = mid - 1;
            } else {
              printf(
                  "%d^3 = %d^3 + %d^3 + %d^3\n", a, b, c,
                  mid); /// �����ھͿ�������ˣ���ô��ʱ���ϵ�ֵ��Ϊֻ����һ��
              break;    /// ����ֱ��ͣ������ѭ��
            }
          }
        }
      }
    }
  }
  return 0;
}
