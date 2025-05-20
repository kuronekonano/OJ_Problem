#include <algorithm> ///超出范围则按下一个大范围来计数
#include <stdio.h> ///按照左边界温度排序后依次更新在范围内交叉的温度范围，并且缩小合并在一起后的范围
using namespace std;
struct tem {
  int l, r;
} a[105];
bool cmp(tem a, tem b) { return a.l < b.l; }
int main() {
  int n, i;
  while (scanf("%d", &n) != EOF) {
    int ans = 1;
    for (i = 1; i <= n; i++)
      scanf("%d%d", &a[i].l, &a[i].r);
    sort(a + 1, a + n + 1, cmp);
    int tml = a[1].l, tmr = a[1].r;
    for (i = 2; i <= n; i++) {
      if (a[i].l <= tmr) {
        tml = max(a[i].l, tml);
        tmr = min(a[i].r, tmr);
      } else {
        ans++;
        tml = a[i].l;
        tmr = a[i].r;
      }
    }
    printf("%d\n", ans);
  }
}
