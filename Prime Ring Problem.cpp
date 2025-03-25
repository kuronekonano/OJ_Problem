#include <stdio.h>
#include <string.h>
int n;        // 输入的数
int snum[58]; // 存储四十以内所有素数
int orz[29];  // 素数环数列
int vis[26];  // 标记数组
int su()      // 找到40以内所有素数，因为n小于20，所以相加的数不会超过40
{
  snum[2] = 1; // 2为素数；
  for (int i = 3; i <= 40;
       i += 2) // 找出40以内所有素数,素数一定是奇数，这样找可以减少遍历的量
  {
    bool flag = false; // 开关关闭
    for (int j = 2; j < i; j++) {
      if (i % j == 0) // 求模
      {
        flag = true; // 开关打开
        break;       // 因为这个数i已经有其他因子了，所以不继续找
      }
    }
    if (flag == false) // 若没有因子，则标记这个数为素数
    {
      snum[i] = 1; // 标记
    }
  }
}
int dfs(int num) // 从第二个数开始遍历，之后每次投入的num是指搜索到第几个数
{
  if (num > n) // 若找的第num个数字大于输入的数字，则说明找到完了，可以输出了
  {
    if (snum[orz[1] + orz[n]]) // 第一个数和最后一个数相加也为素数
    {
      for (int i = 1; i <= n; i++) // 输出排列
      {
        printf("%d", orz[i]);
        if (i != n)
          printf(" ");
      }
      printf("\n");
    }
  }
  for (int i = 2; i <= n; i++) {
    if (!vis[i] &&
        snum[orz[num - 1] +
             i]) // 若未被标记的数字，且这个数为素数，能进来的数表示都是选好了的，每次找的条件是
    {
      vis[i] = 1;   // 标记这个数
      orz[num] = i; // 将这个符合条件的数装入素数环数列数组中
      dfs(num +
          1); // 执行这个语句时，是递归的，若能执行到最后，才会执行下一步取消标记，或者当这一行无法进行到最后时，才会执行取消标记往前退回
      vis[i] = 0; // 取消标记
    }
  }
  return 0;
}
int main() {
  int cas = 1;
  su();                          // 调用函数找出40因为所有素数
  while (scanf("%d", &n) != EOF) // 输入n
  {
    memset(vis, 0, sizeof(vis)); // 清空标记数组
    orz[1] = 1;                  // 素数环第一项一定为1
    printf("Case %d:\n", cas++);
    dfs(2); // 投入数字2，从第二个数开始寻找符合条件的数
    printf("\n");
  }
  return 0;
}
