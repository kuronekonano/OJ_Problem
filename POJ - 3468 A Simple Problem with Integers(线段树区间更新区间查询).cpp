#include <stdio.h>
#include <string.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 9;
int n, q;
LL a[maxn], mark[maxn << 2], ans;
struct node {
  int l, r;
  LL sum;
} tre[maxn << 2];
void pushup(int rt) { tre[rt].sum = tre[rt << 1].sum + tre[rt << 1 | 1].sum; }
void pushdown(
    int rt) /// 向下传递，根据结点的区间边界对sum求和与mark延时标记进行更新
{
  if (mark[rt]) {
    tre[rt << 1].sum += (tre[rt << 1].r - tre[rt << 1].l + 1) * 1LL * mark[rt];
    tre[rt << 1 | 1].sum +=
        (tre[rt << 1 | 1].r - tre[rt << 1 | 1].l + 1) * 1LL * mark[rt];
    mark[rt << 1] += mark[rt];
    mark[rt << 1 | 1] += mark[rt];
    mark[rt] = 0;
  }
}
void build(int l, int r, int rt) {
  tre[rt].l = l;
  tre[rt].r = r;
  if (l == r)
    tre[rt].sum = a[l];
  else {
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    pushup(rt);
  }
}
void update(int l, int r, LL val, int rt) {
  if (tre[rt].l >= l && tre[rt].r <= r) {
    tre[rt].sum +=
        (tre[rt].r - tre[rt].l + 1) * val; /// 更新区间时要加上长度*val
    mark[rt] += val;                       /// 并且对mark延时标记更新
  } else {
    pushdown(
        rt); /// 查询及更新结点时要先判断该位置是否有延时标记，如果有则push_down向下传递
    int mid = (tre[rt].l + tre[rt].r) >> 1;
    if (l > mid)
      update(l, r, val, rt << 1 | 1);
    else if (r <= mid)
      update(l, r, val, rt << 1);
    else {
      update(l, r, val, rt << 1 | 1);
      update(l, r, val, rt << 1);
    }
    pushup(rt); /// 更新后向上传递
  }
}
void query(int l, int r, int rt) {
  if (tre[rt].l >= l && tre[rt].r <= r)
    ans += tre[rt].sum;
  else {
    pushdown(rt); /// 查询向下传递
    int mid = (tre[rt].l + tre[rt].r) >> 1;
    if (l > mid)
      query(l, r, rt << 1 | 1);
    else if (r <= mid)
      query(l, r, rt << 1);
    else {
      query(l, r, rt << 1 | 1);
      query(l, r, rt << 1);
    }
  }
}
int main() {
  while (scanf("%d%d", &n, &q) != EOF) {
    memset(mark, 0, sizeof mark);
    for (int i = 1; i <= n; i++)
      scanf("%lld", &a[i]);
    build(1, n, 1);
    char com[3];
    int l, r;
    LL val;
    while (q--) {
      ans = 0;
      scanf("%s", com);
      if (com[0] == 'Q') {
        scanf("%d%d", &l, &r);
        query(l, r, 1);
        printf("%lld\n", ans);
      } else {
        scanf("%d%d%lld", &l, &r, &val);
        update(l, r, val, 1);
      }
    }
  }
}
