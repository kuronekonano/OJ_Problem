#include <stdio.h>
#include <string.h>
int main() {
  char a[1008];
  char b[18] = {' ', '1', 'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'};
  int i;
  while (scanf("%s", &a) != EOF) {
    int n = strlen(a);
    for (i = 0; i < n; i++) {
      if (a[i] == '0') {
        printf("%c", b[a[i] - '0']);
      } else {
        printf("%c", b[a[i] - '0'] + (a[i + 1] - '1'));
        i++;
      }
    }
    printf("\n");
  }
  return 0;
}
