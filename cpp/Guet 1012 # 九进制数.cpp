#include <stdio.h>
int ten[100], five[100], flag;
bool judge(int x) {
  int n = x, num = 0;
  while (n > 0) {
    ten[num++] = n % 9;
    n /= 9;
  }
  flag = 0;
  while (x > 0) {
    five[flag++] = x % 5;
    x /= 5;
  }
  if (flag == num) {
    for (int j = 0, i = flag - 1; j < flag; j++, i--) {
      if (ten[i] != five[j]) {
        return false;
      }
    }
    return true;
  }
  return false;
}
int main() {
  int i;
  for (i = 10; i <= 1000; i++) {
    if (judge(i)) {
      printf("%d ", i);
      for (int j = flag - 1; j >= 0; j--) {
        printf("%d", ten[j]);
      }
      printf(" ");
      for (int j = flag - 1; j >= 0; j--) {
        printf("%d", five[j]);
      }
      printf("\n");
    }
  }
}
