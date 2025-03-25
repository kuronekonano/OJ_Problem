#include <stdio.h>
int main() {
  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    int tmp = k;
    int y = k / (2 * m);
    if (k % (2 * m) != 0)
      y++;
    if (k % (2 * m) != 0)
      k = k % (2 * m);
    else
      k = 2 * m;
    int x = k / 2;
    if (k % 2 != 0)
      x++;
    printf("%d %d %c\n", y, x, tmp % 2 == 0 ? 'R' : 'L');
  }
}
