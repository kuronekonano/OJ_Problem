#include <stdio.h>
#include <string.h>
int main() {
  char a[10008], b[205];
  int i, n, s, flag = 0, c[100], d[100];
  while (scanf("%s", a) != EOF) {
    memset(c, 0, sizeof(c)); // 记得清空数组
    memset(d, 0, sizeof(d));
    scanf("%s", b);
    s = strlen(a);
    n = strlen(b);
    for (i = 0; i < s; i++) {
      c[a[i] - '0']++;
    }
    for (i = 0; i < n; i++) {
      d[b[i] - '0']++; // 分别存储关键字和字符串的字符出现频率
    }
    int k = 54181;
    for (i = 0; i < 80; i++) // 最大不过74，用‘z’-'0'
    {
      if (d[i] != 0 &&
          c[i] / d[i] <
              k) // 遍历每个用数组存储的字符的序号数量，若相除小于最小值，则更新最小能组成的关键字的数量
      {
        k = c[i] / d[i];
      }
    }
    flag++;
    printf("Case %d: %d\n", flag, k);
  }
  return 0;
}
