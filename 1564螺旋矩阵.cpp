#include <stdio.h>
#include <string.h>

int xxx(int b) /// 计算位数
{
  int flag = 0;
  while (b != 0) {
    b = b / 10;
    flag++;
  }
  return flag;
}
int main() {
  int n, i, j, a[40][40], x, y;
  bool check = false;
  while (scanf("%d", &n) != EOF) {
    int flag = 1;
    memset(a, 0, sizeof(a));
    x = 1;
    y = 1;
    a[x][y] = flag++;
    int t = n;
    while (flag <= n * n) /// 螺旋矩阵
    {
      for (y++; y <= t; y++) /// 从左到右
      {
        a[x][y] = flag++;
      }
      y--;
      for (x++; x <= t; x++) /// 从上到下
      {
        a[x][y] = flag++;
      }
      x--;
      for (y--; y >= n - x + 1; y--) /// 从右到左
      {
        a[x][y] = flag++;
      }
      y++;
      for (x--; a[x][y] == 0; x--) /// 从左到右
      {
        a[x][y] = flag++;
      }
      x++;
      t--; /// 最后就是从左上角开始的顺时针螺旋
    }
    if (check) /// 控制while循环中的数据间空行
    {
      printf("\n");
    } else {
      check = true;
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        printf("%*d", xxx(n * n) + 1, a[i][j]); /// 动态控制字符宽度！！！！！
      }
      printf("\n");
    }
  }
  return 0;
}
