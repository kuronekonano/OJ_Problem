#include <stdio.h>
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    if (n == 1) {
      printf("-1\n");
      continue;
    }
    printf("%d %d %d\n", n, n + 1, n * (n + 1));
  }
}
/// 给一个n,求2/n=1/x+1/y+1/z中的x y z，解有多个
/// 2/n=1/n+1/n，但是因为x!=y!=z
/// 所以把其中一个1/n又可以分解成[1/(n+1)]+[1/n*(n+1)]
/// 因此最后结果是n  n+1   n*(n+1)
