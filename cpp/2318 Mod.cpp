#include <stdio.h>  ///处理要取模的数组，每一个ai若比之前那个大，都是无效的取模
#include <string.h> ///ai若是a(i-1)因子，那么a(i-1)就是无效的取摸
int main() {
  bool flag = false;
  int n, m, a, tmp, b[100008], t;
  int vis[100008];
  scanf("%d", &t);
  while (t--) {
    int num = 0;
    scanf("%d", &n);
    scanf("%d", &vis[++num]);
    for (int i = 1; i < n; i++) {
      scanf("%d", &a);
      if (a < vis[num]) {
        while (vis[num] % a == 0)
          num--;
        vis[++num] = a;
      }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      scanf("%d", &tmp);
      for (int j = 1; j <= num; j++) {
        if (vis[j] <= tmp) {
          tmp %= vis[j];
        }
      }
      b[i] = tmp;
    }
    for (int i = 0; i < m; i++)
      printf("%d\n", b[i]);
  }
}
