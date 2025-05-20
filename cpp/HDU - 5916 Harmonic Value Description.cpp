#include <stdio.h> ///先输出k和2*k，使得公约数为k，接下来剩下的数都按互质输出，也就是两数之差为1时互质
int main() /// 使剩下的数公约数为1，这样，根据最小的排列是公约数全为1，在此基础上+k，就是第k小的公约数之和
{
  int t, n, k, i,
      cas =
          0; /// 利用互质来控制不需要变化的数的公约数为1，只凑出多k的公约数即可
  scanf("%d", &t);
  while (t--) {
    cas++;
    scanf("%d%d", &n, &k);
    printf("Case #%d: ", cas);
    printf("%d %d", 2 * k, k);
    for (i = k - 1; i >= 1; i--)
      printf(" %d", i);
    for (i = k + 1; i < 2 * k; i++)
      printf(" %d", i);
    for (i = 2 * k + 1; i <= n; i++)
      printf(" %d", i);
    printf("\n");
  }
}
