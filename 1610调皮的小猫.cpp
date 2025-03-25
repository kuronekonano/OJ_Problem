#include <stdio.h>
#include <string.h>
int main() {
  char a[105];
  int b[130];
  int i, j;
  while (scanf("%s", a) != EOF) {
    memset(b, 1, sizeof(b));
    for (i = 'a'; i <= 'z'; i++) {
      b[i] = 1;
    }
    int n = strlen(a);
    for (i = 0; i < n; i++) {
      if (b[a[i]]) {
        b[a[i]] = 0;
      }
    }
    bool flag = false;
    for (i = 'a'; i <= 'z'; i++) {
      if (b[i] == 1) {
        printf("%c", i);
        flag = true;
      }
    }
    if (flag == true) {
      printf("\n");
    } else {
      printf("0\n");
    }
  }
  return 0;
}
