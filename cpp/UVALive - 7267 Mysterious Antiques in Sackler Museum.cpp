#include <stdio.h>
bool judge(int x1, int y1, int x2, int y2, int x3, int y3) {
  if (x1 == x2 && x2 == x3 || x1 == x2 && x2 == y3 || x1 == y2 && y2 == x3 ||
      x1 == y2 && y2 == y3 || y1 == x2 && x2 == x3 || y1 == x2 && x2 == y3 ||
      y1 == y2 && y2 == x3 || y1 == y2 && y2 == y3)
    return true; /// 重叠在一起

  if (x1 == x2 && y1 + y2 == x3 || x1 == x2 && y1 + y2 == y3)
    return true; /// 两边加和后等于另一个矩形的边
  if (x1 == y2 && y1 + x2 == x3 || x1 == y2 && y1 + x2 == y3)
    return true;

  if (y1 == x2 && x1 + y2 == x3 || y1 == x2 && x1 + y2 == y3)
    return true;
  if (y1 == y2 && x1 + x2 == x3 || y1 == y2 && x1 + x2 == y3)
    return true;

  if (x1 == x3 && y1 + y3 == x2 || x1 == x3 && y1 + y3 == y2)
    return true;
  if (x1 == y3 && y1 + x3 == x2 || x1 == y3 && y1 + x3 == y2)
    return true;

  if (y1 == x3 && x1 + y3 == x2 || y1 == x3 && x1 + y3 == y2)
    return true;
  if (y1 == y3 && x1 + x3 == x2 || y1 == y3 && x1 + x3 == y2)
    return true;

  if (x2 == x3 && y2 + y3 == x1 || x2 == x3 && y2 + y3 == y1)
    return true;
  if (x2 == y3 && y2 + x3 == x1 || x2 == y3 && y2 + x3 == y1)
    return true;

  if (y2 == x3 && x2 + y3 == x1 || y2 == x3 && x2 + y3 == y1)
    return true;
  if (y2 == y3 && x2 + x3 == x1 || y2 == y3 && x2 + x3 == y1)
    return true;

  return false;
}
int main() {
  int t, i, a[4], b[4], j;
  scanf("%d", &t);
  while (t--) {
    for (i = 0; i < 4; i++) {
      scanf("%d%d", &a[i], &b[i]);
    }
    bool flag = false;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        if (j != i) {
          for (int k = 0; k < 4; k++) {
            if (k != i && k != j) {
              flag = judge(a[i], b[i], a[j], b[j], a[k], b[k]);
              if (flag)
                break;
            }
          }
        }
        if (flag)
          break;
      }
      if (flag)
        break;
    }
    printf("%s\n", flag ? "Yes" : "No");
  }
}
