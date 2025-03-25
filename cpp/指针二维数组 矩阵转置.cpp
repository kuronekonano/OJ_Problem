#include <stdio.h>
#include <stdlib.h>
void input(int **p, int m, int n) {
  int i, j;
  printf("����������%d��%d��\n", m, n);
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &p[i][j]);
}

void output1(int **p, int m, int n) {
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%5d", p[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void output2(int **q, int m, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%5d", *(*(q + i) + j));
    }
    printf("\n");
  }
  printf("\n");
}

void zhuanzhi(int **p, int **q, int m, int n) {
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      *(*(q + j) + i) = *(*(p + i) + j);
    }
  }
}

int main() {
  int **a, **b, m, n, i; // �������ָ��

  printf("�������С�����Ϊ��");

  scanf("%d%d", &m, &n);

  a = (int **)malloc(m * sizeof(int));

  for (i = 0; i < m; ++i) {
    a[i] = (int *)malloc(n * sizeof(int)); // ���ٴ洢�ռ䣬����a
  }

  b = (int **)malloc(n * sizeof(int));

  for (i = 0; i < n; ++i) {

    b[i] = (int *)malloc(m * sizeof(int)); // ����
  }

  input(a, m, n); // �������

  output1(a, m, n); // �������

  zhuanzhi(a, b, m, n); // ת�ú���

  output2(b, m, n); // �������

  for (i = 0; i < m; ++i) /// �ͷſռ�
    free(a[i]);
  free(a);
  for (i = 0; i < n; ++i)
    free(b[i]);
  free(b);
  return 0;
}
