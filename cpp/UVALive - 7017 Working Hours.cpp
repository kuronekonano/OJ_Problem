#include <stdio.h> ///计算工作时间，模拟读取字符串
#include <stdlib.h>
#include <string.h> ///总时间计算时全部换算成分钟，最后输出时取模和除得到时间
int main() {
  char a[10];
  int time = 0;
  while (scanf("%s", a) != EOF) {
    if (strcmp(a, "$$$") == 0) {
      time = abs(time);
      int ss = time % 60;
      int hh = time / 60;
      printf("%d:%02d\n", hh, ss);
      time = 0;
      continue;
    }
    if (strcmp(a, "###") == 0) {
      time = abs(time);
      int ss = time % 60;
      int hh = time / 60;
      printf("%d:%02d\n", hh, ss);
      return 0;
    }
    int len = strlen(a);
    int h = 0, num = 1, s = 0, i = 1;
    bool flag = false;
    if (a[0] == '-')
      num = -1;
    while (i < len) {
      if (a[i] == '.' || a[i] == ':') {
        i++;
        flag = true;
      }
      if (!flag) {
        while (a[i] >= '0' && a[i] <= '9' && i < len) {
          h = h * 10 + a[i] - '0';
          i++;
        }
      }
      if (flag) {
        while (a[i] >= '0' && a[i] <= '9' && i < len) {
          s = s * 10 + a[i] - '0';
          i++;
        }
      }
    }
    time += num * (h * 60 + s);
  }
}
