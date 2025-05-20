#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int n, i, j, a[1005];
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);          /// 排序
    int flag = 0, i = n - 1; /// 从最大值开始输出
    while (flag != n) {
      flag++; /// 输出计数器
      printf("%d%c", a[i], flag == n ? '\n' : ' ');
      if (flag == n)
        break;
      flag++;
      printf("%d%c", a[n - i - 1], flag == n ? '\n' : ' ');
      i--;
    }
  }
  return 0;
}
