#include <stdio.h>
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int i, j;
    for (i = 1; i <= n / 2 + 1; i++) // �ϰ벿��
    {
      for (j = 1; j <= n - i + 1; j++) {
        if (i == j || j == n - i + 1) {
          printf("X");
        } else
          printf(" ");
      }
      printf("\n");
    }
    for (i = n / 2; i >= 1; i--) // ע�������������
    {
      for (j = 1; j <= n - i + 1; j++) // �°벿��
      {
        if (i == j || j == n - i + 1) // ÿ��ͷβ���ͼ�ξͺ�
        {
          printf("X");
        } else
          printf(" ");
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
