#include <stdio.h>
int main() {
  int n, i, j;
  int a[55][55];
  while (scanf("%d", &n) != EOF) // cm-1 cn-1
  {
    for (i = 0; i < n; i++) {
      for (j = 0; j <= i; j++) // j�ǿ��Ե���i�ģ��������
      {
        if (j == 0 || j == i) // ��Ե��ĩβʱ��������1
        {
          a[i][j] = 1;
        } else {
          a[i][j] = a[i - 1][j - 1] +
                    a[i - 1][j]; // ĳ���������Ͻǵ������������Ϸ�����
        }
      }
    } // ��ѭ���������һ��������ǣ�֮���ѭ���������
    for (i = 0; i < n; i++) {
      for (j = 0; j <= i; j++) {
        printf("%d", a[i][j]);
        if (j < i) {
          printf(" "); // �κλ���֮ǰ��������ո�
        }
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
