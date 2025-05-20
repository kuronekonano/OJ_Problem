#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1e5 + 7;
int t, n;
struct point {
  int x, y, w;
  bool operator<(const point &a) const { return x == a.x ? y > a.y : x < a.x; }
  point(int a, int b, int c) { x = a, y = b, w = c; }
};
struct node {
  int l, r, ma;
} tre[maxn << 2];
void push_up(int rt) { tre[rt].ma = max(tre[rt << 1].ma, tre[rt << 1 | 1].ma); }
void build(int l, int r, int rt) {
  tre[rt].l = l, tre[rt].r = r;
  if (l == r)
    tre[rt].ma = 0;
  else {
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    push_up(rt);
  }
}
void update(int pos, int val, int rt) {
  if (tre[rt].l == pos && tre[rt].r == pos)
    tre[rt].ma = val;
  else {
    int mid = (tre[rt].l + tre[rt].r) >> 1;
    if (pos > mid)
      update(pos, val, rt << 1 | 1);
    else if (pos <= mid)
      update(pos, val, rt << 1);
    push_up(rt);
  }
}
int query(int l, int r, int rt) {
  if (tre[rt].l >= l && tre[rt].r <= r)
    return tre[rt].ma;
  else {
    int mid = (tre[rt].l + tre[rt].r) >> 1;
    if (l > mid)
      return query(l, r, rt << 1 | 1);
    else if (r <= mid)
      return query(l, r, rt << 1);
    else
      return max(query(l, r, rt << 1 | 1), query(l, r, rt << 1));
  }
}
vector<point> q;
vector<int> xx, yy;
int main() {
  int x, y, w;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    q.clear();
    xx.clear();
    yy.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", &x, &y, &w);
      q.pb(point(x, y, w));
      xx.pb(x);
      yy.pb(y);
    }
    sort(xx.begin(), xx.end()); /// 离散化
    sort(
        yy.begin(),
        yy.end()); /// 先将坐标值按大小排序，得到每个坐标值的相对位置，也就是离散化映射的值
    xx.erase(unique(xx.begin(), xx.end()),
             xx.end()); /// 去重，如果是相同坐标有区分则不能这样离散
    yy.erase(unique(yy.begin(), yy.end()), yy.end());
    for (int i = 0; i < q.size(); i++) {
      q[i].x = lower_bound(xx.begin(), xx.end(), q[i].x) - xx.begin();
      q[i].y = lower_bound(yy.begin(), yy.end(), q[i].y) - yy.begin();
    }
    sort(q.begin(), q.end());
    build(0, n, 1);
    for (int i = 0; i < q.size(); i++) {
      int sum = 0;
      if (q[i].y == 0)
        sum = q[i].w;
      else
        sum = query(0, q[i].y - 1, 1) + q[i].w;
      update(q[i].y, sum, 1);
    }
    printf("%d\n", query(0, n, 1));
  }
}
