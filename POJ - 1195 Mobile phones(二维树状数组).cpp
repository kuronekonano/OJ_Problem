#include <stdio.h> ///二维树状数组模板题
#include <string.h>
#define LL long long
LL tre[1036][1036];
int n;
int lowbit(int x) { return x & (-x); }
void update(
    int x, int y,
    int add) /// 区间更新，对被更新区域前缀和更新x到y更新至n 增长率为lowbit(i)
{
  for (int i = x; i <= n; i += lowbit(i))
    for (int j = y; j <= n; j += lowbit(j))
      tre[i][j] += add;
}
LL sum(int x, int y) /// 求和
{
  LL sum = 0;
  for (int i = x; i > 0; i -= lowbit(i))
    for (int j = y; j > 0; j -= lowbit(j))
      sum += tre[i][j];
  return sum;
}
int main() {
  int flag;
  while (scanf("%d", &flag) != EOF) {
    if (flag == 0) /// 输入0时清空数组
    {
      memset(tre, 0, sizeof(tre));
      scanf("%d", &n);
    } else if (flag == 1) /// 输入1时做单点修改
    {
      int x, y, add;
      scanf("%d%d%d", &x, &y, &add);
      x++;
      y++; /// 注意题目是从0,0的坐标开始的，直到n-1，而树状数组因为要lowbit操作必从1开始n结束，因此在输入后应+1表示树状数组中存储的位置
      update(x, y, add);
    } else if (flag == 2) /// 输入2时区间求和查询
    {
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      x1++;
      y1++;
      x2++;
      y2++;
      printf("%lld\n",
             sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) +
                 sum(x1 - 1, y1 - 1)); /// 容斥原理删减增加重复减去的内容
    } else
      break;
  }
}
