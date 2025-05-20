#include <stdio.h> ///水题，好像用了背单词那题的字符比较方法
#include <string.h>
int main() {
  int t, n, m, i, j;
  char a[55][55];
  while (scanf("%d", &t) != EOF) {
    char key[55];
    while (t--) {
      scanf("%d%d", &m, &n);
      scanf("%s", key);
      for (i = 1; i <= m; i++) {
        scanf("%s", a[i]);
      }
      int flag = 0, len;
      len = strlen(key);
      for (i = 1; i <= m; i++) /// 有m个字符串，逐个串比较
      {
        int len1 = strlen(a[i]), k = 0;
        for (j = 0; j < len1; j++) /// 逐个串和关键字比较
        {
          if (a[i][j] ==
              key[k]) /// 只要遇到和关键字对应字符一样，那么字符往后移动指针，找下一个相同的字符
          {
            k++;
          }
        }
        if (k ==
            len) /// 如果字符加到了关键字的长度，那么说明有匹配的关键字，计数器加一
        {
          flag++;
        }
      }
      if (flag == n) /// 比较部分
      {
        printf("Orz!\n");
      } else if (flag < n) {
        printf("Vagaa V5!\n");
      } else {
        printf("EMule V5!\n");
      }
    }
    printf("\n");
  }
  return 0;
}
