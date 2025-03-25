#include <stdio.h> ///找B的个数，并且是分段的连续的B
#include <string.h>
int main() {
  int n, i, sums[108];
  char a[108];
  while (scanf("%d", &n) != EOF) {
    scanf("%s", a);
    int sum = 0, j = 0;
    for (i = 0; i < n; i++) {
      if (a[i] == 'B') {
        while (a[i] == 'B') {
          sum++;
          i++;
        }
        sums[j++] = sum;
        sum = 0;
      }
    }
    printf("%d\n", j);
    for (i = 0; i < j; i++) {
      printf("%d%c", sums[i], i == j - 1 ? '\n' : ' ');
    }
  }
  return 0;
}
