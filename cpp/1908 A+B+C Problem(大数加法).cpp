#include <stdio.h> ///这次是自己写的A+B模拟了……
#include <string.h>
int main() {
  char a[1008], b[1008], c[1008];
  int t, ans[1009];
  scanf("%d", &t);
  while (t--) {
    scanf("%s %s %s", a, b, c);
    int la = strlen(a);
    int lb = strlen(b);
    int lc = strlen(c);
    memset(ans, 0, sizeof(ans)); /// 三数相加，一个一个加，最后进位
    int numa = 0, k = 0;
    la--, lb--, lc--;
    while (la >= 0) {
      ans[numa++] += a[la--] - '0';
    }
    int numb = 0;
    while (lb >= 0) {
      ans[numb++] += b[lb--] - '0';
    }
    int numc = 0;
    while (lc >= 0) {
      ans[numc++] += c[lc--] - '0';
    }
    numa =
        numb > numc ? (numa > numb ? numa : numb) : (numa > numc ? numa : numc);
    for (int i = 0; i < numa; i++) {
      if (i == numa - 1 && ans[i] >= 10)
        continue; /// 注意处理最后一位数
      ans[i + 1] = ans[i + 1] + ans[i] / 10;
      ans[i] = ans[i] % 10;
    }
    printf("%s + %s + %s = ", a, b, c);
    for (int i = numa - 1; i >= 0; i--) {
      printf("%d", ans[i]);
    }
    printf("\n");
  }
}
