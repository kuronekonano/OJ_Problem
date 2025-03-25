#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 1e5 + 7;
const int mod = 1e9 + 7;
int n, tre[maxn];
int lowbit(int x) { return x & (-x); }
void update(int x, int val) {
  while (x <= maxn) {
    tre[x] = (tre[x] + val) % mod;
    x += lowbit(x);
  }
  return;
}
int query(int x) {
  int sum = 0;
  while (x > 0) {
    sum = (sum + tre[x]) % mod;
    x -= lowbit(x);
  }
  return sum;
}
struct node {
  int pos, val;
} a[maxn];
bool cmp(node a, node b) {
  if (a.val == b.val)
    return a.pos < b.pos;
  return a.val < b.val;
}
int ls[maxn];
int main() {
  while (scanf("%d", &n) != EOF) {
    memset(tre, 0, sizeof tre);
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i].val), a[i].pos = i;
    sort(a + 1, a + 1 + n, cmp);
    int newval = 1;
    for (int i = 1; i <= n; i++) {
      if (a[i].val != a[i - 1].val)
        newval++;
      ls[a[i].pos] = newval;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int tmp = query(ls[i] - 1);
      ans = (tmp + 1 + ans) % mod;
      update(ls[i], (tmp + 1) % mod);
    }
    printf("%d\n", ans);
  }
}
