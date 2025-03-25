#include <stdio.h>
#include <string.h>
struct man {
  char name[25], num[18];
} a[108];
int main() {
  int n, i, j, cas = 1;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      return 0;
    for (i = 0; i < n; i++) {
      scanf("%s %s", a[i].name, a[i].num);
    }
    char tmp[18];
    scanf("%s", tmp);
    printf("Case #%d:\n", cas++);
    for (i = 0; i < n; i++) {
      if (strstr(a[i].num, tmp) != 0)
        printf("%s %s\n", a[i].name, a[i].num);
    }
  }
  return 0;
}
