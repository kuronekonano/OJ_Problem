#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int i, j, t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int a
        [n + 5]
        [2 *
         n]; // 防止数组越界，注意j的值是i的值的两倍减一，因此一定要开大开大开大
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= 2 * i - 1; j++) // 二维数组输入数据
      {
        scanf("%d", &a[i][j]);
      }
    }
    for (
        i = n - 1; i >= 1;
        i--) // 这里，从三角形的倒数第二行开始检阅，逐行向上，为的是从倒数第二行向下找最大值求和，然后赋值，再退回上一行，向下找最大值，因为原行数的值
    {
      for (
          j = 1; j <= 2 * i - 1;
          j++) // 已经被求和值覆盖，因此可以直接找最大的求和值并向上赋值，直到求和至三角形最顶端的数字
      {
        a[i][j] = a[i][j] +
                  max(max(a[i + 1][j], a[i + 1][j + 1]),
                      a[i + 1]
                       [j + 2]); // 两两求最大值，以便求三个数中的最大值，并求和
      }
    }
    printf("%d\n", a[1][1]); // 输出三角形顶端数字
  }
  return 0;
}
