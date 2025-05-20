#include <algorithm>
#include <stdio.h> ///简单贪心
using namespace std;
struct baby /// 宝贝的价值和体积
{
  int pi, mi;
} a[108];
bool cmp(baby a, baby b) /// 结构体排序，从大到小，从价值最高的开始收
{
  return a.pi > b.pi;
}
int main() {
  int v, m, i;
  while (scanf("%d", &v) != EOF) {
    if (v ==
        0) /// 题目要求v等于0时结束，因此必须一个一个判断，不能输入完v和m之后再判断是否结束
      return 0;
    else
      scanf("%d", &m);
    for (i = 0; i < m; i++) {
      scanf("%d%d", &a[i].pi, &a[i].mi);
    }
    sort(a, a + m, cmp);
    int sum = 0;
    for (i = 0; i < m; i++) /// 从价格高到低一样一样塞物品
    {
      if (v > a[i].mi) /// 如果剩余体积够装当前遍历物品
      {
        sum = sum + a[i].pi * a[i].mi; /// 塞进去，计算求和总价值
        v -= a[i].mi;                  /// 体积相应减少
      } else                           /// 若放不下了
      {
        sum = sum + a[i].pi * v; /// 剩下的容积都拿来装目前这个物品
        break;                   /// 并不装其他的了，退出遍历物品循环
      }
    }
    printf("%d\n", sum); /// 输出总和
  }
  return 0;
}
