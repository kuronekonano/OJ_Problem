#include <stdio.h> ///二分应用
int a[307], time, m, n;
bool ok(int m, int n, int maxi) // 投入最大时间
{
  int get = 0;                // 已分配路段
  for (int i = 0; i < n; i++) // 循环判断每个工程队的工作量
  {
    int maxj = 0; // 初始化每个工程队的工作量
    int j;
    for (j = get; j < m; j++) {
      maxj = maxj + a[j]; // 求和第i个队的工作量
      if (maxj > maxi)    // 若所用时间超出最大时间
      {
        break;
      }
    }
    get = j; // 分配到第j段路
    if (get == m) {
      return true; // 若路段分配完成，则返回true
    }
  }
  return false; // 否则返回false
}
int solve(int m, int n, int big) // 二分函数
{
  int l = 0, r = big; // 设定左右两边极值
  time = big;         // 将最大时间设为最大时限
  while (l <= r) {
    int mid = (l + r) / 2; // 取中点判断
    if (ok(m, n, mid))     // 投中点时限
    {
      time = mid; // 若返回可以分配完，则表示实际使用时间小于中点
      r = mid - 1;
    } else {
      l = mid + 1; // 不能分配完则表示实际施工时间大于中点时限
    }
  }
  return time; // 最终左值会大于右值，跳出循环返回最终时间
}
int main() {
  int i, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &m, &n);
    int sum = 0;
    for (i = 0; i < m; i++) {
      scanf("%d", &a[i]);
      sum = sum + a[i]; // 求所需的最大时间
    }
    time = solve(m, n, sum);
    printf("%d\n", time);
  }
  return 0;
}
