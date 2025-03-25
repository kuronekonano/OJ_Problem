#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char a[25];
  while (scanf("%s", a) != EOF) {
    long n =
        strtol(a, NULL, 12); /// 转换 12进制到十进制，头文件特殊，直接取摸即可
    printf(n % 11 == 0 ? "YES\n" : "NO\n");
  }
  return 0;
}
