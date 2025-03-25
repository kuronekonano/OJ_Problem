#include <math.h>  ///设起始值为st，数列长度为d+1(加上起始本身，终值为起始加d)
#include <stdio.h> ///由等差数列求和公式得(起始值+终止值)*(数列长度)/2=等差数列和
int main()         ///(st+(st+d))*(d+1)/2   化简后求st=(2*n-d*d-d)/(2*d+2)
           /// 枚举d值，从0到sqrt(2*n)，因为分子是用2*n来减d*d因此d不会超过sqrt(2*n)
{
  int n;
  while (scanf("%d", &n) != EOF) {
    int up = sqrt(2 * n), ans = 0;
    for (int i = 0; i <= up; i++)
      if ((2 * n - i * i - i) % (2 * i + 2) ==
          0) /// 注意，此时会解出起始值是0或n的情况，这样只有一个数或有人为0的分法不算答案
        if ((2 * n - i * i - i) / (2 * i + 2) != 0 &&
            (2 * n - i * i - i) / (2 * i + 2) != n)
          ans++;
    printf("%d\n", ans);
  }
}
