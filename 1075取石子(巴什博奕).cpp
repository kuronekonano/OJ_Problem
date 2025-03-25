#include <stdio.h>
int main() {
  int m, n;
  while (scanf("%d%d", &n, &m) != EOF) {
    if (n % (m + 1) !=
        0) // 巴什博奕（Bash Game）：
           // 显然，如果n=m+1，那么由于一次最多只能取m个，所以，无论先取者拿走多少个后取者都能够一次拿走剩余的物品，后者取胜。因此我们发现了如何取胜的法则
    {
      printf("JiaozhuV5!\n"); // 要给对方留下m+1的倍数，此时的取法必胜
    } else
      printf("LeyniV5!\n");
  }
  return 0;
}
