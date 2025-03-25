#include <bits/stdc++.h>
#define LL long long
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
using namespace std;
LL tree[maxn], lowl[20004], lowr[20004], highl[20004], highr[20004];
int n, t;
struct node {
  int val, pos;
} a[20004];
int lowbit(int x) { return x & (-x); }
void update(int x) {
  while (x <= maxn) /// 上界为题目给出的最大值
  {
    tree[x]++;
    x += lowbit(x);
  }
}
int query(int x) {
  LL sum = 0;
  while (x > 0) {
    sum += tree[x];
    x -= lowbit(x);
  }
  return sum;
}
bool cmp(node a, node b) { return a.pos > b.pos; }
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(tree, 0, sizeof tree);
    memset(lowr, 0, sizeof lowr);
    memset(lowl, 0, sizeof lowl);
    memset(highl, 0, sizeof highl);
    memset(highr, 0, sizeof highr);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) /// 左到右遍历更新左边的较大较小值计数
    {
      scanf("%d", &a[i].val);
      a[i].pos = i;
      update(a[i].val);
      lowl[a[i].pos] += query(a[i].val - 1);
      highl[a[i].pos] += i - query(a[i].val);
    }
    sort(a + 1, a + 1 + n, cmp);
    memset(tree, 0, sizeof tree);
    for (int i = 1; i <= n; i++) {
      update(a[i].val); /// 右到左遍历更新右边的较大较小值计数
      lowr[a[i].pos] += query(a[i].val - 1);
      highr[a[i].pos] += i - query(a[i].val);
    }
    //        for(int i=1; i<=n; i++)printf("i=%d   highl=%lld  highr=%lld
    //        lowl=%lld  lowr=%lld\n",i,highl[i],highr[i],lowl[i],lowr[i]);
    LL ans = 0;
    for (int i = 1; i <= n; i++)
      ans += (lowl[i] * highr[i]) + (lowr[i] * highl[i]);
    printf("%lld\n", ans);
  }
}
