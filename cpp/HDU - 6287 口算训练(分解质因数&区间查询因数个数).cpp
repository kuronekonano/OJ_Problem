#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, m;
vector<int> p[maxn];
void prim(int x, int pos) {
  for (int i = 2; i * i <= x; i++) {
    while (x % i == 0) {
      p[i].push_back(pos);
      x /= i;
    }
  }
  if (x > 1)
    p[x].push_back(pos);
}
int check(int l, int r, int x) {
  return upper_bound(p[x].begin(), p[x].end(), r) -
         lower_bound(p[x].begin(), p[x].end(), l);
} /// 直接在某个因数中查询第pos个位置的值被分解出了多少个x，也就是连续多少pos
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < maxn; i++)
      p[i].clear();
    int tmp;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &tmp);
      prim(tmp, i);
    }
    while (m--) {
      int l, r;
      bool ans = true;
      scanf("%d%d%d", &l, &r, &tmp);
      for (int i = 2; i * i <= tmp; i++) {
        int sum = 0;
        while (tmp % i == 0)
          sum++, tmp /= i;
        if (sum > check(l, r, i)) {
          ans = false;
          break;
        }
      }
      if (ans && tmp > 1 && check(l, r, tmp) == 0)
        ans = false;
      printf("%s\n", ans ? "Yes" : "No");
    }
  }
}
