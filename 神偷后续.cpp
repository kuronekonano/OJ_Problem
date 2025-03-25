#include <stdio.h>
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) != EOF) {
    int t, sum = 1;
    if (k == 0) {
      printf("1\n");
      continue;
    }
    int flag = 0;
    for (int i = n;; i--) {
      sum = sum * i;
      flag++;
      if (flag == k) {
        break;
      }
    }
    int num = 1;
    for (int i = k; i >= 1; i--) {
      num = num * i;
    }
    t = sum / num;
    printf("%d\n", t);
  }
  return 0;
}
