#include <stdio.h>
#include <string.h>
int main() {
  char a[105];
  int n, i;
  while (scanf("%s", a) != EOF) {
    n = strlen(a);
    int flag = 0;
    int v = 0;
    for (i = 0; i < n; i++) {
      if (a[i] == a[i + 1]) {
        v++;
        if (v >= 5) {
          v = 0;
          flag++;
        }
      } else if (a[i] != a[i + 1]) {
        flag++;
        v = 0;
      }
    }
    printf("%d\n", flag);
  }
  return 0;
}
