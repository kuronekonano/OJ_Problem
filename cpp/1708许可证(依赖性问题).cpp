#include <stdio.h>
#include <string.h>
int main() {
  int n, m, i, j, x, y, k;
  bool vis[105][108];
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(vis, false, sizeof(vis)); /// 必须记得清空数组
    for (i = 0; i < m; i++) {
      scanf("%d%d", &x, &y);
      vis[x][y] = true; /// 数组中建立关系
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        for (k = 1; k <= n; k++) {
          if (vis[i][j] == true &&
              vis[j][k] ==
                  true) /// 两两比较，若对应关系两两关联，直接在那里标注关系
          {
            vis[i][k] = true;
          }
        }
      }
    }
    vis[1][1] = true; /// 第一个是肯定有的
    int flag = 0;     /// 计数器
    for (i = 1; i <= n; i++) {
      if (vis[1][i] == true) /// 直接数和1建立直接关系的
        flag++;
    }
    printf("%d\n", flag);
    //        for(i=1;i<=n;i++)
    //        {
    //            for(j=1;j<=n;j++)
    //            {
    //                printf("%d",vis[i][j]);
    //            }
    //            printf("\n");
    //        }
  }
  return 0;
}
