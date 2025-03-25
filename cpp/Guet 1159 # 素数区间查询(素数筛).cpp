#include <stdio.h>
#include <string.h>
#define N 1000001
int main() {
  int t, i, x, y, j;
  bool a[N + 2];
  memset(a, true, sizeof(a));
  a[1] = false;
  for (i = 2; i < N; i++) {
    if (a[i]) {
      for (j = i + i; j < N; j += i) {
        a[j] = false;
      }
    }
  }
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &x, &y);
    int flag = 0;
    for (i = x; i <= y; i++) {
      if (a[i])
        flag++;
    }
    printf("%d\n", flag);
  }
}
