#include <stdio.h> ///并查集
int z[30005];
int find(int x) /// 关键还是查找和加入两个函数建立体系
{
  int r = x, t;
  while (r != z[r]) /// 这里包括了上溯查找和路径压缩
  {
    t = r;       /// 路径压缩步骤
    r = z[r];    /// 上溯查找步骤
    z[t] = z[r]; /// 路径压缩步骤
  }
  return r;
}
void join(int x,
          int y) /// 加入函数需要利用查找函数查询要加入的成员是否属于一个集团
{
  int a = find(x), b = find(y);
  if (a != b) {
    z[a] = b; /// 不属于两个集团，则两个集团的老大建立从属关系
  }
}
int main() {
  int n, m, i, k, s1, s2;
  while (scanf("%d%d", &n, &m) != EOF) {
    if (m == 0 && n == 0) {
      return 0;
    }
    for (i = 0; i <= n; i++) /// 初始化每个人独立一个集团，自己是自己老大
    {
      z[i] = i;
    }
    while (m--) /// m个夜晚，也就是共有m个线索
    {
      scanf("%d", &k); /// k个人出来活动，也就是这k个人形成集团
      scanf(
          "%d",
          &s1); /// 既然是k个人形成集团，那么将第一个人作为这天晚上的一个总节点，他关系到剩下几个当晚活动的人
      for (i = 1; i < k; i++) /// 建立集团体系
      {
        scanf("%d", &s2);
        join(s1, s2);
      }
    }
    int boss = find(0), sum = 0;
    for (i = 0; i <= n; i++) /// 查找并对比boss然后相同boss的就计数
    {
      if (find(i) == boss) {
        sum++;
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}
