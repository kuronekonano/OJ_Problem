#include <algorithm>
#include <stdio.h>
using namespace std;
const int maxn = 5e4 + 9;
int n, a[maxn], q;
struct node {
  int l, r, ma;
} tre[maxn << 2], tre2[maxn << 2];
void buildmax(int l, int r, int rt) {
  tre[rt].l = l;
  tre[rt].r = r;
  if (l == r)
    tre[rt].ma = a[l];
  else {
    int mid = (tre[rt].l + tre[rt].r) >> 1;
    buildmax(l, mid, rt << 1);
    buildmax(mid + 1, r, rt << 1 | 1);
    tre[rt].ma = max(tre[rt << 1].ma, tre[rt << 1 | 1].ma);
  }
}
void buildmin(int l, int r, int rt) {
  tre2[rt].l = l;
  tre2[rt].r = r;
  if (l == r)
    tre2[rt].ma = a[l];
  else {
    int mid = (tre2[rt].l + tre2[rt].r) >> 1;
    buildmin(l, mid, rt << 1);
    buildmin(mid + 1, r, rt << 1 | 1);
    tre2[rt].ma = min(tre2[rt << 1].ma, tre2[rt << 1 | 1].ma);
  }
}
int querymax(int l, int r, int rt) {
  if (tre[rt].l >= l && tre[rt].r <= r)
    return tre[rt].ma;
  else {
    int mid = (tre[rt].l + tre[rt].r) >> 1;
    if (mid < l)
      return querymax(l, r, rt << 1 | 1);
    else if (mid >= r)
      return querymax(l, r, rt << 1);
    else
      return max(querymax(l, r, rt << 1 | 1), querymax(l, r, rt << 1));
  }
}
int querymin(int l, int r, int rt) {
  if (tre2[rt].l >= l && tre2[rt].r <= r)
    return tre2[rt].ma;
  else {
    int mid = (tre2[rt].l + tre2[rt].r) >> 1;
    if (mid < l)
      return querymin(l, r, rt << 1 | 1);
    else if (mid >= r)
      return querymin(l, r, rt << 1);
    else
      return min(querymin(l, r, rt << 1 | 1), querymin(l, r, rt << 1));
  }
}
int main() {
  while (scanf("%d%d", &n, &q) != EOF) {
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    buildmin(1, n, 1);
    buildmax(1, n, 1);
    int l, r;
    while (q--) {
      scanf("%d%d", &l, &r);
      printf("%d\n", querymax(l, r, 1) - querymin(l, r, 1));
    }
  }
}
