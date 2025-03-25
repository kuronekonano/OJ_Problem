#include <stdio.h>
int main() {
  int s, v1, v2, t1, t2;
  while (scanf("%d%d%d%d%d", &s, &v1, &v2, &t1, &t2) != EOF) {
    int a = s * v1 + 2 * t1;
    int b = s * v2 + 2 * t2;
    if (a == b) {
      printf("Friendship\n");
    } else if (a < b) {
      printf("First\n");
    } else {
      printf("Second\n");
    }
  }
}
