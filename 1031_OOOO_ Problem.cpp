#include <stdio.h>
bool law(
    int x, int y, int l, int r,
    int t) /// 判断每个起始的O周围是否在棋盘内部，并且往后延长的五个格子也要在棋盘内部
{
  if (x < 0 || x >= 15 || y < 0 || y >= 15 || l < 0 || l >= 15 || r < 0 ||
      r >= 15 || t < 0 || t >= 15) {
    return false;
  } else {
    return true;
  }
}
int main() /// 因为是找连续四个，因此找到四个之首，头部的位置，往后延展就可以知道是否成连续四个了，不需要考虑再次碰到这连续四个时的判断
{
  char a[19][19];
  int n, i, j;
  scanf("%d", &n);
  getchar(); /// 吃掉换行
  while (n--) {
    getchar();               /// 每次一个数据完有个换行，这里吃掉它
    for (i = 0; i < 15; i++) /// 输入字符串二维数组
    {
      scanf("%s", a[i]);
    }
    int flag = 0;            /// 计数器
    for (i = 0; i < 15; i++) /// 遍历二维数组
    {
      for (j = 0; j < 15; j++) {
        if (a[i][j] ==
            'O') /// 当第一次发现这个O时，开始向周围四个方向延展遍历，观察是否成连续的四个O
        {
          if (law(i - 1, i + 1, i + 2, i + 3, i + 4) &&
              a[i - 1][j] ==
                  '+' && /// 纵向判断，并且首位（i-1）和（i+4）必须为 +（空格）
              a[i + 1][j] == 'O' &&
              a[i + 2][j] == 'O' && a[i + 3][j] == 'O' && a[i + 4][j] == '+') {
            flag++;
          }
          if (law(j - 1, j + 1, j + 2, j + 3, j + 4) &&
              a[i][j - 1] == '+' && /// 横向判断
              a[i][j + 1] == 'O' && a[i][j + 2] == 'O' && a[i][j + 3] == 'O' &&
              a[i][j + 4] == '+') {
            flag++;
          }
          if (law(i - 1, j + 1, j - 1, i + 1, i + 2) &&
              law(i + 3, i + 4, j - 4, j - 3, j - 3) &&
              a[i + 1][j - 1] ==
                  'O' && /// 左撇判断，并且此时有两个判断是否在棋盘内的函数判断
              a[i + 2][j - 2] == 'O' &&
              a[i + 3][j - 3] == 'O' && a[i + 4][j - 4] == '+' &&
              a[i - 1][j + 1] == '+') {
            flag++;
          }
          if (law(i - 1, i + 1, j - 1, j + 1, i + 2) &&
              law(j + 2, i + 3, j + 3, i + 4, j + 4) &&
              a[i + 1][j + 1] == 'O' && /// 右捺判断
              a[i + 2][j + 2] == 'O' && a[i + 3][j + 3] == 'O' &&
              a[i + 4][j + 4] == '+' && a[i - 1][j - 1] == '+') {
            flag++;
          }
        }
      }
    }
    printf("%d\n", flag); /// 直接输出计数结果
  }
  return 0;
}
