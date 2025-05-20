#include <algorithm>
#include <stdio.h>
using namespace std;
const int maxn = 5e4 + 10;
int n, l, m, a[maxn];
bool judge(int mid) {
  int start = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (a[i] - start < mid)
      cnt++;
    else
      start = a
          [i]; /// 理论上还应判断终点与最后一个落脚点的距离要大于最小值，但是题目并没有卡这个问题
  if (cnt > m)
    return false;
  return true;
}
int main() {
  while (scanf("%d%d%d", &l, &n, &m) != EOF) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a, a + n);
    int ll = 0, rr = l, ans = 0;
    while (ll <= rr) {
      int mid = (ll + rr) >> 1;
      if (judge(mid)) {
        ll = mid + 1;
        ans = mid;
      } else
        rr = mid - 1;
    }
    printf("%d\n", ans);
  }
}
