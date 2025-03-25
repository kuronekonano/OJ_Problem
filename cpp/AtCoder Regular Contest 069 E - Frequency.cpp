#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#define LL long long
using namespace std;
const int maxn = 1e5 + 10;
struct node {
  LL pos, val;
} a[maxn];
bool cmp(node a, node b) {
  if (a.val == b.val)
    return a.pos < b.pos;
  return a.val > b.val;
}
int n;
LL ans[maxn];
int main() {
  while (scanf("%d", &n) != EOF) {
    memset(ans, 0, sizeof ans);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i].val);
      a[i].pos = i;
    }
    sort(a + 1, a + n + 1, cmp);
    a[n + 1].val = 0;
    LL tmp = 1;
    int num = a[1].pos;
    for (int i = 2; i <= n + 1; i++) {
      if (a[i].val == a[i - 1].val)
        tmp++;
      else
        ans[num] += (a[i - 1].val - a[i].val) * tmp, tmp++;
      if (a[i].pos < num)
        num = a[i].pos;
    }
    for (int i = 1; i <= n; i++)
      printf("%lld\n", ans[i]);
  }
}
/*
6
1 3 2 3 3 3
*/
