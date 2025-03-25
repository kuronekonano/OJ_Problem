#include <stdio.h>
#include <stdlib.h>
void input(int **p, int m, int n) {
  int i, j;
  printf("请输入数组%d×%d：\n", m, n);
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
  int **a, **b, m, n, i; // 定义二重指针

  printf("请输入行、列数为：");

  scanf("%d%d", &m, &n);

  a = (int **)malloc(m * sizeof(int));

  for (i = 0; i < m; ++i) {
    a[i] = (int *)malloc(n * sizeof(int)); // 开辟存储空间，数组a
  }

  b = (int **)malloc(n * sizeof(int));

  for (i = 0; i < n; ++i) {

    b[i] = (int *)malloc(m * sizeof(int)); // 开辟
  }

  input(a, m, n); // 输出函数

  output1(a, m, n); // 输出函数

  zhuanzhi(a, b, m, n); // 转置函数

  output2(b, m, n); // 输出函数

  for (i = 0; i < m; ++i) /// 释放空间
    free(a[i]);
  free(a);
  for (i = 0; i < n; ++i)
    free(b[i]);
  free(b);
  return 0;
}
