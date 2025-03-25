#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
using namespace std;
const int maxn = 2e5 + 7;
LL n, k;
int main() {
  while (scanf("%lld%lld", &n, &k) != EOF) {
    if (k < n)
      printf("%lld\n", k & 1 ? k / 2 : k / 2 - 1);
    else if (k >= 2 * n)
      printf("0\n");
    else {
      LL tmp = n - (k - n - 1);
      printf("%lld\n", n == k ? tmp / 2 - 1 : tmp / 2);
    }
  }
}
