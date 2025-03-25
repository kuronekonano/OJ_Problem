#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
using namespace std;
const int maxn = 1e5 + 7;
int t;
int a[8][3][3];
bool check(int x, int y) {
  if (a[x][1][1] == a[x][1][2] && a[x][1][1] == a[x][2][1] &&
      a[x][1][1] == a[x][2][2] && a[y][1][1] == a[y][1][2] &&
      a[y][1][1] == a[y][2][1] && a[y][1][1] == a[y][2][2])
    return true;
  return false;
}
bool judge(int x, int y, int x1, int x2, int x3, int x4, int y1, int y2, int y3,
           int y4) {
  if (a[x][x1][x2] == a[y][y1][y2] && a[x][x1][x2] == a[y][y3][y4] &&
      a[x][x1][x2] == a[x][x3][x4])
    return true;
  return false;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    for (int i = 1; i <= 6; i++)
      for (int j = 1; j <= 2; j++)
        for (int k = 1; k <= 2; k++)
          scanf("%d", &a[i][j][k]);
    if (check(1, 2) && check(3, 4) && check(5, 6))
      puts("YES");
    else {
      if (check(1, 3)) {
        if (judge(4, 5, 1, 2, 1, 1, 1, 2, 2, 2) &&
            judge(5, 2, 1, 1, 2, 1, 1, 2, 1, 1) &&
            judge(2, 6, 2, 2, 2, 1, 1, 1, 2, 1) &&
            judge(6, 4, 1, 2, 2, 2, 2, 2, 2, 1)) {
          puts("YES");
          continue;
        }
        if (judge(4, 6, 1, 2, 1, 1, 1, 1, 2, 1) &&
            judge(6, 2, 1, 2, 2, 2, 1, 2, 1, 1) &&
            judge(2, 5, 2, 2, 2, 1, 1, 2, 2, 2) &&
            judge(5, 4, 1, 1, 2, 1, 2, 2, 2, 1)) {
          puts("YES");
          continue;
        }
      }
      if (check(2, 4)) {
        if (judge(1, 5, 1, 2, 1, 1, 2, 2, 2, 1) &&
            judge(5, 3, 1, 2, 1, 1, 1, 2, 1, 1) &&
            judge(3, 6, 2, 2, 2, 1, 2, 1, 2, 2) &&
            judge(6, 1, 1, 2, 1, 1, 2, 2, 2, 1)) {
          puts("YES");
          continue;
        }
        if (judge(1, 6, 1, 2, 1, 1, 2, 2, 2, 1) &&
            judge(6, 3, 1, 1, 1, 2, 1, 2, 1, 1) &&
            judge(3, 5, 2, 2, 2, 1, 2, 1, 2, 2) &&
            judge(5, 1, 1, 1, 1, 2, 2, 2, 2, 1)) {
          puts("YES");
          continue;
        }
      }
      if (check(5, 6)) {
        if (judge(1, 4, 1, 2, 2, 2, 1, 1, 2, 1) &&
            judge(4, 3, 2, 2, 1, 2, 2, 1, 1, 1) &&
            judge(3, 2, 2, 2, 1, 2, 2, 1, 1, 1) &&
            judge(2, 1, 2, 2, 1, 2, 2, 1, 1, 1)) {
          puts("YES");
          continue;
        }
        if (judge(1, 2, 1, 2, 2, 2, 1, 1, 2, 1) &&
            judge(2, 3, 1, 2, 2, 2, 1, 1, 2, 1) &&
            judge(3, 4, 1, 2, 2, 2, 1, 1, 2, 1) &&
            judge(4, 1, 1, 2, 2, 2, 1, 1, 2, 1)) {
          puts("YES");
          continue;
        }
      }
      puts("NO");
    }
  }
}
