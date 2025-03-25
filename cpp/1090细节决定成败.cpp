#include <stdio.h>
#include <string.h>
int main() {
  char s[105];
  int i, n, x, y;
  while (scanf("%s", s) != EOF) {
    n = strlen(s);
    x = 0;
    y = 0;
    for (i = 0; i < n; i++) {
      if (s[i] == '0')
        x++;
      else if (s[i] == 'O')
        y++;
    }
    printf("%d %d\n", x, y);
  }
  return 0;
}
