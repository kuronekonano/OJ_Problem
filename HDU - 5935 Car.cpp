#include <stdio.h>
int main() {
  int t, i, n, a[100008], cas = 0;
  scanf("%d", &t);
  while (t--) {
    cas++;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    for (i = n; i >= 2; i--)
      a[i] -= a[i - 1];
    int time = 1, ans = 1;
    double speed = a[n];
    for (i = n - 1; i >= 1; i--) {
      if (a[i] <= speed) {
        ans++;
        speed = a[i];
      } else /// 速度可能是小数，当保持原速度用
             /// 路程/速度=时间，得到的时间，如果用路程除去后仍大于速度，说明需要更大的速度才能在这个时间通过，在保持原速度的基础上，加大时间，并且，算出在这个时间内得到的具体速度(小数且比原速度小)
      {
        time = a[i] / speed; /// 原速度所得到的时间，取整
        if ((double)a[i] / time > speed)
          time++; /// 发现时间少了，小于实际的时间，加回来。
        speed =
            (double)a[i] /
            time; /// 在向上取整时间后，算出在这个整数时间段内，所用的具体速度，因为路程不变，时间变大，所以速度变小
        ans += time;
      } /// 若再以原速度前进，不微调为小数，将会发生在整点时间内，算出的路程大于或小于固定的距离。这是不可能的
    }
    printf("Case #%d: %d\n", cas, ans);
  }
}
