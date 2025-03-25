#include <algorithm>
#include <stdio.h> ///背包
#include <string.h>
using namespace std;
struct metal /// 价值和攻击打包
{
  int att;
  int vol;
} timo[1005];
int dp[1005][1005]; /// dp数组
int main() {
  int i, n, v, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &v); /// n个道具，v的容量
    memset(dp, 0, sizeof(dp));
    for (i = 1; i <= n; i++) /// 输入价值和攻击,n个道具
    {
      scanf("%d", &timo[i].att);
    }
    for (i = 1; i <= n; i++) {
      scanf("%d", &timo[i].vol);
    }
    for (i = timo[1].vol; i <= v; i++) /// 边界初始处理
    {
      dp[1][i] = timo[1].att; /// 动态规划表格的横行是从1开始增大的背包容量
    }
    for (i = 2; i <= n; i++) {
      for (int j = 1; j <= v; j++) {
        if (j >= timo[i].vol) {
          dp[i][j] =
              max(dp[i - 1][j], dp[i - 1][j - timo[i].vol] + timo[i].att);
        } else
          dp[i][j] = dp[i - 1][j];
      }
    }
    printf("%d\n", dp[n][v]);
  }
  return 0;
}
