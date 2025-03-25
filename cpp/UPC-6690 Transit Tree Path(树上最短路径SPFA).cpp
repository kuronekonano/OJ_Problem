#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 10;
const LL inf = 1000000000000000;
int n;
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
bool vis[maxn];
LL dist[maxn];
void SPFA(int s) {
  queue<int> q;
  while (!q.empty())
    q.pop();
  for (int i = 0; i <= n; i++)
    dist[i] = inf;
  memset(vis, false, sizeof vis);
  dist[s] = 0;
  vis[s] = true;
  q.push(s);
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    vis[top] = false;
    for (int i = 0; i < mp[top].size(); i++) {
      int v = mp[top][i].to;
      if (dist[v] > dist[top] + mp[top][i].val) {
        dist[v] = dist[top] + mp[top][i].val;
        if (!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
    }
  }
}
int main() {
  while (scanf("%d", &n) != EOF) {
    int from, to;
    LL val;
    for (int i = 0; i < n - 1; i++) {
      scanf("%d%d%d", &from, &to, &val);
      mp[from].push_back(edge(to, val));
      mp[to].push_back(edge(from, val));
    }
    int q, k;
    scanf("%d%d", &q, &k);
    SPFA(k);
    for (int i = 0; i < q; i++) {
      scanf("%d%d", &from, &to);
      printf("%lld\n", dist[from] + dist[to]);
    }
  }
}
