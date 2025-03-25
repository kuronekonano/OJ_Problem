#include <stdio.h>
#include <string.h> ///注意读题，一定是一个完整的矩阵
int main() {
  int i, j, n;
  char a[25][25];
  char b[209];
  while (scanf("%d", &n) != EOF) {
    if (n == 0) {
      return 0;
    }
    scanf("%s", b);
    int len = strlen(b);
    int t = 0;
    i = 0;
    while (len > t - 1) /// 塞入蛇形二维数组中处理
    {
      for (i++, j = 1; j <= n; j++) {
        a[i][j] = b[t++];
      }
      if (len <= t) {
        break;
      }
      j--;
      for (i++; j >= 1; j--) {
        a[i][j] = b[t++];
      }
      j++;
      if (len <= t) {
        break;
      }
    }
    int k = i;
    t = 0;
    for (j = 1; j <= n; j++) /// 倒着念出来就好
    {
      for (i = 1; i <= k; i++) {
        b[t++] = a[i][j];
      }
    }
    b[t] = '\0'; /// 记得处理字符串末尾
    printf("%s\n", b);
  }
  return 0;
}
