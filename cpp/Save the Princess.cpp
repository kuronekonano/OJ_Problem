#include <stdio.h>
int main() {
  int t, n, k;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    if (n % 2 == 0)
      printf("LYF\n");
    else
      printf("BH\n");
  }
  return 0;
}
