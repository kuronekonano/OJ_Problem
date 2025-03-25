#include <stdio.h>
#include <string.h>
int main() {
  char a[10000];
  int i, t;
  scanf("%d", &t);
  getchar();
  while (t--) {
    gets(a);
    int n = strlen(a);
    int sum = 0;
    if (n == 0) {
      printf("0\n");
      continue;
    }
    for (i = 0; i <= n; i++) {
      if (a[i] == ' ' && a[i + 1] != ' ' && a[i + 1] != '\0') {
        sum++;
      }
    }
    if (a[0] == ' ') {
      printf("%d\n", sum);
    } else {
      printf("%d\n", sum + 1);
    }
  }
  return 0;
}
