#include <math.h>
#include <stdio.h>
#include <string.h>
char a[5000][5000];
int digui(int n, int x, int y, int h, int w) {
  if (n == 2) {
    a[x][y] = a[x - 1][y - 1] = a[x][y - 2] = '*';
    return 0;
  }
  int nh = pow(2, n - 2) / 2,
      nw = (pow(2, n - 1) - 1) / 2; /// 上一个三角形坐标，各点坐标
  digui(n - 1, x, y, nh, nw);       /// 右下角，以三角形右下角为标准点，分支扩展
  digui(n - 1, x, y - w - 1, nh, nw); /// 左下角
  digui(
      n - 1, x - h, y - w / 2 - 1, nh,
      nw); /// 上方///最右下角坐标
           /// 一只讲三点坐标投向下一个图形打印的函数中处理，直到找到每一个n=2时的坐标
} /*                      /  |  \      */
int main() /*左边大图形 中间  右边大图形*/
{
  /*   / | \   /|\     / | \     */
  int n, x, y, stop, i, j, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    n++;
    memset(a, ' ', sizeof(a));
    x = pow(2, n - 1);
    y = (pow(2, n)) - 1;
    int h = x / 2; /*小图形的高宽*/
    int w = y / 2;
    digui(n, x, y, h, w);    /*函数处理*/
    for (i = 1; i <= x; i++) /*输出部分*/
    {
      for (j = 1; j <= pow(2, n) - 1; j++) // 正序输出
      {
        if (a[i][j] == '*')
          stop = j; // 防止后面的空格出现
      }
      for (j = 1; j <= stop; j++) // 在空格出现处停止输出
      {
        printf("%c", a[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
