#include <stdio.h> ///1378的n次方的最后一位数，因此一直拿10取摸取个位乘8就好
int main() /// 用for循环裸乘因为是1e9也会超时，有规律的，8  6  4 2,因此取摸n就好
{
  int n, a[5] = {6, 8, 4, 2, 6};
  while (scanf("%d", &n) != EOF) {
    if (n == 0) {
      printf("1\n");
      continue;
    }
    printf("%d\n", a[n % 4]);
  }
}
