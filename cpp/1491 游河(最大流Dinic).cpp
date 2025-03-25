#include <bits/stdc++.h>
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
int dep[maxn];
int n, m, d;
vector<edge> mp[maxn];
void add(int from, int to, int val) {
  mp[from].push_back(edge(to, val, mp[to].size()));
  mp[to].push_back(edge(from, val, mp[from].size() - 1));
}
int bfs() {
  memset(dep, -1, sizeof dep);
  queue<int> q;
  while (!q.empty())
    q.pop();
  dep[1] = 0;
  q.push(1);
  while (!q.empty()) {
    int tmp = q.front();
    q.pop();
    if (tmp == n)
      return 1;
    for (int i = 0; i < mp[tmp].size(); i++) {
      int &to = mp[tmp][i].to, flow = mp[tmp][i].val;
      if (dep[to] == -1 && flow) {
        dep[to] = dep[tmp] + 1;
        q.push(to);
      }
    }
  }
  return 0;
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
    ans += dfs(1, n, inf);
  return ans;
}
map<int, int> vis;
int main() {
  while (scanf("%d%d%d", &n, &m, &d) != EOF) {
    int from, to;
    vis.clear();
    for (int i = 0; i <= n; i++)
      mp[i].clear();
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &from, &to);
      vis[from * 300 + to]++; /// 可能是因为数据水，这样加边方式足足加了4次边
    }
    map<int, int>::iterator it;
    for (it = vis.begin(); it != vis.end(); it++)
      add(it->first / 300, it->first % 300, it->second);
    printf("%s\n", dinic() >= d ? "Orz!" : "Jiao Zhu v5!");
  }
}
