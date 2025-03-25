#include <stdio.h>
#include <string.h> //marshtomp
int main() {
  char a[205];
  int n, i;
  while (gets(a)) // 一句话中存在空格，所以不能用scanf输入
  {
    n = strlen(a);
    for (i = 0; i < n; i++) {
      if (((a[i] == 'm') ||
           (a[i] ==
            'M')) && // if语句的特殊用法啊，每次遍历字符串第i个,判断是否为i之后的字符串为marshtomp,若成立则直接输出fjxmlhx然后直接跳过8个字符继续遍历
          ((a[i + 1] == 'a') || (a[i + 1] == 'A')) &&
          ((a[i + 2] == 'r') || (a[i + 2] == 'R')) &&
          ((a[i + 3] == 's') || (a[i + 3] == 'S')) &&
          ((a[i + 4] == 'h') || (a[i + 4] == 'H')) &&
          ((a[i + 5] == 't') || (a[i + 5] == 'T')) &&
          ((a[i + 6] == 'o') || (a[i + 6] == 'O')) &&
          ((a[i + 7] == 'm') || (a[i + 7] == 'M')) &&
          ((a[i + 8] == 'p') || (a[i + 8] == 'P'))) {
        printf("fjxmlhx");
        i = i + 8;
      } else // 若字符中无上述字符串，则照常输出原字符，注意此处为单个字符则用%c
        printf("%c", a[i]);
    }
    printf("\n");
  }
  return 0;
}
