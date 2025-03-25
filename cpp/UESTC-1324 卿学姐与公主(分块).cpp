#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 1e5 + 10;
int block, belong[maxn], l[maxn], r[maxn], n, q, num;
long long a[maxn], Max[maxn];
int build() {
  block = sqrt(n); /// 分成sqrt(n)块，也就是block是每块的个数
  num = n / block; /// num表示被分成的块数
  if (num % block)
    num++; /// 余下的个数不足block个，剩余的单独分成一块
  for (
      int i = 1; i <= num;
      i++) /// 给每块边上边界，每块的左边界等于i-1倍的block(个数)+1，即第i块的第一个数
    l[i] = (i - 1) * block + 1,
    r[i] = i * block;          /// 右边界即完整的i*block的个数
  r[num] = n;                  /// 最后一块的右边界直接标记为总值n
  for (int i = 1; i <= n; i++) /// 给每个数标记该数属于哪个块
    belong[i] =
        (i - 1) / block + 1;     /// 第i个数(i从1开始)属于第(i-1)/blcok+1的块
  for (int i = 1; i <= num; i++) /// 初始化每块的最大值
  {
    /// 遍历num个块
    for (int j = l[i]; j <= r[i];
         j++) /// 对于每个块从左边界遍历到右边界，取最大值记录
      Max[i] = max(Max[i], a[j]);
  }
}
void updata(int x, int y) /// 更新
{
  a[x] += y;
  Max[belong[x]] = max(Max[belong[x]], a[x]);
}
long long query(int x, int y) /// 查询
{
  long long ans = 0;
  if (belong[x] == belong[y]) /// 若查询的区间同块
  {
    for (int i = x; i <= y; i++) /// 小范围直接遍历
      ans = max(ans, a[i]);
    return ans;
  }
  for (int i = x; i <= r[belong[i]]; i++) /// 查询的区间不同块，先对左区间遍历
    ans = max(ans, a[i]);
  for (int i = belong[x] + 1; i < belong[y];
       i++) /// 中间跨过的整块部分直接对比块的最大值
    ans = max(ans, Max[i]);
  for (int i = l[belong[y]]; i <= y;
       i++) /// 最后没有完整跨越的块要单独从左边界遍历到查询位置
    ans = max(ans, a[i]);
  return ans;
}
int main() {
  scanf("%d%d", &n, &q);
  int flag, x, y;
  memset(a, 0, sizeof(a));
  while (q--) {
    scanf("%d", &flag);
    if (flag == 1) {
      scanf("%d%d", &x, &y);
      updata(x, y);
    } else {
      scanf("%d%d", &x, &y);
      printf("%lld\n", query(x, y));
    }
  }
}
