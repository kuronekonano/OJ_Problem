#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 108;
const int inf = 0x3f3f3f3f;
struct edge {
  int to, val, nxt;
  edge() {}
  edge(int a, int b, int c) { to = a, val = b, nxt = c; }
} mp[maxn * 20];
int head[maxn], cnt;
int n, m;
void addedge(int from, int to, int val) {
  mp[cnt] = edge(to, val, head[from]);
  head[from] = cnt++;
  mp[cnt] = edge(from, 0, head[to]);
  head[to] = cnt++;
}
struct node {
  int from, to, val;
  bool operator<(const node &a) const { return val < a.val; }
} a[maxn * 5];
int dep[maxn];
bool bfs(int st, int ed) {
  M(dep, -1);
  queue<int> q;
  while (!q.empty())
    q.pop();
  dep[st] = 0;
  q.push(st);
  while (!q.empty()) {
    int tmp = q.front();
    q.pop();
    if (tmp == ed)
      return true;
    for (int i = head[tmp]; i != -1; i = mp[i].nxt) {
      int &to = mp[i].to, flow = mp[i].val;
      if (dep[to] == -1 && flow) {
        dep[to] = dep[tmp] + 1;
        q.push(to);
        if (to == ed)
          return true;
      }
    }
  }
  return false;
}
int cur[maxn];
int dfs(int s, int t, int flow) {
  if (s == t || flow == 0)
    return flow;
  int pre = 0;
  for (int &i = cur[s]; i != -1; i = mp[i].nxt) {
    int &to = mp[i].to, val = mp[i].val;
    if (dep[s] + 1 == dep[to] && val) {
      int tmp = min(flow - pre, val);
      int sub = dfs(to, t, tmp);
      mp[i].val -= sub;
      mp[i ^ 1].val += sub;
      pre += sub;
      if (pre == flow)
        return pre;
    }
  }
  return pre;
}
int dinic(int st, int ed) {
  int ans = 0;
  while (bfs(st, ed)) {
    for (int i = 1; i <= n; i++)
      cur[i] = head[i];
    ans += dfs(st, ed, inf);
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
    scanf("%d%d%d", &a[i].from, &a[i].to, &a[i].val);
  sort(a + 1, a + 1 + m);
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    cnt = 0, M(head, -1);
    for (int j = 1; j < i; j++)
      if (a[i].val != a[j].val)
        addedge(a[j].from, a[j].to, 1), addedge(a[j].to, a[j].from, 1);
    ans += dinic(a[i].from, a[i].to);
  }
  printf("%d\n", ans);
}
