#include <stdio.h>
#include <string.h>
int main() {
  int a[100005], n, vis[100005];
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i <= n; i++)
      vis[i] = 1; /// 从左到右扫一遍，从右到左扫一遍，取最大值
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    if (a[1] > a[2])
      vis[1]++;
    if (a[n] > a[n - 1])
      vis[n]++;
    for (int i = 2; i <= n; i++)
      if (a[i] > a[i - 1])
        vis[i] = vis[i - 1] + 1;
    int ans = vis[n];
    for (int i = n - 1; i >= 1; i--) {
      if (a[i] > a[i + 1])
        vis[i] = vis[i] > vis[i + 1] + 1 ? vis[i] : vis[i + 1] + 1;
      ans += vis[i];
    }
    printf("%d\n", ans);
  }
}
