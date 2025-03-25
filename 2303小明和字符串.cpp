#include <stdio.h>
#include <string.h>
int main() {
  char a[100];
  int i, n, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", a);
    n = strlen(a);
    char flag;
    for (i = 0; i < n; i++) {
      flag = a[i];
      int sum = 0;
      while (a[i + 1] >= '0' && a[i + 1] <= '9') {
        sum = sum + a[i + 1] - '0';
        i++;
      }
      for (int j = 1; j <= sum + 1; j++) {
        printf("%c", flag);
      }
    }
    printf("\n");
  }
  return 0;
}
