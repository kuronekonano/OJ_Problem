#include <math.h>
#include <stdio.h>
int main() {
  for (int i = 1; i <= 10000; i++) {
    if ((int)sqrt(100 + i) * (int)sqrt(100 + i) ==
        (100 + i)) /// �ж���ȫƽ������������ǿ��ת��
    {
      if ((int)sqrt(268 + i) * (int)sqrt(268 + i) == (268 + i)) /// �ټ���168
      {
        printf("%d\n", i);
      }
    }
  }
  return 0;
}
