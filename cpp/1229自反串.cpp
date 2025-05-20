#include <stdio.h>
#include <string.h>
int main() {
  char a[60];
  int n, i, j, flag, xi = 0;
  while (scanf("%s", &a) != EOF) {
    if (strcmp(a, "STOP") == 0) {
      return 0;
    }
    n = strlen(a);
    flag = 0;
    xi++;
    if (n == 1) {
      printf("#%d: YES\n", xi);
    } else {
      for (i = 0, j = n - 1; i < n / 2; i++, j--) // 倒着两个变量回头检阅
      {
        if (a[i] == a[j]) {
          flag++;
        }
      }
      if (flag == n / 2) {
        printf("#%d: YES\n", xi);
      } else {
        printf("#%d: NO\n", xi);
      }
    }
  }
  return 0;
}
