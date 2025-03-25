#include <queue>
#include <stdio.h>
#include <string.h>
#include <vector>
#define N 1008
using namespace std;
struct Edge {
  int to, val;
  Edge(int a = 0, int b = 0) : to(a), val(b) {}
  bool operator<(const Edge &a) const {
    if (val == a.val)
      return to < a.to;
    return val > a.val;
  }
};
int n, m, x;
vector<Edge> v[N];
vector<Edge> fv[N];
int dist[N], distf[N];
void dijkstra(int s) {
  memset(distf, 0x3f, sizeof(distf));
  distf[s] = 0;
  priority_queue<Edge> q;
  q.push(Edge(s, 0));
  q.push(Edge(s, 0));
  while (!q.empty()) {
    Edge top = q.top();
    q.pop();
    for (int i = 0; i < fv[top.to].size(); i++) {
      Edge tmp = fv[top.to][i];
      if (distf[tmp.to] > top.val + tmp.val) {
        distf[tmp.to] = top.val + tmp.val;
        q.push(Edge(tmp.to, distf[tmp.to]));
      }
    }
  }
}
void dijkstra_back(int s) {
  memset(dist, 0x3f, sizeof(dist));
  dist[s] = 0;
  priority_queue<Edge> q;
  q.push(Edge(s, 0));
  q.push(Edge(s, 0));
  while (!q.empty()) {
    Edge top = q.top();
    q.pop();
    for (int i = 0; i < v[top.to].size(); i++) {
      Edge tmp = v[top.to][i];
      if (dist[tmp.to] > top.val + tmp.val) {
        dist[tmp.to] = top.val + tmp.val;
        q.push(Edge(tmp.to, dist[tmp.to]));
      }
    }
  }
}
int main() {
  while (scanf("%d%d%d", &n, &m, &x) != EOF) {
    for (int i = 0; i < N; i++)
      v[i].clear();
    for (int i = 0; i < N; i++)
      fv[i].clear();
    int from, to, val;
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &from, &to, &val);
      v[from].push_back(Edge(to, val));
      fv[to].push_back(Edge(from, val));
    }
    dijkstra(x);
    dijkstra_back(x);
    int ans = 0;
    for (int i = 1; i <= n; i++)
      if (ans < dist[i] + distf[i])
        ans = dist[i] + distf[i];
    printf("%d\n", ans);
  }
}
