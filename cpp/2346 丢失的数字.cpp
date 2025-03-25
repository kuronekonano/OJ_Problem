#include <algorithm>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;
bool vis[1000006];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    int flag = 0x7fffffff, tmp;
    int ans = -1, i;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &tmp);
      if (tmp > 0 && tmp <= 1000000)
        vis[tmp] = true;
    }
    for (i = 1; i <= 1000000; i++)
      if (!vis[i] && ans == -1)
        ans = i;
      else
        vis[i] = false;
    printf("%d\n", ans);
  }
  return 0;
}
