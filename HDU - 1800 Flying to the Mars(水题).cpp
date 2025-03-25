#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 9;
int ans[maxn];
int main() {
  int n, a[maxn], cnt;
  while (scanf("%d", &n) != EOF) {
    cnt = 0;
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
      int tmp = -1;
      for (int j = 0; j < cnt; j++) {
        if (a[i] > ans[j]) {
          tmp = j;
          break;
        }
      }
      if (tmp == -1)
        ans[cnt++] = a[i];
      else
        ans[tmp] = a[i];
    }
    printf("%d\n", cnt);
  }
}
