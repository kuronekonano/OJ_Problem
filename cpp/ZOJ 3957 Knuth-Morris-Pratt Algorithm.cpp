#include <stdio.h>
#include <string.h>
int main() {
  char a[1008];
  int i, n, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", a);
    n = strlen(a);
    int sum = 0;
    for (i = 0; i < n; i++) {
      if (a[i] == 'd' || a[i] == 'c') {
        if (a[i] == 'd' && a[i + 1] == 'o' && a[i + 2] == 'g') {
          sum++;
          i += 2;
        } else if (a[i] == 'c' && a[i + 1] == 'a' && a[i + 2] == 't') {
          sum++;
          i += 2;
        }
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}
