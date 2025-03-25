#include <stdio.h>
#include <string.h>
int main() {
  char a[100008];
  int i, n;
  while (scanf("%s", a) != EOF) {
    n = strlen(a);
    bool flag = false;
    for (i = 0; i < n; i++) {
      if (a[i] == '0' && !flag) {
        flag = true;
        continue;
      }
      if (i == n - 1 && !flag)
        continue;
      printf("%c", a[i]);
    }
    printf("\n");
  }
}
