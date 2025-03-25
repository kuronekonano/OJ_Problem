#include <stdio.h>
#include <string.h>
#define LL long long
using namespace std;
const LL MOD = 1000000007;
LL a[10000];
LL poww(LL a, LL b) {
  LL ans = 1;
  while (b) {
    if (b & 1)
      ans = ((ans % MOD) * (a % MOD)) % MOD;
    a = ((a % MOD) * (a % MOD)) % MOD;
    b >>= 1;
  }
  return ans;
}
int main() {
  int t, n, a[100004], b[100004], hand[100004];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &hand[i]);
      b[n - i - 1] = hand[i];
    }
    bool fr = true, ba = true;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i] < hand[i])
        fr = false;
      if (a[i] < b[i])
        ba = false;
    }
    if (ba && fr) {
      printf("both\n");
    } else if (ba || fr) {
      printf("%s\n", ba ? "back" : "front");
    } else
      printf("none\n");
  }
}
