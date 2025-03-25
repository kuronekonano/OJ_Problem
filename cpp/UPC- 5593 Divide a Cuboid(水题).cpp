#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[4];
  while (scanf("%d%d%d", &a[0], &a[1], &a[2]) != EOF) {
    sort(a, a + 3);
    if (a[0] % 2 == 0 || a[1] % 2 == 0 || a[2] % 2 == 0)
      printf("0\n");
    else
      printf("%lld\n", (long long)a[0] * (long long)a[1]);
  }
}
