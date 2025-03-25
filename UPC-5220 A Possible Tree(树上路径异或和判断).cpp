#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1e5 + 7;
int n, t, q;
struct edge {
  int to;
  LL val;
  edge() {}
  edge(int a, LL b) {
    to = a;
    val = b;
  }
};
vector<edge> mp[maxn];
int z[maxn];
LL sum[maxn];
bool vis[maxn];
int finds(int x) { return z[x] == x ? x : z[x] = finds(z[x]); }
void dfs(int rt, int fa) {
  if (vis[rt])
    return;
  vis[rt] = true;
  for (int i = 0; i < mp[rt].size(); i++) {
    edge tmp = mp[rt][i];
    if (tmp.to == fa)
      continue;
    sum[tmp.to] = sum[rt] ^ tmp.val; /// 异或路径和
    dfs(tmp.to, rt);
  }
  return;
}
int from[maxn], to[maxn];
LL val[maxn];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &q);
    for (int i = 0; i <= n; i++)
      mp[i].clear(), z[i] = i, vis[i] = false, sum[i] = 0; /// 初始化
    for (int i = 0; i < n - 1; i++)
      scanf("%*d%*d");
    for (
        int i = 1; i <= q;
        i++) { /// 真正有效的是给了路径异或和的信息，那么，就把所有可能的路径异或和都认为是正确的
      scanf(
          "%d%d%lld", &from[i], &to[i],
          &val[i]); /// 有q条不确定正确与否的异或路径，但其实上面给出的树图没有给出边权所以没有什么用
      int fx = finds(from[i]),
          fy = finds(to[i]); /// 并查集判断是否有环，有环不建边
      if (fx !=
          fy) /// 给出的q条可能路径，首先因为肯定联通并且只有唯一路径，那么这条边实际上是有效的，只是不确定异或和正确与否
      {
        z[fy] = fx;
        mp[from[i]].pb(edge(to[i], val[i]));
        mp[to[i]].pb(edge(from[i], val[i]));
      } /// 如果需要最大化正确的路径异或和的条数，那就将前几条默认是对的，在此基础上建图去判断后面其他条，这样顺序判断下去一定是最大的条数
    }
    for (
        int i = 1; i <= q;
        i++) /// 因为q条可能给出来的并不是一颗完整的树，可能是多棵，所以要带标记的深搜每颗树算到异或路径和
      if (!vis[from[i]])
        dfs(from[i], 0);
    int ans = 0;
    for (
        int i = 1; i <= q;
        i++) /// 最后得到所有建立在前几条可能异或和的树上判断往后最多有多少条可行即可
      if ((sum[from[i]] ^ sum[to[i]]) != val[i])
        break;
      else
        ans++;
    printf("%d\n", ans);
  }
}
