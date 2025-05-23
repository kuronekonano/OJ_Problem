#include <stdio.h>
int main() {
  int m, n;
  while (scanf("%d%d", &m, &n) != EOF) {
    int ans = 0;
    for (int i = 1; i <= m; i++) /// for(int i=0;i<=m;i++)
    {
      for (int j = i; j <= m; j++) {
        int sum = i * i + j * j;
        for (int k = j; k <= m; k++)
          if (k * k == sum)
            ans++;
      }
    } /// ans+(m+1)*(n-1)
    printf(
        "%d\n",
        ans +
            (m + 1) *
                (n -
                 1)); /// 当0=x时，只要y=z，就行,那么就有(m+1)*(n-1)个，因为y可能从0取到m，j可以从2取到n。
  } /// 当0!=x时，那么只要一个勾股定理能构成，只要幂大于2，就一下没解，所以我们把第一种中拿出j=2时，的特殊情况，特殊考虑。
}
/// 费马大定理:当整数n >2时，关于x, y, z的方程 x^n + y^n = z^n 没有正整数解。
/// 因此ans计算的只是当题目中的j=2时有解的情况数量
/// 而x,y,z是指m的值，每个m都要配一个不同的n，因此(m+1)表示从0到m个数，xyz都会取到，并且从小到大，n从2到n，共n-1个数
/// 配对种数(m+1)*(n-1)个，这就只考虑了y,z两个数，因为x固定是0，当x不是0的时候，就是考虑了3个数
/// 考虑3个数的情况，只有j=2有解，用循环来暴力找有几个满足条件，然后，三层循环暴力包括了只考虑y,z时的情况
/// 为避免重复，计算时，(m+1)*(n-2)就去除了j=1和j=2两种情况
/// 当然，如果循环暴力找的起点，从1开始而不从x=0开始，ans+(m+1)*(n-1)也是正确的，不会重复
