#include <stdio.h>            ///深搜全排列
#include <string.h>           ///next_permutation(a,a+m)全排列
int vis[30];                  /// 标记数组
int a[35];                    /// 递归数组
int b[35], nums[780][10], ii; /// 最大n为6,6的阶乘排列数量有720个，每个有6个数字
int dfs(int n, int num) {
  if (num > n) /// 当num个数字大于所求n的个数时，说明找齐了，可以记录当前这组了
  {
    ii++;
    for (int i = 1; i <= n; i++) /// 记录a数组中的这n个数
    {
      nums[ii][i] = a[i];
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
  int n, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &b[i]);
    }
    memset(vis, 0, sizeof(vis));
    ii = 0;
    dfs(n, 1);
    int j;
    int flag = 1;
    for (int i = 1; i <= ii; i++) {
      for (j = 1; j <= n; j++) {
        if (b[j] != nums[i][j])
          break;
        //                  printf("%d%c",nums[i][j],j==n?'\n':' ');
      }
      if (j == n + 1) {
        flag = i;
        break;
      }
    }
    if (flag == ii)
      flag = 0;
    for (int k = 1; k <= n; k++) {
      printf("%d%c", nums[flag + 1][k], k == n ? '\n' : ' ');
    }
  }
  return 0;
}
