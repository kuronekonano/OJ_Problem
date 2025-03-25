#include <bits/stdc++.h> ///普通的最大流题目，但是数据卡当前弧优化
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 508;
const int inf = 0x3f3f3f3f;
struct edge {
  int to, nxt, val;
  edge() {}
  edge(int a, int b, int c) {
    to = a;
    val = b;
    nxt = c;
  }
} mp[maxn * maxn];
int head[maxn], dep[maxn], cnt;
int n, m, c;
void addedge(int from, int to, int val) {
  mp[cnt] = edge(to, val, head[from]);
  head[from] = cnt++;
  mp[cnt] = edge(from, 0, head[to]);
  head[to] = cnt++;
}
bool bfs(int st, int ed) {
  memset(dep, -1, sizeof dep);
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
int cur[maxn]; /// 当前弧优化数组
int dfs(int s, int t, int flow) {
  if (s == t || flow == 0)
    return flow; /// 当前弧优化
  int pre = 0;
  for (int &i = cur[s]; i != -1;
       i = mp[i].nxt) /// 每次dfs的时候记录遍历优化到那条边了
  {                   /// 如果再次遍历这个点的时候就可以直接取拜访那条边
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
      cur[i] = head[i]; /// 清空当前弧
    ans += dfs(st, ed, inf);
  }
  return ans;
}
int main() {
  int from, to, val, st, ed;
  while (scanf("%d%d%d%d%d", &n, &m, &st, &ed, &c), n || m || st || ed || c) {
    M(head, -1);
    cnt = 0;
    for (int i = 1; i <= m; i++) {
      scanf("%d%d", &from, &to);
      addedge(from, to, 1);
    }
    int sum = dinic(st, ed);
    LL ans = 0;
    LL tmp = c / sum;
    LL mod = c % sum;
    ans +=
        mod * (tmp + 1) * (tmp + 1) * (tmp + 1) + (sum - mod) * tmp * tmp * tmp;
    printf("%lld\n", ans);
  }
}
/*
接下来我们用到了当前弧得优化，引用cur数组，作用是i变化，cur也变化，
就相当与，这个点变关系每一条边在这次所有的dfs中只会出现一次，
*/
