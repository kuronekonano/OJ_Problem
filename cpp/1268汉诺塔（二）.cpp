#include <stdio.h>
long long tower(int a) /// 汉诺塔的数在63内可用long long存下，单独取出运算
{
  long long flag = 1;
  for (int i = 1; i < a; i++) {
    flag = flag * 2 + 1; /// 汉诺塔递推公式
  }
  return flag; /// 返回值是long long的
}
int main() {
  int i, n;
  while (scanf("%d", &n) != EOF) {
    long long hano = tower(n); /// 由此依次求模，再除求年份天数时分秒
    int second = hano % 60;
    hano = hano / 60;
    int minute = hano % 60;
    hano = hano / 60;
    int hour = hano % 24;
    hano = hano / 24;
    int day = hano % 365;
    hano = hano / 365;
    printf("%lld years %d days %d hours %d minute %d seconds\n", hano, day,
           hour, minute, second);
  }
  return 0;
}
