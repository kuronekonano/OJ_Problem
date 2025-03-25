#include <stdio.h> ///相当于把所有情况都列出来了
int main() {
  int a[205][208], n, i, j, h, l;
  while (scanf("%d", &n) != EOF) {
    int sum, flag = 0;
    for (i = 1; i <= n; i++) /// 二维矩阵按行输入
    {
      sum = 0;
      for (j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]);
        sum = sum + a[i][j]; /// 标记每行
      }
      a[i][0] = sum;    /// 从1开始，那0位可以存这一行的和
      if (sum % 2 != 0) /// 不为偶数计数
      {
        h = i;
        flag++;
      }
    }
    if (flag >= 2) /// 大于等于2直接pass
    {
      printf("NO\n");
      continue;
    }
    int flag2 = 0;
    for (j = 1; j <= n; j++) {
      sum = 0;
      for (i = 1; i <= n; i++) {
        sum = sum + a[i][j];
      }
      a[0][j] = sum;
      if (sum % 2 != 0) {
        l = j;
        flag2++;
      }
    }
    if (flag2 >= 2) {
      printf("NO\n");
      continue;
    }
    if (flag == flag2 && flag2 == 1) {
      printf("change(%d,%d)\n", h, l);
    } else {
      printf("YES\n");
    }
  }
  return 0;
}
