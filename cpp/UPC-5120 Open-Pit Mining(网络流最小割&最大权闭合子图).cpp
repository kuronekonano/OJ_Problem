#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 208;
const int inf = 0x3f3f3f3f;
struct edge {
  int to, val, rev;
  edge() {}
  edge(int a, int b, int c) {
    to = a;
    val = b;
    rev = c;
  }
};
vector<edge> mp[maxn];
int n;
inline void add(int from, int to, int val) {
  mp[from].pb(edge(to, val, mp[to].size()));
  mp[to].pb(edge(from, 0, mp[from].size() - 1));
}
int dep[maxn];
bool bfs() {
  memset(dep, -1, sizeof dep);
  queue<int> q;
  while (!q.empty())
    q.pop();
  dep[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int tmp = q.front();
    q.pop();
    if (tmp == n + 1)
      return true;
    for (int i = 0; i < mp[tmp].size(); i++) {
      int &to = mp[tmp][i].to, flow = mp[tmp][i].val;
      if (dep[to] == -1 && flow) {
        dep[to] = dep[tmp] + 1;
        q.push(to);
      }
    }
  }
  /// if(dep[n+1]!=-1)return true;
  return false;
}
int dfs(int s, int t, int flow) {
  if (s == t)
    return flow;
  int pre = 0;
  for (int i = 0; i < mp[s].size(); i++) {
    int &to = mp[s][i].to, val = mp[s][i].val;
    if (dep[s] + 1 == dep[to] && val > 0) {
      int tmp = min(flow - pre, val);
      int sub = dfs(to, t, tmp);
      mp[s][i].val -= sub;
      mp[to][mp[s][i].rev].val += sub;
      pre += sub;
      if (pre == flow)
        return pre;
    }
  }
  return pre;
}
int dinic() {
  int ans = 0;
  while (bfs())
    ans += dfs(0, n + 1, inf);
  return ans;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i <= n + 1; i++)
      mp[i].clear();
    int ci, vi, to, num, val, ans = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d%d", &vi, &ci, &num);
      val = vi - ci; /// 先计算宝石利润
      if (val > 0)
        add(0, i, val), ans += val; /// 正利润连到源点
      else
        add(i, n + 1, -val); /// 负利润连到汇点
      for (int j = 1; j <= num; j++) {
        scanf("%d", &to);
        add(to, i,
            inf); /// 第i个石头压着的石头，从被压的石头连向i一条有向边，容量为无限大
      } /// 表示，要挖该石头就要走一个该石头之上的另一个石头，若该石头是与其之上的石头都是正利润，那么损失为0可以不走到汇点
    }
    printf(
        "%d\n",
        ans -
            dinic()); /// 若该石头是正利润，其上石头是负利润，那么必定会通过这条无穷大容量通路走到汇点，也就是会被其上石头的负利润所限制
  } /// 若该石头负利润，其上石头为正利润，从负利润到正利润有一条有向边，但这条有向边无法从源点流到汇点，因此负利润不会被减到，也就是不挖下面这块石头
}
