#include <stdio.h>
int main() {
  int i, j, n, t, k;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    if (n == 1) {
      printf("*\n"); // �������һ����ʱ�����
    } else {
      for (i = 1; i <= n; i++) // ÿ��
      {
        for (j = 1; j <= n - i; j++) // �ո���
        {
          printf(" ");
        }
        printf("*");                     // �����ո�����Ǻ�
        for (k = 1; k <= i * 2 - 3; k++) // �����ո�������ʵ�ļ�������
          printf(" ");
        if (i > 1) /// ��һ�в�����ڶ����Ǻ�
        {
          printf("*");
        }
        printf("\n");
      }
      for (i = n - 1; i >= 1; i--) /// �°벿�֣�ֱ����������ͺ�
      {
        for (j = 1; j <= n - i; j++) {
          printf(" ");
        }
        printf("*");
        for (k = 1; k <= i * 2 - 3; k++) {
          printf(" ");
        }
        if (i > 1) {
          printf("*");
        }
        printf("\n");
      }
    }
    printf("\n");
  }
  return 0;
}
