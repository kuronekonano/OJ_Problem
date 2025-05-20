#include <algorithm>
#include <stdio.h> ///树上任意两点的异或和，可根据两点到根节点的异或和 异或得到
#include <string.h>
#include <vector>
#define LL long long
using namespace std;
const int maxn = 100005;
struct edge {
  int to, val;
  edge() {}
  edge(int a, int b) {
    to = a;
    val = b;
  }
};
int n, t;
int xorsum[maxn], cnt[40];
vector<edge> q[maxn];
void dfs(int rt, int pre) {
  for (int i = 0; i < q[rt].size(); i++) {
    edge tmp = q[rt][i];
    if (tmp.to != pre) {
      xorsum[tmp.to] = xorsum[rt] ^ tmp.val; /// 根节点到每个节点的异或和
      dfs(tmp.to, rt);
    }
  }
  for (int i = 0; i < 31; i++)
    if (xorsum[rt] & (1 << i))
      cnt[i + 1]++; /// 记录每个异或和的二进制位上1出现的次数
}
LL binary[40];
int main() {
  for (int i = 0; i < 31; i++)
    binary[i + 1] = 1 << i;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof cnt);
    int from, to, val;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
      q[i].clear();
    for (int i = 1; i < n; i++) {
      scanf("%d%d%d", &from, &to, &val);
      q[from].push_back(edge(to, val));
      q[to].push_back(edge(from, val));
    }
    xorsum[1] = 0;
    dfs(1, 0);
    LL ans = 0;
    for (int i = 1; i <= 31; i++)
      ans += binary[i] * (n - cnt[i]) * cnt[i];
    printf("%lld\n", ans);
  }
}
/// 得到根节点到每个节点位置的异或和后，那么计算任意两点的异或和只需要将任意两路径异或和进行异或操作，又因为我们要计算的是所有路径异或和的加和
/// 因此任意两结点路径异或之后，只取二进制位上位1的值计算，那么只有0和1进行异或才会在二进制位上得到1，直接用所有1和0匹配，得到异或出1的情况数量，转换为十进制求和。
