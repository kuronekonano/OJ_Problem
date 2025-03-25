#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int i, n, a[100005], j;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n); // 排序，用sort的时候记住从零开始
    int flag;
    bool ent = false;
    for (i = 0; i < n; i++) {
      flag = 1;
      while (a[i] ==
             a[i + 1]) // 若成立多个数字相同的条件，则遍历的光标i自动向后自增
      {
        flag++;
        i++;
      }
      if (flag % 2 != 0 && ent == false) {
        printf("%d", a[i]);
        ent = true;
      } else if (flag % 2 != 0 && ent == true) {
        printf(" %d", a[i]);
      }
    }
    printf("\n");
  }
  return 0;
}
