#include <stdio.h> ///并查集连通块
int z[1003],
    sum[1005]; /// 两个数组，一个是正常并查集的上溯查找数组，一个用来记录整个集团的元素总和
int find(
    int x) /// find和join函数基本相同，因为要输出整个集团中拥有的元素个数，多个用来在boss处存集团元素总数的数组
{          /// 也可以只用一个数组，但是这样就要一个一个元素的重新计数，速度会慢
  int r = x, k;
  while (r != z[r]) {
    k = r;
    r = z[r];
    z[k] = z[r];
  }
  return r;
}
void join(int x, int y) {
  int a = find(x), b = find(y);
  if (a !=
      b) /// 差别在于，当不是同一个集团时，除了要将两个集团的boss建立从属关系
  {
    z[a] = b;
    sum[b] =
        sum[b] +
        sum[a]; /// 还要在这里将被定位下属的那个原boss的集团总数加到新boss身上
    sum[a] =
        1; /// 原boss变为普通下属，且计数变为1，当找上司和总数时，不在找到他身上
  }
}
int main() {
  int i, t, n, m, a, b, flag;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (i = 0; i <= n; i++) /// 最终错误，记得初始化两个数组的位置放哪儿
    {
      z[i] = i;   /// 初始化，除了上溯查找数组，自己当自己老大之外
      sum[i] = 1; /// 还要集团元素和数组，每个人的集团都初始化为自己1个元素
    }
    while (m--) {
      scanf("%d", &flag);
      if (flag == 1) {
        scanf("%d%d", &a, &b);
        join(a, b);
      } else {
        scanf("%d", &a);
        int aim = find(a);        /// 查找上司
        printf("%d\n", sum[aim]); /// 输出你要查找的那个元素所在集团的总人数
      } /// 也就是找上司问问他，你的集团有几人
    }
  }
  return 0;
}
