#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 10;
const LL has = 5e5;
int n, l, k;
int road[2 * maxn], rail[2 * maxn];
int find(int z[], int x) /// 比while式的查找更优秀，路径压缩也更快
{
  return z[x] == x ? x : z[x] = find(z, z[x]);
}
void join(int z[], int x, int y) {
  int a = find(z, x), b = find(z, y);
  if (a != b)
    z[a] = b;
}
map<LL, int> ans;
int main() {
  while (scanf("%d%d%d", &n, &k, &l) != EOF) {
    ans.clear();
    for (int i = 0; i <= n; i++)
      rail[i] = i, road[i] = i;
    int from, to;
    for (int i = 0; i < k; i++) {
      scanf("%d%d", &from, &to);
      join(road, from, to);
    }
    for (int i = 0; i < l; i++) {
      scanf("%d%d", &from, &to);
      join(rail, from, to);
    }
    for (int i = 1; i <= n; i++)
      ans[(LL)find(road, i) * has + (LL)find(rail, i)]++;
    for (int i = 1; i <= n; i++)
      printf("%d%c", ans[find(road, i) * has + find(rail, i)],
             i == n ? '\n' : ' ');
  }
}
/*
4 2 2
1 3
2 3
1 4
2 4
*/
