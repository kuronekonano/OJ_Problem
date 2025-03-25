#include <bits/stdc++.h> ///更新条件，将区间内所有小于val的值更新成val
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
using namespace std;
const int maxn = 1e5 + 7;
struct node {
  int l, r;
  LL val;
} tre[maxn << 2];
int m, n;
unsigned int x, y, z;
LL ans;
unsigned int calsq() {
  x = x ^ (x << 11);
  x = x ^ (x >> 4);
  x = x ^ (x << 5);
  x = x ^ (x >> 14);
  unsigned w = x ^ (y ^ z);
  x = y;
  y = z;
  z = w;
  return z;
}
void pushup(
    int rt) /// 那么线段树维护区间最小值，这样更新时方便查找哪段区间是小于更新值的
{
  tre[rt].val = min(tre[rt << 1].val, tre[rt << 1 | 1].val);
}
void pushdown(
    int rt) /// 延时更新传递更新最大值，保证多次更新后维护到底层用的是有效的最大值更新
{
  if (tre[rt].val) {
    tre[rt << 1].val = max(tre[rt << 1].val, tre[rt].val);
    tre[rt << 1 | 1].val = max(tre[rt << 1 | 1].val, tre[rt].val);
    tre[rt].val = 0;
  }
}
void build(int l, int r, int rt) {
  tre[rt].l = l;
  tre[rt].r = r;
  tre[rt].val = 0;
  if (l == r)
    return;
  else {
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    pushup(rt);
  }
}
void update(int l, int r, unsigned val, int rt) {
  if (tre[rt].val >= val)
    return;
  if (tre[rt].l >= l &&
      tre[rt].r <=
          r) /// 更新时要求该区间最小值小于被更新值，那么所有的最小值都会被更新，与区间内最大值无关
  {
    if (tre[rt].val <= val)
      tre[rt].val = val;
    return;
  }
  pushdown(rt);
  int mid = (tre[rt].l + tre[rt].r) >> 1;
  if (l <= mid)
    update(l, r, val, rt << 1);
  if (r > mid)
    update(l, r, val, rt << 1 | 1);
  pushup(rt); /// 向上传递最小值
}
void query(int l, int r, int rt) {
  if (tre[rt].l == tre[rt].r) /// 查询时查询到底层，用标号L与该值相乘并异或总ANS
  {
    ans = ans ^ (tre[rt].l * tre[rt].val);
    return;
  }
  pushdown(rt);
  query(l, r, rt << 1);
  query(l, r, rt << 1 | 1);
}
LL f[maxn * 3];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%u%u%u", &n, &m, &x, &y, &z);
    build(1, n, 1);
    for (int i = 1; i <= m; i++) { /// 构造区间和值
      LL a = calsq(), b = calsq();
      int l = min(a % n + 1, b % n + 1);
      int r = max(a % n + 1, b % n + 1);
      LL val = calsq() % (1 << 30);
      update(l, r, val, 1);
    }
    ans = 0;
    query(1, n, 1);
    printf("%lld\n", ans);
  }
}
