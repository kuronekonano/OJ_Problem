#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 1e5 + 10;
int num[maxn], n;
int tre[maxn << 4][2];
int tot;
void insert(int a, int rt) {
  for (int i = 31; i >= 0; i--) {
    int x = (a >> i) & 1;
    if (!tre[rt][x])
      tre[rt][x] = ++tot; /// 创建节点
    rt = tre[rt][x];
  }
}
int finds(int a, int rt) {
  int res = 0;
  for (int i = 31; i >= 0; i--) /// 从高位遍历二进制
  {
    int x = (a >> i) & 1; /// 判断数值
    res <<= 1;            /// 后移结果
    if (tre[rt][!x])
      rt = tre[rt][!x], res++;
    else
      rt = tre[rt][x];
  }
  return res;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    tot = 0;
    int rt = ++tot;
    memset(tre, 0, sizeof tre);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &num[i]), insert(num[i], rt);
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans = max(ans, finds(num[i], rt));
    printf("%d\n", ans);
  }
  return 0;
}
