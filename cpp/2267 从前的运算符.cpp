#include <stdio.h>
int main() {
  int a[10002], n;
  while (scanf("%d", &n) != EOF) {

    int zero = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (!a[i])
        zero++;
    }
    if (a[n] == 0 && a[n - 1] == 1)
      printf("YES\n");
    else if (a[n] == 0 && a[n - 1] == 0 && (zero >= 3))
      printf("YES\n");
    else
      printf("NO\n");
  }
}
