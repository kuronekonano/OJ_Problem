#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int n, t, a[100005];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    int b = a[0];          /// b记录当前取得的最大值
    int big = a[0] - a[1]; /// big记录当前最大差值
    for (
        int i = 1; i < n;
        i++) /// 从第二个数开始遍历，一直找最大的数，但是是从已经扫过的值中找，所以不会出现后面的数减前面的数的情况
    {
      big = max(
          big,
          b - a[i]); /// 利用当前扫过的最大值减去正在扫的后面那个值，这样来取最值
      b = max(b, a[i]); /// 记录的是扫过的所有数中的最大值
    }
    printf("%d\n", big);
  }
  return 0;
}
