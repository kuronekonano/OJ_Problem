#include <algorithm>
#include <stdio.h>  ///超棒！最长递增子序列get√
#include <string.h> ///实际上就是将每个数和前面的前面的最大值比较，选取最大值加上并赋值给正在遍历的数
using namespace std;
int main() {
  int i, j, a[1080], dp[1080], n; /// 两个数组，dp数组和输入数组
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    memset(dp, 0, sizeof(dp));
    int flag;
    int maxn = 1;
    dp[0] = 1;              /// 初始第一个遍历的数为长度1
    for (i = 1; i < n; i++) /// 开始动态规划
    {
      flag = dp[i];           /// 记录此时遍历数字的长度，一般被初始化为0
      for (j = 0; j < i; j++) /// 检查前面的dp数组中存储的最长长度
      {
        if (a[i] > a[j] && dp[j] > flag) /// 若满足递增条件，且找到了最大长度
        {
          flag = dp[j]; /// 记录长度
        } /// 如果符合递增序列的条件，那么就将其长度记录，到flag，便于存至第i位作为最长长度
      }
      dp[i] = flag + 1; /// 若遍历过了的i，则将最长长度+1，表示为i的长度
      maxn = max(maxn, dp[i]);
    } /// 作为最长长度，从flag中+1（i本身）记录到第i个数中
    //        for(i=0;i<=n;i++)
    //        {
    //            printf("%d\n",dp[i]);
    //        }
    //        sort(dp,dp+n);///这里找dp出来的长度最大值，有点小题大做了，但是为了省事
    printf("%d\n", maxn);
  }
  return 0;
}
