#include <bits/stdc++.h>
using namespace std;
const int maxn = 102;
struct road {
  int from, to;
  double dis;
  road() {}
  road(int a, int b, double c) {
    from = a;
    to = b;
    dis = c;
  }
} edge[maxn * maxn >> 1];
bool cmp(road a, road b) { return a.dis - b.dis < 0.000000000000001; }
int t, c, z[maxn];
int Find(int n) { return z[n] == n ? n : Find(z[n]); }
void join(int x, int y) { z[Find(x)] = z[y]; }
double dist(double a, double b, double x, double y) {
  return sqrt((a - x) * (a - x) + (b - y) * (b - y));
}
double x[102], y[102];
int main() {
  scanf("%d", &t);
  while (t--) {
    int m = 0;
    scanf("%d", &c);
    for (int i = 1; i <= c; i++) {
      scanf("%lf%lf", &x[i], &y[i]);
      for (int j = 1; j < i; j++) {
        double tmp = dist(x[i], y[i], x[j], y[j]);
        //                printf("......%f\n",tmp);
        if (tmp >= 10 && tmp <= 1000)
          edge[m++] = road(i, j, tmp);
      }
    }
    sort(edge, edge + m, cmp);
    for (int i = 0; i <= c; i++)
      z[i] = i;
    double ans = 0;
    int cnt = 0;
    //        printf("-----%d\n",m);
    for (int i = 0; i < m; i++) {
      if (Find(edge[i].from) != Find(edge[i].to)) {
        cnt++;
        join(edge[i].from, edge[i].to);
        ans += edge[i].dis;
      }
    }
    int flag = 0;
    for (int i = 1; i <= c; i++)
      if (z[i] == i)
        flag++;
    if (flag == 1)
      printf("%.1f\n", ans * 100);
    else
      printf("oh!\n");
  }
}
