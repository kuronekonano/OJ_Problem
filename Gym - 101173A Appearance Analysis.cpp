#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  int xx, yy;
} num[20008];
char a[150][150];
bool judge1(int x, int y, int n) /// 左上角
{
  bool flag = false;
  int i, j, ii, jj;
  for (i = num[n].x, ii = x; i <= num[n].xx; i++, ii++) {
    for (int j = num[n].y, jj = y; j <= num[n].yy; j++, jj++) {
      if (a[ii][jj] != a[i][j]) {
        flag = true;
        break;
      }
    }
    if (flag)
      break;
  }
  if (!flag)
    return 1;

  flag = false;
  for (i = num[n].yy, ii = x; i >= num[n].y; i--, ii++) /// 右上角
  {
    for (int j = num[n].x, jj = y; j <= num[n].xx; j++, jj++) {
      if (a[ii][jj] != a[j][i]) {
        flag = true;
        break;
      }
    }
    if (flag)
      break;
  }
  if (!flag)
    return 1;

  flag = false;
  for (i = num[n].xx, ii = x; i >= num[n].x; i--, ii++) /// 右下角
  {
    for (int j = num[n].yy, jj = y; j >= num[n].y; j--, jj++) {
      if (a[ii][jj] != a[i][j]) {
        flag = true;
        break;
      }
    }
    if (flag)
      break;
  }
  if (!flag)
    return 1;

  flag = false;
  for (i = num[n].y, ii = x; i <= num[n].yy; i++, ii++) /// 左下角
  {
    for (int j = num[n].xx, jj = y; j >= num[n].x; j--, jj++) {
      if (a[ii][jj] != a[j][i]) {
        flag = true;
        break;
      }
    }
    if (flag)
      break;
  }
  if (!flag)
    return 1;

  return 0;
}
bool judge2(int x, int y, int n) /// 左上角
{
  int i, j, ii, jj;
  bool flag = false;
  for (i = num[n].x, ii = x; i <= num[n].xx; i++, ii++) {
    for (j = num[n].y, jj = y; j <= num[n].yy; j++, jj++) {
      if (a[ii][jj] != a[i][j]) {
        flag = true;
        break;
      }
    }
    if (flag)
      break;
  }
  if (!flag)
    return 1;

  flag = false;
  for (i = num[n].xx, ii = x; i >= num[n].x; i--, ii++) /// 右下角
  {
    for (j = num[n].yy, jj = y; j >= num[n].y; j--, jj++) {
      if (a[ii][jj] != a[i][j]) {
        flag = true;
        break;
      }
    }
    if (flag)
      break;
  }
  if (!flag)
    return 1;

  return 0;
}
int main() {
  int r, c, i, j, k;
  while (scanf("%d%d", &c, &r) != EOF) {
    memset(a, 0, sizeof(a));
    int cn = 0, rn = 0;
    for (i = 0; i < c; i++) {
      scanf("%s", &a[i]);
      if (a[i][1] == '#')
        cn++;
    }
    for (i = 0; i < r; i++)
      if (a[1][i] == '#')
        rn++;
    cn = (c - cn) / (cn - 1);
    rn = (r - rn) / (rn - 1);
    int ans = 1;
    num[ans].x = 1;
    num[ans].y = 1;
    num[ans].xx = num[ans].x + cn - 1;
    num[ans].yy = num[ans].y + rn - 1;
    if (cn == rn) {
      for (i = 1; i < c; i += cn + 1) /// 大图形
      {
        for (j = 1; j < r; j += rn + 1) {
          bool flag2 = false;
          for (int n = 1; n <= ans; n++) /// 从ans中选择图形比较
          {
            if (judge1(i, j, n) != 0) {
              flag2 = true;
              break;
            }
          }
          if (!flag2) {
            ans++;
            num[ans].x = i;
            num[ans].y = j;
            num[ans].xx = num[ans].x + cn - 1;
            num[ans].yy = num[ans].y + rn - 1;
          }
        }
      }
      printf("%d\n", ans);
    } else {
      for (i = 1; i < c; i += cn + 1) /// 大图形
      {
        for (j = 1; j < r; j += rn + 1) {
          bool flag2 = false;
          for (int n = 1; n <= ans; n++) /// 从ans中选择图形比较
          {
            if (judge2(i, j, n) != 0) {
              flag2 = true;
              break;
            }
          }
          if (!flag2) {
            ans++;
            num[ans].x = i;
            num[ans].y = j;
            num[ans].xx = num[ans].x + cn - 1;
            num[ans].yy = num[ans].y + rn - 1;
          }
        }
      }
      printf("%d\n", ans);
    }
  }
}
/*
11 16
################
#....#++++#+...#
#....#++.+#+...#
#....#.++.#++.+#
#....#....#++++#
################
#....#.+..#++++#
#..++#.+..#++.+#
#+...#....#.++.#
#+...#..++#....#
################

9 21
#####################
#...+#++++#+...#..+.#
#..+.#.++.#.+..#..+.#
#.+..#....#..+.#..+.#
#####################
#.+..#....#..+.#.+..#
#..+.#.++.#.+..#.+..#
#...+#++++#+...#.+..#
#####################

11 16
################
#+..+#+..+#+...#
#....#....#+...#
#....#....#++.+#
#...+#...+#..++#
################
#....#.+..#++++#
#+.++#.+..#++.+#
#+...#.+..#.++.#
#+...#..++#....#
################
*/
