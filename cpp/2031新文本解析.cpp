#include <stdio.h>
char a[10000000];
int main() {
  int i;
  while (gets(a) != NULL) {
    for (i = 0; a[i] != '\0'; i++) {
      if (a[i] == 'v') {
        a[i] = '\n';
      }
    }
    printf("%s", a);
  }
  return 0;
}
