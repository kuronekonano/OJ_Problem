#include <stdio.h> ///找出最多的连续相同字符数量
#include <string.h>
int main() {
  char a[1005];
  int i;
  while (scanf("%s", a) != EOF) {
    int n = strlen(a);
    int max = 0, sum = 1;
    for (i = 0; i < n; i++) {
      if (a[i] == a[i + 1]) /// 如何和后面那个一样就计数+1
      {
        sum++;
      } else /// 否则初始计数
      {
        sum = 1;
      }
      if (max < sum) /// 判断更改最大计数
      {
        max = sum;
      }
    }
    printf("%d\n", max);
  }
  return 0;
}
