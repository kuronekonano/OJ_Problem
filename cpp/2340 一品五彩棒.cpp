#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int n, a[3002], vis[2000006];
int main() {
  while (scanf("%d", &n) != EOF) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]),
          vis[1000000 +
              a[i]]++; /// 哈希记录1000000正负数出现的次数，判断该数是否可用
    sort(a, a + n);
    int num = 0;
    int pre1, pre2;
    pre1 = pre2 =
        0x3f3f3f3f; /// 记录上一个输出的数，下一组满足条件的数不能和上一组前两个数相等，否则会重复0
                    /// 0 0
    for (int i = 0; i < n && a[i] <= 0; i++) {
      while (i < n && a[i] == pre1)
        ++i; /// 跨越不可用的数
      vis[1000000 + a[i]]--;
      pre2 = 0x3f3f3f3f;
      for (int j = i + 1; j < n; j++) {
        while (j < n && a[j] == pre2)
          ++j;
        if (j == n)
          break; /// 判断是否还有数可用，否则直接跳出
        vis[1000000 + a[j]]--;
        if (vis[1000000 - a[i] - a[j]] > 0 && 0 - a[i] - a[j] >= a[j]) {
          printf("%d %d %d\n", a[i], a[j], 0 - a[i] - a[j]);
          pre1 = a[i];
          pre2 = a[j];
        }
        vis[1000000 + a[j]]++;
      }
      vis[1000000 + a[i]]++;
    }
  }
}
