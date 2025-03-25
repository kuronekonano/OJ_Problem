#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n;
LL tree1[100008], tree2[100008];
int lowbit(int x) { return x & (-x); }
void update(LL tree[], int x, LL val) {
  while (x <= n) {
    tree[x] += val;
    x += lowbit(x);
  }
}
LL query(LL tree[], int x) {
  LL ans = 0;
  while (x > 0) {
    ans += tree[x];
    x -= lowbit(x);
  }
  return ans;
}
LL a[100008];
int main() {
  int t;
  while (scanf("%d%d", &n, &t) != EOF) {
    a[0] = 0;
    memset(tree1, 0, sizeof tree1);
    memset(tree2, 0, sizeof tree2);
    for (LL i = 1; i <= n; i++) {
      LL tmp;
      scanf("%lld", &a[i]);
      update(tree1, i, a[i] - a[i - 1]);
      update(tree2, i, (a[i] - a[i - 1]) * (i - 1));
    }
    char com[3];
    while (t--) {
      scanf("%s", com);
      if (com[0] == 'C') {
        LL l, r, add;
        scanf("%lld%lld%lld", &l, &r, &add);
        update(tree1, l, add);
        update(tree1, r + 1, -add);
        update(
            tree2, l,
            add *
                (l -
                 1)); ///(i-1)*(d[i]+x)=(i-1)*d[i]+(i-1)*x,
                      ///(i-1)为系数，在tree2中存储了(i-1)*d[i]的前缀和，而更新需要改变的值是(i-1)*x
        update(tree2, r + 1, -add * r); /// 更新的位置是r+1和l本身
      } else {
        LL l, r;
        scanf("%lld%lld", &l, &r);
        LL ansl = (l - 1) * query(tree1, l - 1) - query(tree2, l - 1);
        LL ansr = r * query(tree1, r) - query(tree2, r);
        printf("%lld\n", ansr - ansl);
      }
    }
  }
}
