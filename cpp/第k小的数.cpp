#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int i, n, k;
  while (scanf("%d%d", &n, &k) != EOF) {
    int a[n + 5];
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n); // 排序方便查找
    printf("%d\n",
           a[k - 1]); // 因为是第K小的数，所以输出应该是数组中的第k-1个数
  }
  return 0;
}
