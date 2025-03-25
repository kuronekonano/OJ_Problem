#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1e3 + 7;
int n;
LL a[80];
int main() {
  int cas = 1;
  a[1] = a[2] = 0;
  a[3] = 1, a[4] = a[5] = 2;
  for (int i = 6; i <= 76; i++)
    a[i] = a[i - 2] + a[i - 3];
  while (scanf("%d", &n) && n)
    printf("Case #%d: %lld\n", cas++, a[n - 1] + a[n]);
}
