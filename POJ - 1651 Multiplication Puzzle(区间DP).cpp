#include <algorithm>
#include <stdio.h> ///区间DP
#include <string.h>
#define LL long long
using namespace std;
const int maxn = 108;
int n;
LL a[maxn],
    dp[maxn]
      [maxn]; /// DP[i][j]表示区间的左右边界，表示删除左右边界之间的数所要的花费
int main() {
  while (scanf("%d", &n) != EOF) {
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    for (int i = 2; i <= n; i++)
      for (int j = 1; j + i <= n; j++) {
        dp[j][j + i] = 1e12;
        for (
            int k = j + 1; k < j + i;
            k++) /// 在一个区间内选择一个k值，这个k值和左右边界相乘，意思是删除k，并且从边界到k这两段区间优先被删掉，求和后取一个花费最小值
          dp[j][j + i] = min(dp[j][j + i],
                             a[j] * a[k] * a[j + i] + dp[j][k] + dp[k][j + i]);
        //                printf("dp[%d][%d] = %lld\n",j,j+i,dp[j][j+i]);
      }
    printf(
        "%lld\n",
        dp[1]
          [n]); /// 最后因为只留下第一个值和最后一个值，因此这段区间内所有值被删去的最优解即answer
  }
}
/*
6
10 1 50 50 20 5
7
10 1 50 50 20 100 20
*/
