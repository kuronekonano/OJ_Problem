#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
char a[60];
char b[60];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    scanf("%s", a);
    scanf("%s", b);
    LL ans = 3;
    for (int i = 1; i < n; i++) {
      if (a[i] == b[i] && a[i - 1] == b[i - 1])
        ans = (ans * (LL)2) % mod;
      if (a[i] == a[i - 1] && b[i] == b[i - 1]) {
        if (i - 3 >= 0 && a[i - 2] == a[i - 3] && b[i - 2] == b[i - 3])
          ans = (ans * (LL)3) % mod;
        else
          ans = (ans * (LL)2) % mod;
      }
    }
    printf("%lld\n", ans % mod);
  }
}
/*
6
abaacc
abccbb
6
abbacc
accabb
*/
