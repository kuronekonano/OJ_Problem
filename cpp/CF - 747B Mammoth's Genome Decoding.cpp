#include <stdio.h>
int main() {
  int n, i;
  char a[288];
  while (scanf("%d", &n) != EOF) {
    scanf("%s", a);
    int A = 0, G = 0, C = 0, T = 0, sum;
    sum = n / 4;
    for (i = 0; i < n; i++) {
      if (a[i] == 'T')
        T++;
      if (a[i] == 'A')
        A++;
      if (a[i] == 'C')
        C++;
      if (a[i] == 'G')
        G++;
    }
    if (n % 4 != 0 || A > sum || C > sum || G > sum || T > sum) {
      printf("===\n");
      continue;
    }
    A = sum - A;
    T = sum - T;
    G = sum - G;
    C = sum - C;
    for (i = 0; i < n; i++) {
      if (a[i] == '?') {
        if (A) {
          printf("A");
          A--;
          continue;
        }
        if (C) {
          printf("C");
          C--;
          continue;
        }
        if (G) {
          printf("G");
          G--;
          continue;
        }
        if (T) {
          printf("T");
          T--;
          continue;
        }
      } else
        printf("%c", a[i]);
    }
    printf("\n");
  }
}
