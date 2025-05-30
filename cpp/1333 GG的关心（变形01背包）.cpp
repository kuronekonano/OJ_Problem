#include <algorithm>
#include <stdio.h> ///01背包的变形
#include <string.h>
using namespace std;
int main() {
  int i, j, n, m, a[1008], dp[1008];
  while (scanf("%d", &n) != EOF) {
    if (n == 0) {
      return 0;
    }
    scanf("%d", &m);
    for (i = 0; i < n; i++) /// 输入部分
    {
      scanf("%d", &a[i]);
    }
    if (m <
        5) /// 因为输入值m是小于1000的，因此当输入的本金少于5时什么都买不了，就直接输出原有金额就好
    {
      printf("%d\n", m);
      continue;
    }
    sort(
        a,
        a + n); /// 排序，按从小到大的顺序一个个购买，这样才能从基础部分一遍遍更新dp数组，因为在计算更大价钱的物品时，会需要买便宜物品的时记录的数据
    memset(dp, 0, sizeof(dp)); /// 记得清空数组
    for (
        i = 0; i < n - 1;
        i++) /// 背包部分，从第1个物品到第n-1个物品，因为最后一个物品是最大值，之后会单独计算，因此不能在背包中被统入
    {
      for (
          j = m - 5; j >= a[i];
          j--) /// 从m-5的金额，开始记录，留出5元的最低金额，防止超出而不能消费掉最值钱的物品
      { /// 注意这个巧妙的限制条件，遍历的金额将一直到遍历物品的金额截止，也就是说不会把钱花超
        dp[j] = max(
            dp[j],
            dp[j - a[i]] +
                a[i]); /// 比较当前金额和加物品后的金额，谁比较大，就更新为谁，这里取的数据是当前
                       /// 余额-物品金额
                       /// 的位置锁存储的最大使用金额，最大使用金额再加上当前物品金额便是当前持有金额可以消费的最大值
      }
      //            for(int
      //            k=m-5;k>=0;k--)///这里可以看出每次遍历，动态规划数组的更新路径
      //            {
      //                printf("%d\n",dp[k]);
      //            }
      //            printf("======\n");
    } /// 取出最贵的物品，留在背包完成后减去，是余额最少的
    printf("%d\n", m - dp[m - 5] - a[n - 1]);
  }
  return 0;
}
