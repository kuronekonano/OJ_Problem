#include <stdio.h>
#include <string.h>
int main() {
  long long b, sum;
  char s;
  while (scanf("%lld", &sum) != EOF) {
    while (scanf("%c", &s) &&
           (s == '+' || s == '-')) // 当输入的字符为+或-时继续循环,否则跳出循环
    {
      scanf("%lld", &b); // 相当于一直输入的是+1，+6等之类的下一个数
      if (s == '+')
        sum = sum + b;
      else
        sum = sum - b;
    }
    printf("%lld\n", sum);
  }
  return 0;
}
