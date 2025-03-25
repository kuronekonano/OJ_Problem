#include <math.h>
#include <stdio.h>
#include <string.h>
bool a[1000089];
void inti() {
  memset(
      a, true,
      sizeof(
          a)); /// 利用简单的数学题
               /// 那题的算法，通过乘积的形式标记素数，遍历不超过一遍就可以标记完成
  a[0] = a[1] = false;
  for (int i = 2; i <= 1000000; i++) {
    if (a[i]) {
      for (int j = i + i; j <= 1000000; j += i) {
        a[j] = false;
      }
    }
  }
}
int main() {
  int n, num;
  inti();
  while (scanf("%d", &n) != EOF) {
    num = sqrt(n);
    bool flag = true;
    for (int i = 2; i <= num; i++) /// 找因子也是找出其中一个，再判断另一个即可
    {
      if (a[i] && n % i == 0) {
        int ans = n / i;
        if (a[ans]) {
          printf("Yes\n");
          flag = false;
          break;
        }
      }
    }
    if (flag) {
      printf("No\n");
    }
  }
  return 0;
}
