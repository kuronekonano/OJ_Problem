#include <stdio.h>
int main() {
  int t, a, b, n, i;
  scanf("%d", &t);
  while (t--) {
    int flag = 0;
    scanf("%d%d%d", &n, &a, &b);
    for (i = 0; i < n; i++) {
      if (i >= a &&
          (n - i - 1) <=
              b) // 记住减掉其本身的人数，i为前面的人数，n-i-1为后面的人数
      {
        flag++;
      }
    }
    printf("%d\n", flag);
  }
  return 0;
}
