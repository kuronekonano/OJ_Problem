#include <stdio.h>
int main() {
  int n, m, i, j, a[108][105];
  while (scanf("%d%d", &n, &m) != EOF) {
    bool flag1 = true, flag0 = true,
         per = true; /// 三个标记，标记是否出现1，是否出现0，是否有0相连
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
        if (a[i][j] == 1)
          flag1 = false;
        if (a[i][j] == 0)
          flag0 = false;
        if (j != 1 && a[i][j - 1] == 0 && a[i][j] == 0) /// 横排判断连续0
        {
          per = false;
        }
      }
    }
    for (i = 1; i <= m; i++) /// 纵列判断连续0
    {
      for (j = 1; j <= n; j++) {
        if (j != 1 && a[j][i] == 0 && a[j - 1][i] == 0) {
          per = false;
        }
      }
    }
    printf("%s\n", !flag0 && !flag1 && per ? "perfect" : "terrible");
  }
}
