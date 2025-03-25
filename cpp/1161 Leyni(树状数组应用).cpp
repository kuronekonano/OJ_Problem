#include <stdio.h> ///树状数组，单点更新，区间求和
#include <string.h>
int tree[100008], n;
int lowbit(int x) { return x & (-x); }
void attact(int p) {
  while (p <= n) {
    tree[p]++;
    p += lowbit(p);
  }
}
int sum(int p) {
  int sum = 0;
  while (p > 0) {
    sum += tree[p];
    p -= lowbit(p);
  }
  return sum;
}
int main() {
  int time[100008], t, cas = 1;
  scanf("%d", &t);
  while (t--) {
    int q, cd;
    memset(tree, 0, sizeof(tree));
    memset(time, 0, sizeof(time));
    scanf("%d%d%d", &n, &q, &cd);
    printf("Case %d:\n", cas++);
    int tt = 1;
    for (int i = 1; i <= q; i++) {
      char str[10];
      scanf("%s", str);
      if (str[0] == 'A') {
        int tmp;
        scanf("%d", &tmp);
        if (time[tmp] <= tt)
          time[tmp] = tt + cd;
        else
          attact(tmp);
        tt++;
      } else {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", sum(r) - sum(l - 1));
      }
    }
  }
}
