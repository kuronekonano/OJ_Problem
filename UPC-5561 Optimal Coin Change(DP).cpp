#include <bits/stdc++.h> ///DP
using namespace std;
const int maxn = 10004;
int cnt[maxn], a[maxn], val[maxn], fa[maxn], ans[maxn];
int main() {
  int sum, n;
  while (scanf("%d%d", &sum, &n) != EOF) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    memset(cnt, 0x3f, sizeof(cnt));
    memset(ans, 0, sizeof(ans));
    cnt[0] = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = a[i]; j <= sum; j++) /// 遍历每个面值能的价格
      {
        if (cnt[j] >=
            cnt[j - a[i]] + 1) /// 取等于则按较少钱币分配，否则按较多钱币分配
        {                      /// 若能延续用这么多钱
          cnt[j] = cnt[j - a[i]] + 1; /// 在此标记记录
          fa[j] = j - a[i];           /// 记录到达sum的路径
          val[j] = i;                 /// 对于每个位置用了哪个面值的记录
        }
      }
    }
    if (cnt[sum] == cnt[sum + 3]) /// 如果未曾凑到sum说明怎么都凑不够
    {
      printf("-1\n");
      continue;
    }
    while (sum) /// 否则按照路径记录对用到的每个面值计数
    {
      ans[val[sum]]++;
      sum = fa[sum];
    }
    for (int i = 0; i < n; i++)
      printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
  }
}
