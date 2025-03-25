#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h> ///并查集
#include <string.h>
#include <string>
#include <vector>
#define LL long long
using namespace std;
struct com {
  double x, y;
} a[1004];
int n, t, ans, d, tmp;
double dis[1005][1008];
vector<int> v[1005];
bool vis[1005];
int x, y;
int zz[1005];
int finds(int x) {
  int r = x, t;
  while (r != zz[r]) {
    t = r;
    r = zz[r];
    zz[t] = zz[r];
  }
  return r;
}
void join(int a, int b) {
  int fa = finds(a), fb = finds(b);
  if (fa != fb) {
    zz[fa] = fb;
  }
}
int main() {
  while (scanf("%d%d", &n, &d) != EOF) {
    memset(vis, false, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++)
      v[i].clear();
    for (int i = 1; i <= n; i++)
      zz[i] = i;
    for (int i = 1; i <= n; i++) {
      scanf("%lf%lf", &a[i].x, &a[i].y);
      for (int j = 1; j < i; j++) {
        dis[i][j] = dis[j][i] = sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) +
                                     (a[i].y - a[j].y) * (a[i].y - a[j].y));
        if (dis[i][j] <= d) /// 将每个电脑周围的可选距离的电脑收入vector中待选
        {
          v[i].push_back(j);
          v[j].push_back(i);
        }
      }
    }
    char flag[3];
    while (scanf("%s", flag) != EOF) {
      if (flag[0] == 'O') {
        scanf("%d", &tmp);
        vis[tmp] = true;
        for (int i = 0; i < v[tmp].size(); i++) {
          if (vis[v[tmp][i]]) {
            //                        printf("%d-------%d\n",vis[v[tmp][i]],v[tmp][i]);
            join(v[tmp][i], tmp);
          }
        }
        //                for(int i=1;i<=n;i++)
        //                {
        //                    printf("%d====>%d\n",i,zz[i]);
        //                }
      } else {
        scanf("%d%d", &x, &y);
        if (finds(x) == finds(y)) {
          printf("SUCCESS\n");
        } else {
          printf("FAIL\n");
        }
      }
    }
  }
  return 0;
}
