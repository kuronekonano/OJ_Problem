#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL pri[3090], cnt;
void broken(LL num) /// 分解质因数
{
  cnt = 0;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      pri[cnt++] = i;
      while (num % i == 0)
        num /= i;
    }
  }
  if (num != 1)
    pri[cnt++] = num;
}
LL all(LL m) /// 容斥原理
{
  LL ans = 0;
  for (int i = 1; i < (1 << cnt); i++) {
    int sum = 1, num1 = 0, tmp = i;
    for (int j = 0; j < cnt; j++) {
      if (1 & tmp) {
        sum *= pri[j];
        num1++;
      }
      tmp >>= 1;
    }
    if (num1 & 1)
      ans += m / sum;
    else
      ans -= m / sum;
  }
  return ans;
}
int main() {
  int t, cas = 1;
  LL a, b, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld%lld", &a, &b, &n);
    broken(n);
    //        printf("%lld   %lld \n",all(b),all(a));
    printf("Case #%d: %lld\n", cas++, b - all(b) - ((a - 1) - all(a - 1)));
  }
}
