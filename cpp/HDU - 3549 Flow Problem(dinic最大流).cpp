#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
const int inf = 0x7fffffff;
struct edge /// 链式前向星建图
{
  int to, val, rev; /// rev用于取反边
  edge() {}
  edge(int a, int b, int c) {
    to = a;
    val = b;
    rev = c;
  }
};
vector<edge> mp[maxn];
void add(int from, int to, int val) /// 加边
{
  mp[from].push_back(edge(to, val, mp[to].size())); /// 正边，rev为to的最新边
  mp[to].push_back(
      edge(from, 0, mp[from].size() - 1)); /// 反边，与正边的rev为正边的标号
}
int t, n, m;
int dep
    [20]; /// dep为dinic算法中的分层图的深度，层数为从开始到达该节点最短距离,数组大小为点数多少，此题只有15
int bfs() {
  memset(dep, -1, sizeof dep);
  queue<int> q;
  while (!q.empty())
    q.pop();
  dep[1] = 0;
  q.push(1);
  while (!q.empty()) /// 广搜分层
  {
    int tmp = q.front();
    q.pop();
    if (tmp == n)
      return 1; /// 若广搜还能走到汇点说明可以继续増广
    for (int i = 0; i < mp[tmp].size(); i++) {
      int &to = mp[tmp][i].to, flow = mp[tmp][i].val;
      if (dep[to] == -1 &&
          flow) /// 若该点还没有被分层，没有走到的标记，且有容量，那么走下去
      {
        dep[to] = dep[tmp] + 1;
        q.push(to);
      }
    }
  }
  return 0;
}
int dfs(int s, int t, int flow) /// 多次増广
{
  if (s == t)
    return flow; /// 返回流量
  int pre = 0;
  for (int i = 0; i < mp[s].size(); i++) {
    int &to = mp[s][i].to, val = mp[s][i].val;
    if (dep[s] + 1 == dep[to] &&
        val > 0) /// 下一次増广的节点层数应在该点基础上+1
    {
      int tmp = min(flow - pre, val);  /// 流量和剩余容量取最小值
      int sub = dfs(to, t, tmp);       /// 不断通过bfs向下流，且过滤流量
      mp[s][i].val -= sub;             /// 正向边-
      mp[to][mp[s][i].rev].val += sub; /// 反向边+
      pre += sub;
      if (pre == flow)
        return pre; /// 多次増广总流量
    }
  }
  return pre;
} /// 分层后每次増广多条链
int dinic() {
  int ans = 0;
  while (bfs())
    ans += dfs(1, n, inf);
  return ans;
}
int main() {
  int cas = 1;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i <= n; i++)
      mp[i].clear();
    int from, to, val;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &from, &to, &val);
      add(from, to, val);
    }
    printf("Case %d: %d\n", cas++, dinic());
  }
}
