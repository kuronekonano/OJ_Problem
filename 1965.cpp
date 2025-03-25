#include <stdio.h>
#include <string.h>
int main() {
  char a[1005];
  int n, i, j, flag;
  while (scanf("%s", a) != EOF) {
    flag = 0;
    n = strlen(a);
    for (i = 1; i < n; i++) {
      for (j = 0; j < i; j++) {
        if (a[i] == a[j]) {
          flag++;
          continue;
        }
      }
    }
    if (flag != 0) {
      printf("no\n");
    } else if (flag == 0) {
      printf("yes\n");
    }
  }
  return 0;
}
