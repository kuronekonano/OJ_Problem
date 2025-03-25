#include <stdio.h> //详见矩阵乘法
#include <string.h>
int main() {
  int i, j, n, m, p, s, flag;
  int a[105][106], b[107][108], c[109][110];
  while (scanf("%d%d%d", &m, &n, &p) != EOF) {
    for (i = 1; i <= m; i++) // 输入部分
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
    memset(c, 0, sizeof(c)); // 计算部分
    for (i = 0; i <= m; i++) // 第i行开始，用于第一个矩阵
    {
      for (j = 1; j <= p; j++) // 第j列，用于第二个矩阵
      {
        for (s = 1; s <= n; s++) // 两个矩阵中，第一个的行和第二个的列是相同的
        {
          c[i][j] = c[i][j] + a[i][s] * b[s][j];
        }
      }
    }
    for (i = 1; i <= m; i++) // 输出部分
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
