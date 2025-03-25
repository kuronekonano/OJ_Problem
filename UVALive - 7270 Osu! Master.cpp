#include <stdio.h>
int main() {
  int i, t, n, shock, flag = 0;
  char a[3];
  while (scanf("%d", &n) != EOF) {
    shock = 0, flag = 1;
    for (i = 1; i <= n; i++) {
      scanf("%s", a);
      if (a[0] != 'S') {
        scanf("%d", &t);
        if (t <= flag)
          shock++;
        flag = t;
      } else
        shock++;
    }
    printf("%d\n", shock);
  }
}
