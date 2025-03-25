#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, a[100005];
  while (scanf("%d%d", &n, &l) != EOF) {
    bool ans = false;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (i != 1 && a[i] + a[i - 1] >= l)
        ans = true;
    }
    printf("%s\n", ans ? "Possible" : "Impossible");
  }
}
