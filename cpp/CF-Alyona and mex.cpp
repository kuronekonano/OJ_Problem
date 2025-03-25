#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int n, m, l, i, r;
  while (scanf("%d%d", &n, &m) != EOF) /// 找最小区间
  {
    int ans = 0x7fffffff;
    for (i = 0; i < m; i++) {
      scanf("%d%d", &l, &r);
      ans = min(ans, r - l + 1);
    }
    printf("%d\n", ans);
    for (i = 0; i < n; i++) {
      printf(
          "%d%c", i % ans,
          i == n - 1
              ? '\n'
              : ' '); /// 默认为，所有区间最小值都相同，也就是说，从0开始一直到最小区间的长度，然后又从0开始
    }
  }
  return 0;
}
