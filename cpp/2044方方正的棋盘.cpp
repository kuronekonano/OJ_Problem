#include <stdio.h>
int main() {
  int t, i, j, n, a[305][305];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    int m, x1, y1, x2, y2;
    scanf("%d", &m);
    while (m--) {
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2); /// 两个坐标确定的长方形
      int max = a
          [x1]
          [y1]; /// 找最大值，直接两个循环嵌套，起始和结束的坐标刚好是提供的长方形坐标范围
      for (i = x1; i <= x2; i++) {
        for (j = y1; j <= y2; j++) {
          if (max < a[i][j]) {
            max = a[i][j];
          }
        }
      }
      printf("%d\n", max);
    }
  }
  return 0;
}
