#include <stdio.h> //�������˷�
#include <string.h>
int main() {
  int i, j, n, m, p, s, flag;
  int a[105][106], b[107][108], c[109][110];
  while (scanf("%d%d%d", &m, &n, &p) != EOF) {
    for (i = 1; i <= m; i++) // ���벿��
    {
      for (j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= p; j++) {
        scanf("%d", &b[i][j]);
      }
    }
    memset(c, 0, sizeof(c)); // ���㲿��
    for (i = 0; i <= m; i++) // ��i�п�ʼ�����ڵ�һ������
    {
      for (j = 1; j <= p; j++) // ��j�У����ڵڶ�������
      {
        for (s = 1; s <= n; s++) // ���������У���һ�����к͵ڶ�����������ͬ��
        {
          c[i][j] = c[i][j] + a[i][s] * b[s][j];
        }
      }
    }
    for (i = 1; i <= m; i++) // �������
    {
      flag = 0;
      for (j = 1; j <= p; j++) {
        if (j == 1) {
          printf("%d", c[i][j]);
        } else
          printf(" %d", c[i][j]);
        flag++;
      }
      if (flag == p)
        printf("\n");
    }
  }
  return 0;
}
