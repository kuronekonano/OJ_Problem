#include <queue>
#include <stdio.h> ///多源最短路径
#include <string.h>
#include <vector>
using namespace std;
const int maxn = 1e5 + 10;
struct edge {
  int to, val;
  edge() {}
  edge(int a, int b) {
    to = a;
    val = b;
  }
};
vector<edge> mp[maxn];
int n, m, s, e;
bool vis[maxn];
int dist[maxn];
void SPFA(int s) {
  queue<int> q;
  while (!q.empty())
    q.pop();
  memset(dist, 0x7f, sizeof dist);
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
  while (scanf("%d%d", &n, &m) != EOF) {
    int from, to, val;
    for (int i = 0; i <= n; i++)
      mp[i].clear();
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &from, &to, &val);
      mp[from].push_back(edge(to, val));
    }
    int tmp;
    scanf("%d", &s); /// 多个起点，建立超级起点连接，边权为0
    for (int i = 0; i < s; i++)
      scanf("%d", &tmp), mp[0].push_back(edge(tmp, 0));
    scanf("%d", &e); /// 多个终点，建立超级终点连接，边权为0
    for (int i = 0; i < e; i++)
      scanf("%d", &tmp), mp[tmp].push_back(edge(n + 1, 0));
    SPFA(0);
    printf("%d\n", dist[n + 1]);
  }
}
