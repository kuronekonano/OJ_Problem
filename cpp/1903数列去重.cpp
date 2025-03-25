#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int a[10005]; // 定义一个存储所有数据的数组
  int i, n, flag, t;
  scanf("%d", &t); // 输入t组数据
  while (t--) {
    scanf("%d", &n);        // 输入n个数字
    for (i = 0; i < n; i++) // 从0开始输入，便于sort函数排序
    {
      scanf("%d", &a[i]); // 输入每个数字
    }
    sort(a, a + n); // 给数字排序
    flag = 1;
    for (i = 1; i < n; i++) // 从第2个数开始前面的（左边）的数比
    {
      if (a[i] != a[i - 1]) // 若发现相同的数，若和上一个数相比相同
      {
        flag++; // 计数器自增
      }
    }
    printf("%d %d ", flag, a[0]); // 输出有几个重复的数，以及原数组中第一个数
    for (i = 1; i < n; i++) {
      if (a[i] !=
          a[i -
            1]) // 同理是比较上一个数,因此上一步0个数是未比较的，所以得先输出，况且第一个数和第0个数已经比较，若重复则不输出第一个，之后的也是与前面的数相比较
      {
        printf("%d ", a[i]); // 再次遍历数组找相同数字，若不同的则输出
      }
    }
    printf("\n");
  }
  return 0;
}
