#include <algorithm>
#include <stdio.h>
using namespace std;
struct path /// 记录交换路径的结构体
{
  int q, p;
} c[10006];
int main() {
  int t, n, a[10005], b[10008], i,
      j; /// 两个一模一样的数组，一个装原版输入顺序，一个装排序好的顺序
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) /// 完全一样的输入
    {
      scanf("%d", &a[i]);
      b[i] = a[i];
    }
    sort(b, b + n);         /// 排序其中一个数组
    int flag = 0;           /// 交换步骤计数器
    for (i = 0; i < n; i++) /// 处理循环
    {
      if (a[i] != b[i]) /// 将对应位置的数字与排序好的相比，不同说明需要交换
      {
        for (
            j = i + 1; j < n;
            j++) /// 若不同，从当前原版数组的下一个开始对比，查找a这之后的数字中，有没有和b那个排序好的数组中数字相同的
        {
          if (a[j] ==
              b[i]) /// 有相同的就交换，在a数组中交换，其实也是一个排序的过程
          {
            int temp = a[i]; /// 三变量交换
            a[i] = a[j];
            a[j] = temp;
            c[flag].q = i; /// 路径记录
            c[flag].p = j;
            flag++; /// 路径计数
            break;  /// 当找到了那个数，后面的就不用找了
          }
        }
      }
    }
    printf("%d\n", flag); /// 输出路径数和具体步骤
    for (i = 0; i < flag; i++) {
      printf("%d %d\n", c[i].q + 1,
             c[i].p + 1); /// 因为是从0开始计数的，记得最终结果+1
    }
  }
  return 0;
}
/*定义 结构体存储 交换操作的 i j .
构造两个相同的数组 a[n]，b[n]   先将 b[n]   sort 排序 然后判断 若 a  b  不相等
则找到与b  相等的a[j],  将a  a[j]  交换 同时将  i j 存入结构体内。 */
