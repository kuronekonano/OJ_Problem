#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct worth {
  int c;   // 体积
  int val; // 价值
} Get[106];

int main() {
  int i, n, v, dp[105][1005];          // dp的是行是化妆品数量，列是最大体积
  while (scanf("%d%d", &n, &v) != EOF) // n件物品，总体积为v
  {
    memset(dp, 0, sizeof(dp)); // 注意清空数组
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &Get[i].c, &Get[i].val);
    }
    for (
        i = Get[1].c; i <= v;
        i++) // 初始化第一件化妆品的数据，意思是，在第一行，也就是从第一个物品开始，
    {
      dp[1][i] =
          Get[1]
              .val; /// 列出来动态规划表格，横行是背包可装的大小，一直在顺序增长，那么拿其中第一个物品，当然是只能放到能装下那个物品的容量
    }
    for (int i = 2; i <= n;
         i++) // 已经完成初始第一个物品的安排，从第二个物品开始计算
    {
      for (int j = 1; j <= v; j++) // 体积却要从1开始计算
      {
        if (j >=
            Get[i]
                .c) // 注意这里要判断目前最大体积是否大于要装物品的体积，若不够大就不装了直接引用上一个数据
          dp[i][j] = max(
              dp[i - 1][j],
              dp[i - 1][j - Get[i].c] +
                  Get[i]
                      .val); // 其实是找，是减掉当前物品的体积，再装上这个物品，来的划算，还是保持原样不变的体积划算。
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
    //        for(i=1;i<=n;i++)//动态规划表格真的超美！！！
    //        {
    //            for(int j=1;j<=v;j++)
    //            {
    //                printf("%5d",dp[i][j]);
    //            }
    //            printf("\n");
    //        }
    printf("%d\n", dp[n][v]);
  }
  return 0;
}
