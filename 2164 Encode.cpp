#include <stdio.h>
#include <string.h> ///思路是拿一个4*4用空格清空的矩阵来存放每个字符，然后再倒着回去输出，输出玩一部分再继续装剩下的，再输出，再装，直到字符串结束
int main() {
  char a[108];
  int i, j, k;
  while (gets(a)) {
    int n = strlen(a);
    bool flag = false;
    for (i = 0; i < n;) {
      char b[5][5];
      memset(b, ' ', sizeof(b));
      for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++) {
          b[j][k] = a[i++];
          if (i == n) {
            flag = true;
            break;
          }
        }
        if (flag)
          break;
      }
      for (j = 0; j <= 3; j++) {
        for (k = 3; k >= 0; k--) {
          printf("%c", b[k][j]);
        }
      }
    }
    printf("\n"); /// 记得换行
  }
}
