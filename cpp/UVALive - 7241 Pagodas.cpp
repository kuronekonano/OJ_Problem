#include <stdio.h> ///因为是两数j加减k得到的值，这样会得到新的值以供得出更多的值，这样会得到一个等差数列，这个等差数列的公差即是初始两数的最大公约数
int gcd(
    int a,
    int b) /// 算出最大公约数，如果为1，(两数互质)，则是公差为1的可建塔序列，否则建塔数是n/公差，算出可以建塔的数量再判断奇偶即可得知谁赢
{
  int c;
  while (b != 0) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}
int main() {
  int t, i, n, a, b, cas = 0;
  scanf("%d", &t);
  while (t--) {
    cas++;
    scanf("%d%d%d", &n, &a, &b);
    int c = gcd(a, b);
    if ((n / c) % 2 == 0)
      printf("Case #%d: Iaka\n", cas);
    else {
      printf("Case #%d: Yuwgna\n", cas);
    }
  }
}
