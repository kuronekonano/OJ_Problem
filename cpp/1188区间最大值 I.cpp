#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int n, a[5005], i, t, flag = 1;
  while (scanf("%d", &n) != EOF) /// n个数
  {
    for (i = 1; i <= n; i++) /// 输入n个数
    {
      scanf("%d", &a[i]);
    }
    scanf("%d", &t); /// t次提问
    int j = t - 1;
    int x, y;
    int b[5005]; /// 最大值存储数组
    while (t--)  /// 因为是倒着的，所以第t次反而是第1次
    {
      scanf("%d%d", &x, &y);   /// 从x到y的区间内
      int max = a[x];          /// 取最大值是初始x
      for (i = x; i <= y; i++) /// 遍历x至y
      {
        if (a[i] > max) /// 取max最值
        {
          max = a[i];
        }
      }
      b[t] = max; /// 记录第t次的最值
    }
    printf("Case %d:\n", flag++);
    for (i = j; i >= 0; i--) /// 倒着输出即是从头输出
    {
      printf("%d\n", b[i]);
    }
  }
  return 0;
}
