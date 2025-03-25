#include <algorithm>
#include <stdio.h>
using namespace std;
struct day {
  int x, y;
} xa[108], ya[109];
int main() {
  int t, i, j, m, n, xn, yn;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d", &n, &m, &xn, &yn);
    for (i = 1; i <= xn; i++) {
      scanf("%d%d", &xa[i].x, &xa[i].y);
    }
    for (i = 1; i <= yn; i++) {
      scanf("%d%d", &ya[i].x, &ya[i].y);
    }
    int ans = 0;
    for (i = 1; i <= xn; i++) {
      for (j = 1; j <= yn; j++) {
        int maxn = max(xa[i].x, ya[j].x);
        int minn = min(xa[i].y, ya[j].y);
        if (minn - maxn + 1 < m)
          continue;
        ;
        ans =
            ans +
            (minn - maxn + 2 -
             m); /// minn-maxn=相差天数，实际经过天数=相差天数+1，获得友好点数=实际经过天数-m(获得点数天数)+1(前m天被减去，加上这m天获得的1个点数)
      } /// 除去m天获得的1个点数，剩余连续天数每天获得1个点数，结果化简为minn-maxn+1-m+1
    }
    printf("%d\n", ans);
  }
  return 0;
}
