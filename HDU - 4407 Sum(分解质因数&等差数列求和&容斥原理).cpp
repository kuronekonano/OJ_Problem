#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL t, n, m, p, a[100080];
LL cnt = 0;
map<LL, LL> vis;
map<LL, LL>::iterator it;
void prim(LL num) /// 分解质因数
{
  cnt = 0;
  for (LL i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      a[cnt++] = i;
      while (num % i == 0)
        num /= i;
    }
  }
  if (num != 1)
    a[cnt++] = num;
}
LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a % b); }
LL all(LL m) {
  LL ans = 0; /// 非互质数之和
  for (LL i = 1; i < (1 << cnt); i++) {
    LL sum = 1, num1 = 0, tmp = i;
    for (LL j = 0; j < cnt; j++) {
      if (1 & tmp) {
        sum *= a[j];
        num1++;
      }
      tmp >>= 1;
    }
    tmp = m / sum;
    if (num1 & 1)
      ans += tmp * (tmp + 1) * sum / 2;
    else
      ans -= tmp * (tmp + 1) * sum / 2;
  }
  return ans;
}
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld", &n, &m);
    vis.clear();
    while (m--) {
      LL com, x, y;
      LL ans = 0;
      scanf("%lld", &com);
      if (com == 1) {
        scanf("%lld%lld%lld", &x, &y, &p);
        prim(p);
        ans = x * (y - x + 1) + (y - x + 1) * (y - x) / 2;
        //                printf("----%lld    %lld %lld\n",ans,all(y),all(x-1));
        ans -= all(y) - all(x - 1);
        for (it = vis.begin(); it != vis.end(); it++) {
          if (it->first >= x && it->first <= y) {
            if (gcd(it->first, p) == 1)
              ans -= it->first;
            if (gcd(it->second, p) == 1)
              ans += it->second;
          }
        }
        printf("%lld\n", ans);
      } else {
        scanf("%lld%lld", &x, &p);
        vis[x] = p;
      }
    }
  }
}
/*
99
3 99
1 3 3 7
2 2 3
1 3 3 7
*/
