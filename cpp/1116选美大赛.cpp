#include <stdio.h> ///动态规划
#include <string.h>
int add
    [106]; /// 因为这个求最长子列的题目需要将最长子列输出，因此要记录每一个符合递增条件的子序列
int digui(int x) /// 递归倒序输出
{
  if (x != 0) {
    digui(add[x]); /// 投入数组中的这个数
    printf(" %d", x);
  }
  return 0;
}
int main() {
  int i, n, j, a[105],
      dp[108]; /// a数组用于存储身高数列，dp数组用于动态规划存储最长子列长度
  while (scanf("%d", &n) != EOF) {
    if (n == 0) /// 不讲了，注意看题，最后WA
    {
      return 0;
    }
    for (i = 1; i <= n; i++) /// 输入
    {
      scanf("%d", &a[i]);
    }
    memset(dp, 0, sizeof(dp)); /// 清空数组
    memset(add, 0, sizeof(add));
    int flag;
    dp[1] = 1;               /// 从第一个数开始比较，第一个数其实长度为1
    for (i = 2; i <= n; i++) /// 第二个数开始找前面那个数比较
    {
      flag = dp
          [i]; /// flag其实是目前为止的最长子列长度,一般未访问过的都是被清空为0了的
      for (
          j = 1; j < i;
          j++) /// 从1到i一一对比，这里体现的动态规划，dp存储的是最长长度，因此首先要符合大于前面那个数，并且那个数要大于目前遍历这个i的最长子列
      {
        if (a[i] > a[j] && dp[j] > flag) {
          flag = dp
              [j]; /// flag因为符合条件因此记录上一个的子列长度，以此来延续上一个的长度
          add[i] =
              j; /// 记录第几个数，这里运用的是类似链表或并查集那样指向下一个的数组递归方式
                 /// 1存2存3存4・・・・・
        }
      }
      dp[i] =
          flag +
          1; /// 将遍历过的这个数记录为长度+1，既能把0（未访问过的），标记为1，也能将访问过符合递增条件的长度+2+3这样延续下去
    }
    flag = 0;
    int st;                  /// 用于查找那个最长子列停止于哪个位置i
    for (i = 1; i <= n; i++) /// 遍历dp数组
    {
      if (dp[i] > flag) /// 查找最长子列的最大值
      {
        flag = dp[i];
        st = i;
      }
    }
    printf("The number is %d:", flag); /// 输出最大值
    digui(
        st); /// 利用递归从记录数列中逆向回去找每个数，投入的是最终的数，在递归中也会最后输出
    printf("\n"); /// 记得换行
  }
  return 0;
}
// int digui(int x)
//{
//     if(x==0)
//     {
//         return 1;
//     }
//     else if(digui(add[x]))
//     {
//         printf(" %d",x);
//     }
// }
