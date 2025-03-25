#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL a[100005], b[100005];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++)
      scanf("%lld%lld", &a[i], &b[i]);
    LL sum = 0;
    for (int i = n - 1; i >= 0; i--) {
      LL tmp = 0;
      a[i] += sum;
      if (a[i] % b[i])
        tmp = b[i] - (a[i] % b[i]);
      sum += tmp;
    }
    printf("%lld\n", sum);
  }
}
