#include <stdio.h> ///从个位到第k位的数字如果都相同输出-1，取摸，然后一一比较就好
int main() {
  long long a, b, k;
  while (scanf("%lld%lld", &a, &b) != EOF) {
    if (a == 0 && b == 0)
      return 0;
    scanf("%lld", &k);
    int tma, tmb;
    bool flag = false;
    long long sum = a + b;
    tma = a % 10;
    tmb = b % 10;
    while (k--) {
      if (tma != tmb) {
        flag = true;
        break;
      }
      a /= 10;
      b /= 10;
      tma = a % 10;
      tmb = b % 10;
    }
    if (flag)
      printf("%lld\n", sum);
    else
      printf("-1\n");
  }
  return 0;
}
