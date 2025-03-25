#include <stdio.h>
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int i, j;
    for (i = 1; i <= n / 2 + 1; i++) // 上半部分
    {
      for (j = 1; j <= n - i + 1; j++) {
        if (i == j || j == n - i + 1) {
          printf("X");
        } else
          printf(" ");
      }
      printf("\n");
    }
    for (i = n / 2; i >= 1; i--) // 注意分上下两部分
    {
      for (j = 1; j <= n - i + 1; j++) // 下半部分
      {
        if (i == j || j == n - i + 1) // 每行头尾输出图形就好
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
