#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
double dist[maxn], mp[maxn][maxn];
bool vis[maxn];
int n;
void SPFA(int s) {
  queue<int> q;
  while (!q.empty())
    q.pop();
  for (int i = 0; i <= n; i++)
    dist[i] = 1e14;
  memset(vis, false, sizeof vis);
  dist[s] = 0;
  vis[s] = true;
  q.push(s);
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    vis[top] = false;
    for (int i = 1; i <= n; i++) {
      if (dist[i] > dist[top] + mp[top][i]) {
        dist[i] = dist[top] + mp[top][i];
        if (!vis[i]) {
          vis[i] = true;
          q.push(i);
        }
      }
    }
  }
}
double cal(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double line(double a, double b, double c, double x, double y) {
  return fabs(a * x + b * y + c) / sqrt(a * a + b * b);
}
double x[maxn], y[maxn], r[maxn];
int main() {
  double a, b, c1, c2;
  while (scanf("%d%lf%lf%lf%lf", &n, &a, &b, &c1, &c2) != EOF) {
    n += 2;
    r[1] = r[2] = 0;
    mp[2][1] = mp[1][2] = fabs(c1 - c2) / sqrt(a * a + b * b);
    for (int i = 3; i <= n; i++) {
      scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
      mp[1][i] = mp[i][1] = line(a, b, c1, x[i], y[i]);
      if (r[i] >= mp[1][i])
        mp[1][i] = mp[i][1] = 0;
      else
        mp[1][i] = mp[i][1] = mp[1][i] - r[i];
      mp[i][2] = mp[2][i] = line(a, b, c2, x[i], y[i]);
      if (r[i] >= mp[2][i])
        mp[2][i] = mp[i][2] = 0;
      else
        mp[2][i] = mp[i][2] = mp[2][i] - r[i];
      for (int j = 3; j < i; j++) {
        double tmp = cal(x[i], y[i], x[j], y[j]);
        if (r[i] + r[j] >= tmp) {
          if (fabs(r[i] - r[j]) > tmp)
            mp[i][j] = mp[j][i] = fabs(r[i] - r[j]) - tmp;
          else
            mp[j][i] = mp[i][j] = 0;
        } else
          mp[i][j] = mp[j][i] = tmp - r[i] - r[j];
      }
    }
    SPFA(1);
    printf("%f\n", dist[2]);
  }
}
