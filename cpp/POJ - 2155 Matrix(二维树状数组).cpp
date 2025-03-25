#include <stdio.h>
#include <string.h>
int tre[1005][1005];
int n, t;
int lowbit(int x) { return x & (-x); }
void update(int x, int y) /// 二维更新函数
{
  for (int i = x; i <= n; i += lowbit(i))
    for (int j = y; j <= n; j += lowbit(j))
      tre[i][j]++; /// 对于区间更新，利用容斥原理，将区间的四个节点进行更新操作
}
int sum(int x, int y) /// 二维查询
{
  int sum = 0;
  for (int i = x; i > 0; i -= lowbit(i))
    for (int j = y; j > 0; j -= lowbit(j))
      sum += tre[i][j];
  return sum;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &t);
    memset(tre, 0, sizeof(tre));
    while (t--) {
      char flag[3];
      scanf("%s", flag);
      if (flag[0] == 'C') {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        update(x1,
               y1); /// 注意容斥原理更新，每次更新四个节点，每个节点从传参处开始
        update(x1, y2 + 1); /// 对于右边界和下边界，做+1的处理
        update(x2 + 1, y1);
        update(x2 + 1, y2 + 1);
      } else {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", sum(x, y) % 2); /// 查询前缀和结果%2即查询节点当前状态
      } /// 对于一个区间L到R，求前缀和时，若取这段区间之内的坐标，求和只求到L位置的1，未取到R位置的1，求和时1不是2，那么%2操作得到该位置数据为1，否则为0，对于覆盖的区间也是如此，计算1的个数得到取反最终状态
    }
    printf("\n");
  }
}
