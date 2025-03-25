#include <bits/stdc++.h> ///有n个盒子，每个盒子出现大小为di的概率为pi，按id顺序遍历盒子，每次遇到比当前钻石大的就换掉，问更换次数期望
#define LL                                                                     \
  long long /// 树状数组中存储第id个钻石没有di那么大的概率，那么，当在第id个位置更换成di那么大的钻石，就要保证在这之前的钻石都比di小
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
#define lowbit(x) x & (-x)
using namespace std;
const int maxn = 1e5 + 7;
const int p = 998244353;
LL qp(LL a, LL b) {
  LL ans = 1;
  while (b) {
    if (b & 1)
      ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}
struct node {
  LL val, id, pp;
  bool operator<(const node &a) const {
    if (val == a.val)
      return id < a.id;
    return val > a.val;
  }
} a[maxn];
LL tre[maxn];
int n;
LL inv = qp(
    100,
    p - 2); /// 注意题目给出的都是*100之后的概率，因此要*100的逆元才是真正的概率
void update(int pos, LL val) {
  for (int i = pos; i <= n; i += lowbit(i))
    tre[i] = tre[i] * val % p; /// 树状数组计算前缀乘
}
LL query(int pos) {
  LL ans = 1;
  for (int i = pos; i; i -= lowbit(i))
    ans = ans * tre[i] % p;
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%lld%lld", &a[i].pp, &a[i].val), a[i].id = i;
  sort(a + 1, a + 1 + n);
  fill_n(tre, n, 1LL); /// 初始化全为1
  LL ans = 0;
  for (int i = 1; i <= n; i++) /// 按钻石从大到小的顺序更新树状数组，这样每次查询时都是查询该id之前，没有取得
                               /// 小于自己id，且大小比自己大的钻石的概率
  {
    ans = (ans + query(a[i].id - 1) * a[i].pp % p * inv % p) %
          p; /// 先查询比自己小的id的比自己大的钻石不取的概率
    update(a[i].id, ((LL)100 - a[i].pp) * inv %
                        p); /// 然后再更新取不到该钻石的概率到树状数组中
  }
  printf("%lld\n", ans);
}
