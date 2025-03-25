#include <bits/stdc++.h> ///题目要求每次减n-1朵花，那么相当于每次有一朵花高度增加1，于是让花排序后求所有花与最高花的差距，即让所有花平等的次数
#define LL                                                                     \
  long long /// 但这个可能是超出剪花次数的，导致-1，因此对于排序后的花高度，如果有超过3朵都小于这个次数，那么不可避免的会有某朵花被剪成负数
#define M(a, b)                                                                \
  memset(                                                                      \
      a, b,                                                                    \
      sizeof a) /// 因此只需比较第三短的花是否能承受减那么多次，就比较了前3朵花是否小于被减次数
#define pb(x) push_back
using namespace std;
const int maxn = 1e5 + 7;
const int mod = 1000000007;
int t, n;
LL a[maxn];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    int ma = a[n];
    LL ans = 0;
    for (int i = 1; i < n; i++)
      ans += ma - a[i];
    if (ans > a[3])
      printf("-1\n");
    else
      printf("%lld\n", ans);
  }
}
