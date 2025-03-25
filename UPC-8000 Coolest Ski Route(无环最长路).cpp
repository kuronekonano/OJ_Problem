#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1e3 + 7;
struct edge {
  int to, val;
  edge() {}
  edge(int a, int b) {
    to = a;
    val = b;
  }
  bool operator<(const edge &a) const { return val < a.val; }
};
int dist[maxn];
vector<edge> mp[maxn];
int n, m;
void dijkstra(int s) {
  M(dist, -1);
  dist[s] = 0;
  priority_queue<edge> q;
  q.push(edge(s, 0));
  while (!q.empty()) {
    edge top = q.top();
    q.pop();
    for (int i = 0; i < mp[top.to].size(); i++) {
      edge tmp = mp[top.to][i];
      if (dist[tmp.to] < top.val + tmp.val) {
        dist[tmp.to] = top.val + tmp.val;
        q.push(edge(tmp.to, dist[tmp.to]));
      }
    }
  }
}
int main() {
  int from, to, val;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &from, &to, &val);
    mp[from].pb(edge(to, val));
  }
  for (int i = 1; i <= n; i++)
    mp[0].pb(edge(i, 0)), mp[i].pb(edge(n + 1, 0));
  dijkstra(0);
  printf("%d\n", dist[n + 1]);
}
