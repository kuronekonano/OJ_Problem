#include <stdio.h>
int main() {
  int i, t, n, a[35] = {0, 0, 0, 1, 1, 2,  3,  3,  4,  5,
                        6, 7, 7, 8, 9, 10, 11, 12, 13, 14}; // 新生赛后的训练赛
  scanf("%d", &t);
  int flag = 0;
  while (t--) {
    scanf("%d", &n);
    printf("Case #%d: %d\n", ++flag, a[n - 1]);
  }
  return 0;
}
