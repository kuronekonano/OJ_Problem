#include <stdio.h> ///深搜全排列
#include <string.h>
int vis[30]; /// 标记数组
int a[35];

int dfs(int n, int num) {
  if (num > n) /// 当num个数字大于所求n的个数时，说明找齐了，可以输出当前这组了
  {
    for (int i = 1; i <= n; i++) /// 输出a数组中的这n个数
    {
      printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) /// 若没有被标记(这个标记数组是放在全局变量的，所以第一次for中找了1，第二次就找2・・・・)
    {
      vis[i] = 1; /// 标记这个数
      a[num] = i;
      //            for(int k=1; k<=n; k++)printf("%d\n",vis[k]);
      //            printf("======\n");
      dfs(n, num + 1); /// 递归
      vis[i] = 0;
    }
  }
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    memset(vis, 0, sizeof(vis));
    dfs(n, 1);
  }
  return 0;
}
