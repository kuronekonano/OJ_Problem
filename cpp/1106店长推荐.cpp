#include <stdio.h>
#include <string.h>
int main() {
  int i, s, v, a, g, x;
  char n[55];
  while (scanf("%s", &n) != EOF) {
    v = 0;
    a = 0;
    g = 0;
    s = strlen(n);
    for (i = 0; i < s; i++) {
      if (n[i] == 'v') {
        v++;
      }
      if (n[i] == 'a') {
        a++;
      }
      if (n[i] == 'g') {
        g++;
      }
    }
    if (v >= g) // 用于统计v多还是g多，按最少的算,别忘了等于情况
    {
      x = g;
    } else if (v < g) {
      x = v;
    }
    if (a / 3 < x) // 若a/3更少，则以a算，否则以v或g算
    {
      x = a / 3;
    }
    printf("THE NUMBER 1S %d.\n", x);
  }
  return 0;
}
