#include <algorithm>
#include <map>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
const int maxn = 30;
int n, z[maxn];
struct road {
  int from, to, val;
  road() {};
  road(int a, int b, int c) {
    from = a;
    to = b;
    val = c;
  }
} edge[maxn * maxn >> 1];
bool cmp(road a, road b) { return a.val < b.val; }
int Find(int x) { return z[x] == x ? x : Find(z[x]); }
void join(int x, int y) { z[Find(x)] = z[y]; }
map<string, int> mp;
int main() {
  int t;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    mp.clear();
    int num = 0, m = 0;
    for (int i = 0; i <= n; i++)
      z[i] = i;
    for (int i = 1; i < n; i++) {
      int val;
      char name[3], name2[3];
      scanf("%s", name);
      if (!mp[name])
        mp[name] = ++num;
      scanf("%d", &t);
      for (int j = 1; j <= t; j++) {
        scanf("%s", name2);
        if (!mp[name2])
          mp[name2] = ++num;
        scanf("%d", &val);
        edge[m++] = road(mp[name], mp[name2], val);
      }
    }
    int ans = 0, cnt = 0;
    sort(edge, edge + m, cmp);
    for (int i = 0; i < m; i++) {
      if (Find(edge[i].from) != Find(edge[i].to)) {
        cnt++;
        join(edge[i].from, edge[i].to);
        ans += edge[i].val;
      }
    }
    printf("%d\n", ans);
  }
}
