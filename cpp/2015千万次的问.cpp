#include <stdio.h>  ///前缀和
#include <string.h> ///得出的df数组是从区间1开始到i中所有数组元素出现的次数和，这样某个区间的元素出现次数时，只用用范围a~b内b的总和-a的总和即可得到区间总和
int i, arr[100005], n, k, t, df[100005];
int main() {
  while (scanf("%d", &n) != EOF) /// n个数字数列，竟然是循环
  {
    for (i = 1; i <= n; i++) /// 输入
    {
      int k;
      scanf("%d", &k);
      arr[k]++; /// 标记数组计数
    }
    for (i = 1; i < 100001;
         i++) /// 输出数组中计数，给每个数字出现的次数加上前面范围的次数
    {
      df[i] = df[i - 1] + arr[i];
    }
    int a, b;
    scanf("%d", &t); /// 询问次数
    while (t--) {
      scanf("%d%d", &a, &b);
      printf("%d\n", df[b] - df[a - 1]); /// 输出范围内次数之差
    }
  }
  return 0;
}
