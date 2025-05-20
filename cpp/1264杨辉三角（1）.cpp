#include <stdio.h>
int main() {
  int n, i, j;
  int a[55][55];
  while (scanf("%d", &n) != EOF) // cm-1 cn-1
  {
    for (i = 0; i < n; i++) {
      for (j = 0; j <= i; j++) // j是可以等于i的，必须等于
      {
        if (j == 0 || j == i) // 边缘和末尾时的数等于1
        {
          a[i][j] = 1;
        } else {
          a[i][j] = a[i - 1][j - 1] +
                    a[i - 1][j]; // 某数等于左上角的数加上其正上方的数
        }
      }
    } // 此循环内造出了一个杨辉三角，之后的循环用于输出
    for (i = 0; i < n; i++) {
      for (j = 0; j <= i; j++) {
        printf("%d", a[i][j]);
        if (j < i) {
          printf(" "); // 任何换行之前都是输出空格
        }
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
