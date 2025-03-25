#include <stdio.h>
#include <string.h>
int main() {
  char a[1008], b[1008];
  int i;
  while (gets(a)) {
    int n = strlen(a);
    int flag = 0;
    for (i = 0; i < n; i++) {
      if (a[i] != ' ') {
        b[flag++] = a[i];
      } else /// 再次遇到空格的时候，因为flag被初始化为0了，且遇到单词字母前不会再增加
      {
        for (int j = flag - 1; j >= 0; j--) {
          printf("%c", b[j]);
        }
        flag = 0;
        printf("%c", a[i]); /// 把空格输出来
      }
    }
    for (i = flag - 1; i >= 0; i--) /// 最后一个单词
    {
      printf("%c", b[i]);
    }
    printf("\n");
  }
  return 0;
}
