#include <stdio.h>
#include <string.h>
int main() {
  long long b, sum;
  char s;
  while (scanf("%lld", &sum) != EOF) {
    while (scanf("%c", &s) &&
           (s == '+' || s == '-')) // ��������ַ�Ϊ+��-ʱ����ѭ��,��������ѭ��
    {
      scanf("%lld", &b); // �൱��һֱ�������+1��+6��֮�����һ����
      if (s == '+')
        sum = sum + b;
      else
        sum = sum - b;
    }
    printf("%lld\n", sum);
  }
  return 0;
}
