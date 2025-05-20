#include <stdio.h>
#include <string.h>
int main() {
  int num[109], i;
  char str[109];
  while (scanf("%s", str) != EOF) {
    int n = strlen(str); /// 大数字符串转换
    if (str[0] == '0') {
      return 0;
    }
    for (i = 0; i < n; i++) {
      num[i] = str[i] - '0';
    }
    long long number = 0;
    for (i = 0; i < n; i++) {
      number = (number * 10 + num[i]) % 33; /// 同余模定理
    }
    if (number == 0) {
      printf("OK\n");
    } else {
      printf("Orz\n");
    }
  }
  return 0;
}
