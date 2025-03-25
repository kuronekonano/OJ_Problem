#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 7;
LL a[maxn], b[maxn], c[maxn], n;
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++)
    scanf("%lld", &a[i]);
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++)
    scanf("%lld", &b[i]);
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; i++)
    scanf("%lld", &c[i]);
  sort(c + 1, c + 1 + n);
  LL ans = 0;
  for (int i = 1; i <= n; i++) {
    LL posa = lower_bound(a + 1, a + 1 + n, b[i]) - a - 1;
    LL posc = upper_bound(c + 1, c + 1 + n, b[i]) - c - 1;
    //        printf("====%d  %d\n",posa,posc);
    ans += posa * (n - posc);
  }
  printf("%lld\n", ans);
}
/*
5
5 5 5 5 5
5 5 5 5 5
5 5 5 5 6

2
1 5
2 4
3 6
*/
