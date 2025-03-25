#include <stdio.h>
#include <string.h>
int main() {
  int n, m, i, j;
  while (scanf("%d%d", &n, &m) != EOF) {
    if (m == 0) {
      printf("%d\n", n);
      continue;
    } else {
      long long sum = 0;
      for (i = 1; i <= n; i++) {
        long long jc = i;
        for (int j = 2; j <= m; j++) {
          jc = (jc % (1000000007) * i % (1000000007)) %
               (1000000007); /// 注意m次方是乘i
        }
        sum = sum + (jc % 1000000007);
      }
      printf("%lld\n", sum % 1000000007);
    }
  }
}
