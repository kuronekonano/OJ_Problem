#include <stdio.h>
#include <string.h>
int main() {
  char a[508];
  int i, n;
  while (scanf("%s", a) != EOF) {
    n = strlen(a);
    if (a[0] != 'a') {
      printf("NO\n");
      continue;
    }
    char check = 'a';
    for (i = 0; i < n; i++) {
      if (a[i] <= check)
        continue;
      if (a[i] == check + 1)
        check++;
      else
        break;
    }
    printf("%s\n", i == n ? "YES" : "NO");
  }
}
