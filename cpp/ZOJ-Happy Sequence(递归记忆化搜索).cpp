#include <stdio.h> ///递归记忆化(递归+DP)
#include <string.h>
#define MOD 1000000007
#define ll long long
int dp[2003][2003], data[2002][2002];
int t, n, m;
ll ans;
void init() /// 1~2000所有数的因子
{
  memset(data, 0, sizeof(data));
  memset(
      dp, 0,
      sizeof(
          dp)); /// DP数组在所有测试数据中都通用，因此每组数据都会相应增加DP出来的数据以供下次使用
  for (int i = 1; i <= 2000; i++) {
    int flag = 0;
    for (int j = 1; j <= i; j++)
      if (i % j == 0)
        data[i][++flag] = j;
    data[i][0] =
        flag; /// 模拟链表，0位存有多少因子，然后依次是数字i的因子分别是谁
  }
}
ll dfs(int now, int len) /// DFS搜索序列数量
{
  if (now == 1 || len == 1)
    return 1; /// 当当前搜索数为1时，不能再继续找1的因子，递归出口，搜索结束。或当搜索的序列长度到达上限时(剩余1)，搜索结束。
  ll tmp = 0; /// 临时存储到达数NOW时的序列数量。
  for (int i = 1; i <= data[now][0]; i++) /// DP记录
  {
    if (dp[len - 1][data[now][i]])
      tmp =
          ((tmp % MOD) + (dp[len - 1][data[now][i]] % MOD)) %
          MOD; /// 若要计算长度为len，当前值为now的序列有多少种时，该结果由长度为len-1，当前值为now的一个因子的序列继承而来
    else
      tmp =
          ((tmp % MOD) + (dfs(data[now][i], len - 1) % MOD)) %
          MOD; /// 若想要查找的序列还未计算有多少种，那么递归搜素这个序列的种数。
  }
  dp[len][now] =
      tmp; /// 最后将数字now的所有因子的种类求和之后，即是len长度，当前数now的
           /// 序列种数
  return tmp;
}
int main() {
  init();
  scanf("%d", &t);
  while (t--) {
    ans = 0; /// 最终答案
    scanf("%d%d", &n, &m);
    for (int i = n; i >= 1; i--)
      ans =
          ((ans % MOD) + (dfs(i, m) % MOD)) %
          MOD; /// 从最大的数n，最长的序列长度m开始查找这个序列。然后依次减小序列的终值来查找。
    printf("%lld\n", ans);
  }
}
